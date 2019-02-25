from hash import hash

def padr(data, lenght):
	data = str(data)
	return (data + (' ' * (-(len(data))&lenght))[:-1])

def iterate(seed, iterations):
	hashes = []
	grand = iterations//128
	_seed = ""
	for i in range(1, grand+1):
		_seed = seed[:-i]
		for j in range(128):
			hashes.append(hex(int.from_bytes(hash(_seed + (chr(j) * i).encode()),byteorder="big"))[2:])
	hashes = [h + '0' * (-(len(h))&0x1F) for h in hashes]
	return hashes


def init():
	seed = bytes.fromhex(open("hex.txt","r").read()[:-1])
	iterations = 2**21

	return([iterate(seed, iterations),iterations])
