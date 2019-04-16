// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

#include "aes.h"
#include "clbuild.h"

#ifdef MAC
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

uint32_t crc32c_table[256] = {
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
	0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
	0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
	0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
	0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
	0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
	0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
	0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
	0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
	0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
	0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
	0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
	0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
	0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
	0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
	0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
	0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
	0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
	0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
	0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
	0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
	0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
	0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
	0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
	0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
	0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
	0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
	0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
	0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
	0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
	0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
	0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
	0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
	0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
	0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
	0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
	0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
	0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
	0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
	0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
	0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

uint32_t crc32(uint32_t msg) {
	uint32_t crc = 0xFFFFFFFF;
#if defined(__aarch64__) && defined(__ARM_FEATURE_CRC32)
	__asm__("crc32w %w0,%w0,%w1\n":"+r"(crc):"r"(msg));
#else
	crc=crc^msg;
	crc=crc32c_table[crc&0xff]^(crc>>8);
	crc=crc32c_table[crc&0xff]^(crc>>8);
	crc=crc32c_table[crc&0xff]^(crc>>8);
	crc=crc32c_table[crc&0xff]^(crc>>8);
#endif
	return crc^0xFFFFFFFF;
}

uint32_t reverse(uint32_t x){
#if defined(__aarch64__) && !defined(__x86_64__)
	  __asm__("rbit %0":"+r"(v));
#else
	x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
	x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
	x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
	x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
	x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
#endif
	return x;
}

// reverse all bytes in the word _v_
uint64_t swap(uint64_t v) {
#if defined(__x86_64__)
	__asm__("bswap %0":"+r"(v));
#elif defined(__aarch64__)
	__asm__("rev %0,%0\n":"+r"(v));
#else
	v=((v&0xff00ff00ff00ff00ULL)>>8)|((v&0x00ff00ff00ff00ffULL)<<8);
	v=((v&0xffff0000ffff0000ULL)>>16)|((v&0x0000ffff0000ffffULL)<<16);
	v=(v>>32)|(v<<32);
#endif
	return v;
}

void squash_0(uint8_t* data, uint8_t* out){
	uint8_t   shift[4]   = {0};
	uint64_t  key[2][2]  = {0};
	uint64_t  crc_64[4]  = {0};
	uint32_t* crc_32     = (uint32_t*)crc_64;
	uint32_t* data_32    = (uint32_t*)data;
	uint64_t* data_64    = (uint64_t*)data;
	uint16_t* out_16     = (uint16_t*)out;
	uint64_t* out_64     = (uint64_t*)out;
	crc_32[0] = crc32(data_32[0]);
	crc_32[1] = crc32(data_32[1]);
	crc_32[2] = crc32(data_32[2]);
	crc_32[3] = crc32(data_32[3]);
	crc_64[2] = (data_64[2] + crc_64[0]) ^ (data_64[2] / crc_64[0]);
	crc_64[3] = (data_64[3] + crc_64[1]) ^ (data_64[3] / crc_64[1]);
	out_64[0] = crc_64[0]; out_64[1] = crc_64[1];
	out_64[2] = crc_64[2]; out_64[3] = crc_64[3];
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
 
 
int squash_opencl(uint32_t block_number)
{
	// Initialise host variables
	uint64_t* seed_64;
	uint64_t* scratchpad_64;
	uint64_t* cache_64;
	uint64_t* dataset_64;
	uint64_t* blake_r;
	uint64_t* blake_r_temp;
	uint64_t* result;

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
	seed_64       = (uint64_t*)calloc(4,8);
	scratchpad_64 = (uint64_t*)calloc(8192,8);
	cache_64      = (uint64_t*)calloc(8388608,8);
	dataset_64    = (uint64_t*)calloc(536870912,8);
	blake_r       = (uint64_t*)calloc(16384,8);
	blake_r_temp  = (uint64_t*)calloc(16384,8);
	result        = (uint64_t*)calloc(16384,8);
	if(!seed_64 || !scratchpad_64 || !cache_64 || !dataset_64 || !blake_r || !blake_r_temp || !result) return(1);

	// Get byte-pointers of 8-byte pointers
	uint8_t*  seed       = (uint8_t*)seed_64;
	uint8_t*  scratchpad = (uint8_t*)scratchpad_64;
	uint8_t*  cache      = (uint8_t*)cache_64;
	uint8_t*  dataset    = (uint8_t*)dataset_64;

	// Calculate seed for scratchpad
	for(uint64_t i=0;i<block_number/60;i++) squash_0(seed, seed);

	// Calculate scratchpad
	squash_0(seed, scratchpad);
	for(uint32_t i=32; i<65536;i+=32) squash_0(&scratchpad[i-32], &scratchpad[i]);
	free(seed);

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
	free(scratchpad);

	// Calculate dataset (via OpenCL device)
	err        = clGetPlatformIDs(1, &cpPlatform, NULL);
	err        = clGetDeviceIDs(cpPlatform, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
	context    = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
	queue      = clCreateCommandQueueWithProperties(context, device_id, 0, &err);
	program    = build_program(context, device_id, "squash.cl");
	kernel     = clCreateKernel(program, "calc_item", &err);
	cl_cache   = clCreateBuffer(context, CL_MEM_READ_ONLY, 67108864, NULL, NULL);
	cl_dataset = clCreateBuffer(context, CL_MEM_READ_WRITE, 4294967296, NULL, NULL);
	err        = clEnqueueWriteBuffer(queue, cl_cache, CL_TRUE, 0, 67108864, cache_64, 0, NULL, NULL);
	err        = clSetKernelArg(kernel, 0, sizeof(cl_mem), &cl_cache);
	err       |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &cl_dataset);
	err        = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);
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
 
	return 2;
}

int main(){
	int result = 0;
	result = squash_opencl(10);
	printf("%d\n",result);
	return 0;
}
