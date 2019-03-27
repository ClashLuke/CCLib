#define PROGRAM_FILE "squash.cl"
#define KERNEL_FUNC "squash"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#ifdef MAC
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

void squash_2(uint8_t* data, uint8_t* scratchpad, uint8_t* out){
	uint8_t   shift[4]   = {0};
	uint64_t  key[2][2]  = {0};
	uint64_t  divr[2]    = {0};
	uint64_t  crc_64[4]  = {0};
	uint32_t* crc_32     = (uint32_t*)crc_64;
	uint16_t* crc_16     = (uint16_t*)crc_64;
	uint32_t* data_32    = (uint32_t*)data;
	uint64_t* data_64    = (uint64_t*)data;
	uint16_t* out_16     = (uint16_t*)out;
	uint64_t* out_64     = (uint64_t*)out;
	crc_32[0] = crc32(data_32[0]);
	crc_32[1] = crc32(data_32[1]);
	crc_32[2] = crc32(data_32[2]);
	crc_32[3] = crc32(data_32[3]);
	crc_32[4] = ((uint32_t*)&scratchpad[crc_16[0]])[0];
	crc_32[5] = ((uint32_t*)&scratchpad[crc_16[2]])[0];
	crc_32[6] = ((uint32_t*)&scratchpad[crc_16[4]])[0];
	crc_32[7] = ((uint32_t*)&scratchpad[crc_16[6]])[0];
	crc_32[0] = reverse(crc_32[0]);
	crc_32[1] = reverse(crc_32[1]);
	crc_32[6] = reverse(crc_32[6]);
	crc_32[7] = reverse(crc_32[7]);
	crc_64[1] = swap(crc_64[1]);
	crc_64[2] = swap(crc_64[2]);
	divr[0] = (data_64[2] + crc_64[2]) ^ (data_64[2] / crc_64[0]);
	divr[1] = (data_64[3] + crc_64[3]) ^ (data_64[3] / crc_64[1]);
	out_64[0] = crc_64[0]^divr[0]; out_64[1] = crc_64[1]^divr[0];
	out_64[2] = crc_64[2]^divr[1]; out_64[3] = crc_64[3]^divr[1];
	shift[0] = out_16[15]&0x3f;
	shift[2] = out_16[ 0]&0x3f;
	shift[1] = 64-shift[0];
	shift[3] = 64-shift[2];
	key[1][0] = (out_64[0]>>shift[0]) | (out_64[0]<<(shift[1]));
	key[1][1] = (out_64[1]>>shift[0]) | (out_64[1]<<(shift[1]));
	key[0][0] = (out_64[2]<<shift[2]) | (out_64[2]>>(shift[3]));
	key[0][1] = (out_64[3]<<shift[2]) | (out_64[3]>>(shift[3]));
	aes(out     , (uint8_t*)key[0]);
	aes(&out[16], (uint8_t*)key[1]);
	return;
}
 
 
int main( int argc, char* argv[] )
{
	// Initialise host variables
	uint64_t* cache_64;
	uint64_t* dataset_64;
	uint8_t*  dataset;
	uint64_t* blake_r;
	uint64_t* blake_r_temp;
	uint64_t* result;
	uint8_t*  cache   = (uint8_t*)cache_64;
	uint8_t*  dataset = (uint8_t*)dataset_64;

	// Initialise variables for OpenCL
	size_t localSize  = 64;
	size_t globalSize = ceil(134217728/(float)localSize)*localSize;

	cl_mem cl_cache;
	cl_mem cl_dataset;
	cl_mem cl_blake_r;
	cl_mem cl_result;
 
	cl_platform_id cpPlatform;
	cl_device_id device_id;
	cl_context context;
	cl_command_queue queue;	
	cl_program program;
	cl_kernel kernel;

	cl_int err;
 
	// Allocate memory on host
	cache_64     = (uint64_t*)calloc(8388608,8);
	dataset_64   = (uint64_t*)calloc(536870912,8);
	blake_r      = (uint64_t*)calloc(16384,8);
	blake_r_temp = (uint64_t*)calloc(16384,8);
	result       = (uint64_t*)calloc(16384,8);
	if(!cache_64 || !dataset_64 || !blake_r || !blake_r_temp || !result) return(1);

	// Initialise cache on host
	uint64_t* temp_cache = (uint64_t*)calloc(4,8);
	uint64_t* index     = (uint64_t*)calloc(4,8);
	for(uint32_t i=0;i<2097152;i++) squash_2((uint8_t*)&cache_64[i*4], scratchpad, (uint8_t*)&cache_64[(i+1)*4]);
	for(uint8_t j=0;j<4;j++){
		for(uint32_t i=0;i<2097152;i++){
			index[0] = cache_64[i*4]&2097151;
			index[1] = i; 
			for(uint8_t k=0;k<4;k++)
				temp_cache[k] = ((uint64_t*)&cache[index[0]+k])[0]^((uint64_t*)&cache[index[1]+k])[0];
			squash_2((uint8_t*)temp_cache, scratchpad, &cache[i*32]);
		}
	}
	free(temp_cache);
	free(index);

	// Calculate dataset (via OpenCL device)
	err = clGetPlatformIDs(1, &cpPlatform, NULL);
	err = clGetDeviceIDs(cpPlatform, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
	context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
	queue = clCreateCommandQueue(context, device_id, 0, &err);
	program = clCreateProgramWithSource(context, 1, (const char**)&kernelSource, NULL, &err);
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	kernel = clCreateKernel(program, "calc_item", &err);
	cl_cache      = clCreateBuffer(context, CL_MEM_READ_ONLY, 67108864, NULL, NULL);
	cl_dataset    = clCreateBuffer(context, CL_MEM_READ_WRITE, 4294967296, NULL, NULL);
	err = clEnqueueWriteBuffer(queue, cl_cache, CL_TRUE, 0, 67108864, cache_64, 0, NULL, NULL);
	err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &cl_cache);
	err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &cl_dataset);
	err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);
	clFinish(queue);
	free(cache_64);
	clReleaseMemObject(cl_cache);
	clReleaseKernel(kernel);

	/* Calculate squash_pow results, in 4096-hash bulks
	 * Exit once a result fitting difficulty was found.
	 * Blake2b hashes are preprocessed within this loop. 
	 */
	while(1){
		kernel = clCreateKernel(program, "squash_pow", &err);
		cl_blake_r   = clCreateBuffer(context, CL_MEM_READ_ONLY,  131072, NULL, NULL);
		cl_result    = clCreateBuffer(context, CL_MEM_WRITE_ONLY, 131072, NULL, NULL);
		err = clEnqueueWriteBuffer(queue, cl_blake_r, CL_TRUE, 0, 131072, blake_r, 0, NULL, NULL);
		err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &cl_dataset);
		err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &cl_blake_r);
		err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &cl_result);
		globalSize = ceil(4096/(float)localSize)*localSize;
		err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);
		/* Calculate 4096 blake2b hashes */
		clFinish(queue);
		clEnqueueReadBuffer(queue, cl_result, CL_TRUE, 0, 131072, result, 0, NULL, NULL );
		/* Analyse hashes (if they meet the diff) 
		   if good hash, break.		
		*/
	}

	// Release Resources
	clReleaseMemObject(cl_dataset);
	clReleaseMemObject(cl_blake_r);
	clReleaseMemObject(cl_result);
	clReleaseProgram(program);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);
	free(dataset_64);
	free(blake_r);
	free(blake_r_temp);
	free(result);
 
	return 0;
}
