from hash import hash, pad

def padr(data, lenght):
	return(pad(str(data), lenght, ' ')[:-1])

def iterate(seed, iterations):
	hashes = []
	grand = iterations//128
	small = iterations % 128
	for i in range(grand):
		for j in range(128):
			hashes.append(hex(int.from_bytes(hash(seed + chr(j) * (i+1)),byteorder="big"))[2:])
	for i in range(small):
		hashes.append(hex(int.from_bytes(hash(seed + chr(j) * (i+1)),byteorder="big"))[2:])
	hashes = [h + '0' * (-(len(h))&0x1F) for h in hashes]
	return hashes


def init():
	import sys

	try:
		seed = sys.argv[1]
	except:
		import time
		import hashlib
		seed = hashlib.sha512(str(time.time()).encode()).hexdigest()
		seed = ''.join([chr(int(s,16)) for s in seed])
	try:
		iterations = int(sys.argv[2])
	except:
		iterations = 2**21

	return([iterate(seed, iterations),iterations])
