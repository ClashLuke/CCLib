from utils import squash_init, keccak_init, padr

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
	
def evaluate_probability(hashes):
	counts = count(hashes)
	total = sum(counts)
	counts = [int(100*c/total) for c in counts]
	for i in range(len(counts)):
		print("Value {}has a total share of {}%".format(padr(i,3),counts[i]))
	print('\n')

def evaluate_similarity(hashes, iterations):
	differences = compare(hashes,iterations)
	print("\t\t\t\tHash\t\t\t\t\t\t\t\t\tDifference")
	for i in range(1,iterations+1):
		try:
			print(hashes[i], differences[i-1],sep='\t')
		except:
			break
	print('\n')

def plot(data, name):
	import matplotlib.pyplot as plt	
	plt.clf()
	plt.scatter(data[1],data[0],s=0.2)
	plt.savefig(name+".svg")
	plt.savefig(name+".png")

def bit_histogram(hashes):
	values = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	lenght = len(hashes[0])
	for hash in hashes:
		for i in range(lenght):
			values[i] = values[i] + int(hash[i],16) 
	values = [v/len(hashes) for v in values]

	return [values, [i for i in range(len(values))]]

def bucket_histogram(hashes, buckets):
	values = []
	for i in range(buckets+1):
		values.append(0)
	for hash in hashes:
		values[int(hash,16)&buckets] += 1
	return [values, [i for i in range(len(values))]]

def test_collisions(hashes):
	collisions = 0
	for i in range(len(hashes)):
		if hashes[i] in hashes[0:i]+hashes[i+1:]:
			collisions = collisions + 1
	print("Found a total number of {} Collisions.\n".format(collisions))
	return


def test_hash_time():
	data = squash_init()
	print("[Squash] Total calculation took {}s".format(data[1]))
	print("[Squash] Calculation per hash took {}ns\n".format(int(1000000000*data[2])))
	return(data[0])

def test_keccak_time():
	data = keccak_init()
	print("[Keccak] Calculation of 2**29 hashes took {}s".format(data[1]))
	print("[Keccak] Calculation per hash took {}ns\n".format(int(1000000000*data[2])))
	return(data[0])

if __name__ == "__main__":
	hashes = test_keccak_time()
	test_collisions(hashes)
	evaluate_probability(hashes)
	evaluate_similarity(hashes, 16)
	plot(bit_histogram(hashes),"keccak_bit_histogram")
	plot(bucket_histogram(hashes,0xFFFF),"keccak_bucket_histogram")
	hashes = test_hash_time()
	test_collisions(hashes)
	evaluate_probability(hashes)
	evaluate_similarity(hashes, 16)
	plot(bit_histogram(hashes),"squash_bit_histogram")
	plot(bucket_histogram(hashes,0xFFFF),"squash_bucket_histogram")
