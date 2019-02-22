from utils import init, padr

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

def plot(data):
	import matplotlib.pyplot as plt	
	plt.ion()
	plt.plot(data)
	plt.show(block=False)
	plt.pause(0.001)

def bit_histogram(hashes):
	values = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	lenght = len(hashes[0])
	for hash in hashes:
		for i in range(lenght):
			values[i] = values[i] + int(hash[i],16) 
	return([v/len(hashes) for v in values])

def test_time():
	import time
	ctime = time.time()
	data = init()
	ctime = int(time.time() - ctime)
	print("Total calculation took {}s".format(ctime))
	print("Calculation per hash took {}µs\n".format(int(1000000*ctime/data[1])))
	return(data[0])

if __name__ == "__main__":
	hashes = test_time()
	evaluate_probability(hashes)
	evaluate_similarity(hashes, 16)
	plot(bit_histogram(hashes))
	input("Press any key to stop")
