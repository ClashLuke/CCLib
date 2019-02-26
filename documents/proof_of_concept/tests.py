from utils import squash_init, keccak_init, padr, plot_data, show_help, parse_args, result_path, init


def count(hashes):
	values = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	hash = ''.join(hashes)
	for h in hash:
		foo = int(h,16)
		values[foo] = values[foo] + 1
	return values

def compare(hashes, iterations):
	lenght = len(hashes[0])
	differences = []
	curr_diff = ""
	for i in range(iterations-1):
		curr_diff = ""
		for j in range(lenght):
			curr = hex((int('0'+hashes[i][j],16) - int('0'+hashes[i+1][j],16))&0xF)[2:]
			curr_diff = curr_diff + curr
		differences.append(curr_diff)
	return(differences)
	
def evaluate_probability(hashes, write = False, out = "results"):
	counts = count(hashes)
	total = sum(counts)
	counts = [int(100*c/total) for c in counts]
	if write:
		f = open(result_path("testresults.txt",out),"a")
		for i in range(len(counts)):
			f.write("Value {}has a total share of {}%\n".format(padr(i,3),counts[i]))
		f.write('\n')
		f.close()
	else:
		for i in range(len(counts)):
			print("Value {}has a total share of {}%".format(padr(i,3),counts[i]))
		print('\n')

def evaluate_similarity(hashes, iterations, write = False, out = "results"):
	differences = compare(hashes,iterations)
	if write:
		f = open(result_path("testresults.txt",out),"a")
		f.write("\t\t\t\tHash\t\t\t\t\t\t\t\t\tDifference\n")
		for i in range(1,iterations+1):
			try:
				f.write(str(hashes[i]) + '\t' + str(differences[i-1])+'\n')
			except:
				break
		f.write('\n')
		f.close()
	else:
		print("\t\t\t\tHash\t\t\t\t\t\t\t\t\tDifference")
		for i in range(1,iterations+1):
			try:
				print(hashes[i], differences[i-1],sep='\t')
			except:
				break
		print('\n')

def bit_histogram(hashes, plot = False, out = "results"):
	values = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	lenght = len(hashes[0])
	for hash in hashes:
		for i in range(lenght):
			values[i] = values[i] + int(hash[i],16) 
	values = [v/len(hashes) for v in values]

	return [values, [i for i in range(len(values))]]

def bucket_histogram(hashes, buckets, plot = False, out = "results"):
	values = []
	for i in range(buckets+1):
		values.append(0)
	for hash in hashes:
		values[int(hash,16)&buckets] += 1
	return [values, [i for i in range(len(values))]]

def test_collisions(hashes, write = False, out = "results"):
	collisions = 0
	_hashes = hashes[:]
	for i in range(len(hashes)):
		_hash = _hashes[0]
		_hashes = _hashes[1:]
		if _hash in _hashes:
			collisions = collisions + 1
	if write:
		f = open(result_path("testresults.txt",out),"a")
		f.write("Found a total number of {} Collisions.\n\n".format(collisions))
		f.close()
	else:
		print("Found a total number of {} Collisions.\n".format(collisions))
	return


def test_hash_time(write = False, time = False, iterations = 2**16, out = "results"):
	if time:
		data = squash_init(time, iterations<<4)
		if write:
			f = open(result_path("testresults.txt",out),"a")
			f.write("[Squash] Calculation of {} hashes took {}s\n".format(iterations, data[0]))
			f.write("[Squash] Calculation per hash took {}ns\n\n".format(int(1000000000*data[1])))
			f.close()
		else:
			print("[Squash] Calculation of {} hashes took {}s".format(iterations, data[0]))
			print("[Squash] Calculation per hash took {}ns\n".format(int(1000000000*data[1])))
	return(squash_init(False, iterations))

def test_keccak_time(write = False, time = False, iterations = 2**16, out = "results"):
	if time:
		data = keccak_init(time, iterations<<4)
		if write:
			f = open(result_path("testresults.txt",out),"a")
			f.write("[Keccak] Calculation of {} hashes took {}s\n".format(iterations, data[0]))
			f.write("[Keccak] Calculation per hash took {}ns\n\n".format(int(1000000000*data[1])))
			f.close()
		else:
			print("[Keccak] Calculation of {} hashes took {}s".format(iterations, data[0]))
			print("[Keccak] Calculation per hash took {}ns\n".format(int(1000000000*data[1])))
	return(keccak_init(False, iterations))

if __name__ == "__main__":
	keccak, squash, iterations, time, collisions, probability, similarity, bit, bucket, write, plot, out = init()

	open(result_path("testresults.txt",out),"w").write('')
	if keccak:
		hashes = test_keccak_time(write=write, time=time, iterations=iterations, out=out)
		if collisions:
			test_collisions(hashes, write=write, out=out)
		if probability:
			evaluate_probability(hashes, write=write, out=out)
		if similarity:
			evaluate_similarity(hashes, 16, write=write, out=out)
		if bucket:
			plot_data(data=bucket_histogram(hashes,0xFFFF),name="keccak_bucket_histogram", plot=plot, out=out)
		if bit:
			plot_data(data=bit_histogram(hashes),name="keccak_bit_histogram", plot=plot, out=out)
	if squash:
		hashes = test_hash_time(write=write, time=time, iterations=iterations, out=out)
		if collisions:
			test_collisions(hashes, write=write, out=out)
		if probability:
			evaluate_probability(hashes, write=write, out=out)
		if similarity:
			evaluate_similarity(hashes, 16, write=write, out=out)
		if bucket:
			plot_data(data=bucket_histogram(hashes,0xFFFF),name="squash_bucket_histogram", plot=plot, out=out)
		if bit:
			plot_data(data=bit_histogram(hashes),name="squash_bit_histogram", plot=plot, out=out)
