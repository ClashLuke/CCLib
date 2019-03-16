from utils import squash_init, keccak_init, padr, plot_data, show_help, parse_args, result_path, init

def compare(hashes, iterations):
	lenght = len(hashes[0])
	differences = []
	curr_diff = ""
	for i in range(iterations-1):
		curr_diff = ""
		if(len(hashes[i])!=64):
			continue
		for j in range(lenght):
			curr = hex((int('0'+hashes[i][j],16) - int('0'+hashes[i+1][j],16))&0xF)[2:]
			curr_diff = curr_diff + curr
		differences.append(curr_diff)
	return(differences)

def bit_histogram(hashes, plot = False, out = "results"):
	values = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	lenght = len(hashes[0])
	for hash in hashes:
		if hash == '':
			continue
		for i in range(lenght):
			values[i] = values[i] + int(hash[i],16) 
	values = [v/len(hashes) for v in values]

	return [values, [i for i in range(len(values))]]

def bucket_histogram(hashes, buckets, plot = False, out = "results"):
	values = []
	for i in range(buckets+1):
		values.append(0)
	for hash in hashes:
		if hash == '':
			continue
		values[int(hash,16)&buckets] += 1
	return [values, [i for i in range(len(values))]]

def test_collisions(hashes, write = False, out = "results"):
	collisions = 0
	l = len(hashes)
	
	for i in range(l):
		try:
			if hashes[i] == hashes[i+1]:
				collisions = collisions + 1
		except:
			break
	if write:
		f = open(result_path("testresults.txt",out),"a")
		f.write("Found a total number of {} Collisions in {} hashes.\n".format(collisions,l))
		f.close()
	else:
		print("Found a total number of {} Collisions in {} hashes.\n".format(collisions,l))
	return


def test_hash_time(write = False, time = False, iterations = 2**16, out = "results"):
	if time:
		data = squash_init(time)
		if write:
			f = open(result_path("testresults.txt",out),"a")
			f.write("[Squash] Calculation of {} hashes took {}s\n".format(1<<32, int(10*data[0])/10))
			f.write("[Squash] Calculation per hash took {}ns\n\n".format(int(1000000000*data[1])))
			f.close()
		else:
			print("[Squash] Calculation of {} hashes took {}s".format(1<<28, data[0]))
			print("[Squash] Calculation per hash took {}ns\n".format(int(1000000000*data[1])))
	return(squash_init(False, iterations))

def test_keccak_time(write = False, time = False, iterations = 2**16, out = "results"):
	if time:
		data = keccak_init(time, iterations<<4)
		if write:
			f = open(result_path("testresults.txt",out),"a")
			f.write("[Keccak] Calculation of {} hashes took {}s\n".format(iterations<<4, int(10*data[0])/10))
			f.write("[Keccak] Calculation per hash took {}ns\n\n".format(int(1000000000*data[1])))
			f.close()
		else:
			print("[Keccak] Calculation of {} hashes took {}s".format(iterations<<4, data[0]))
			print("[Keccak] Calculation per hash took {}ns\n".format(int(1000000000*data[1])))
	return(keccak_init(False, iterations))

if __name__ == "__main__":
	keccak, squash, iterations, time, collisions, bit, bucket, write, plot, out = init()

	open(result_path("testresults.txt",out),"w").write('')
	if keccak:
		hashes = test_keccak_time(write=write, time=time, iterations=iterations, out=out)
		if collisions:
			test_collisions(hashes, write=write, out=out)
		if bucket:
			plot_data(data=bucket_histogram(hashes,0xFFFF),name="keccak_bucket_histogram", plot=plot, out=out)
		if bit:
			plot_data(data=bit_histogram(hashes),name="keccak_bit_histogram", plot=plot, out=out)
	if squash:
		hashes = test_hash_time(write=write, time=time, iterations=iterations, out=out)
		if collisions:
			test_collisions(hashes, write=write, out=out)
		if bucket:
			plot_data(data=bucket_histogram(hashes,0xFFFF),name="squash_bucket_histogram", plot=plot, out=out)
		if bit:
			plot_data(data=bit_histogram(hashes),name="squash_bit_histogram", plot=plot, out=out)
