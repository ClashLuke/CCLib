from hash import hash

def iterate(seed, iterations):
	hashes = []
	for i in range(iterations):
		hashes.append(hex(int.from_bytes(hash(seed + chr(i)),byteorder="big"))[2:])
	hashes = [h + '0' * (-(len(h))&0x1F) for h in hashes]
	return hashes

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

if __name__ == "__main__":
	import time
	import sys
	try:
		seed = sys.argv[1]
	except:
		import hashlib
		seed = hashlib.sha512(str(time.time()).encode()).hexdigest()
	try:
		iterations = int(sys.argv[2])
	except:
		iterations = 4
	hashes = iterate(seed, iterations)
	differences = compare(hashes,iterations)
	print("\t    Hash\t\t\t\t    Difference")
	print(hashes[0],hashes[0],sep='\t')
	for i in range(1,iterations):
		print(hashes[i], differences[i-1],sep='\t')
