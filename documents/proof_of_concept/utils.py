from hash import hash
import time
import hashlib

def padr(data, lenght):
	data = str(data)
	return (data + (' ' * (-(len(data))&lenght))[:-1])

def squash_iterate(seed, iterations):
	hashes = []
	grand = iterations//256
	_seed = ""
	for i in range(1, grand+1):
		_seed = seed[:-i]
		for j in range(256):
			hashes.append(hex(int.from_bytes(hash(_seed + (chr(j) * i).encode()),byteorder="big"))[2:])
	hashes = [h + '0' * (-(len(h))&0x1F) for h in hashes]
	return hashes

def squash_test_time(seed, iterations):
	hash_value = hashlib.sha3_256(str(time.time()).encode()).digest()
	_seed = seed[:-32]
	ctime = time.time()
	for i in range(iterations):
			hash_value = hash(_seed + hash_value)
	return (time.time() - ctime)

def squash_init():
	seed = bytes.fromhex(open("hex.txt","r").read()[:-1])

	iterations = 0x100000 # 2**20
	_time = squash_test_time(seed, iterations)
	_per_hash = _time / iterations

	iterations = 0x10000  # 2**16
	_hashes = squash_iterate(seed, iterations)

	return([_hashes,_time,_per_hash])




def keccak_iterate(seed, iterations):
	_hashes = [seed]
	for i in range(iterations):
		_hashes.append(hashlib.sha3_256(_hashes[-1]).digest())
	_hashes = [h.hex() for h in _hashes]
	return(_hashes)

def keccak_test_time(seed, iterations):
	ctime = time.time()
	for i in range(iterations):
		seed = hashlib.sha3_256(seed).digest()
	_time = time.time() - ctime
	return(_time)

def keccak_init():
	seed = hashlib.sha3_256(str(time.time()).encode()).digest()

	iterations = 0x10000000 # 2**28
	_time = keccak_test_time(seed, iterations)
	_per_hash = _time / iterations

	iterations = 0x10000    # 2**16
	_hashes = keccak_iterate(seed, iterations)

	return([_hashes,_time,_per_hash])
	
