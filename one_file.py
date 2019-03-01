import binascii
from Crypto.Cipher import AES
from threading import Thread
import time as time_module
import os.path
import queue
import hashlib
import sys


def encrypt(key, iv, plain_text):
	return(AES.new(key, AES.MODE_CBC, iv).encrypt(plain_text))

def crc32(message):
	return(pad_classic(hex(binascii.crc32(message) & 0xFFFFFFFF)[2:],7,'0'))

def read(message, location):
	location = int(location, 16)
	return(pad_encode(message[location:location+0x8], 0x7, '\x00'))

def pad_classic(data, lenght, placeholder):
	return (placeholder * (-(len(data))&lenght) + data)

def pad_encode(data, lenght, placeholder):
	return (data + (placeholder * (-(len(data))&lenght)).encode())


def ror(v, bits):
	return((v<<bits)|(v>>(64-bits))&0xffffffffffffffff)

def rol(v, bits):
	return((v>>bits)|(v<<(64-bits))&0xffffffffffffffff)

def swap(v):
	v=(((v&0xff00ff00ff00ff00ff00ff00ff00ff00)>>8) |((v&0x00ff00ff00ff00ff00ff00ff00ff00ff)<<8))&0xffffffffffffffffffffffffffffffff
	v=(((v&0xffff0000ffff0000ffff0000ffff0000)>>16)|((v&0x0000ffff0000ffff0000ffff0000ffff)<<16))&0xffffffffffffffffffffffffffffffff
	v=(((v&0xffffffff00000000ffffffff00000000)>>32)|((v&0x00000000ffffffff00000000ffffffff)<<32))&0xffffffffffffffffffffffffffffffff
	v=((v>>64)|(v<<64))&0xffffffffffffffffffffffffffffffff
	return v


def hash(data):
	crc = ["","","",""]
	crc_int = [0,0,0,0]
	byts = ["",""]
	crc[0] = crc32(data)
	bits3 = (read(data, crc[0][0:4])+read(data, crc[0][4:]))

	crc[1] = crc32(bits3)
	crc_int = [int(c,16) for c in crc[0:2]]
	crc[2] = pad_classic(hex(((crc_int[0] + crc_int[1])&0xffffffff) ^ int(crc_int[0] // crc_int[1]))[2:],7,'0')
	crc[3] = pad_classic(hex((crc_int[0] << (int(crc[1][0:2],16)&31)) | (crc_int[1] >> (31^(int(crc[1][0:2],16)&31))))[2:],7,'0')

	byts[1] = pad_classic(hex(ror(int(crc[2]+crc[3],16),int(crc[0][0:2],16)&0x3F))[2:],15,'0')
	byts[0] = pad_classic(hex(rol(int(crc[0]+crc[1],16),int(byts[1][0],16)&0x3F))[2:],15,'0')

	bits3 = bits3 + read(data, byts[0][0:2]) + read(data, byts[0][2:3])
	bits1 = pad_classic(hex(swap(int(''.join(byts),16)))[2:], 31, '0')
	bits2 = read(data, bits1[bits3[0]&15:2+(bits3[0]&15)]) + read(data, bits1[bits3[1]&15:2+(bits3[1]&15)])
	bits1 = bytes.fromhex(bits1)

	return(bytes.fromhex(encrypt(bits1, bits2, bits3).hex()))

def parse_args():
	keccak = ("--keccak" in sys.argv) or ("-k" in sys.argv)
	squash = ("--squash" in sys.argv) or ("-s" in sys.argv)
	iterations = ("--iterations" in sys.argv) or ("-i" in sys.argv)
	threads = ("--threads" in sys.argv) or ("-t" in sys.argv)

	time = ("--time" in sys.argv) or ("-T" in sys.argv)
	collisions = ("--collisions" in sys.argv) or ("-c" in sys.argv)
	probability = ("--probability" in sys.argv) or ("-p" in sys.argv)
	similarity = ("--similarity" in sys.argv) or ("-S" in sys.argv)

	write = ("--write" in sys.argv) or ("-w" in sys.argv)
	out = ("--out" in sys.argv) or ("-o" in sys.argv)

	help = ("--help" in sys.argv) or ("-h" in sys.argv)

	if help or len(sys.argv) == 1 or not(keccak or squash) or not(time or collisions or probability or similarity):
		show_help()
	if iterations:
		for i in range(len(sys.argv)):
			if sys.argv[i] == "-i" or sys.argv[i] == "--iterations":
				try:
					iterations = int(sys.argv[i+1])
					break
				except:
					print("Please enter a valid iteration number.")
					break
	if threads:
		for i in range(len(sys.argv)):
			if sys.argv[i] == "-t" or sys.argv[i] == "--threads":
				try:
					threads = int(sys.argv[i+1])
					break
				except:
					print("Please enter a valid threads count.")
					break
	if out:
		for i in range(len(sys.argv)):
			if sys.argv[i] == "-o" or sys.argv[i] == "--out":
				try:
					out = str(sys.argv[i+1])
					if not(out[0] == '-'):
						break
					raise Exception('')
				except:
					print("Please enter a valid output directory.")
					break
	else:
		out = "results"
	return([keccak, squash, iterations, threads, time, collisions, probability, similarity, write, out])
			

def show_help():
	print("Algorithm options")
	print("-k, --keccak              Perform tests on keccak")
	print("-s, --squash              Perform tests on squash")
	print("-i, --iterations          Set the number of iterations")
	print("-t, --threads num         Specify the number of threads to use (Squash only)")
	print('')
	print("Test options")
	print("-T, --time                Enable runtime testing")
	print("-c, --collisions          Enable collision testing")
	print("-p, --probability         Enable testing of value probabilities")
	print("-S, --similarity          Enable testing of hash similarities")
	print('')
	print("Output options")
	print("-w, --write               Write to a file instead of console outputs")
	print("-o, --out                 Specify out directory")
	print('')
	print("-h, --help                Display this help message")
	exit()

def result_path(name, folder):
	return(os.path.join(os.path.dirname(os.path.realpath(__file__))+'/'+folder+'/', name))

def padr(data, lenght):
	data = str(data)
	return (data + (' ' * (-(len(data))&lenght))[:-1])

def squash_iterate(seed, start, end):
	hashes = []
	mask = 0x10000 - len(seed)
	for i in range(start, end):
		cur = mask - i
		for j in range(1, 129):
			hashes.append(hash(seed + (chr(j)*i+'\x00'*cur).encode()).hex())
	hashes = [h + '0' * (-(len(h))&0x1F) for h in hashes]
	return hashes

def run_squash_iterate(seed, iterations, threads):
	iter_per_thread = int(iterations//(threads*128))
	_seed = seed[:-int(iterations//128)]
	thread_list = [None] * threads
	hashes = []
	que = queue.Queue()
	for i in range(0,threads):
		thread_list[i] = Thread(target=lambda q, arg1, arg2, arg3: q.put(squash_iterate(arg1, arg2, arg3)), args=(que, _seed,1+i*iter_per_thread,1+(i+1)*iter_per_thread))
		thread_list[i].start()
	for i in range(0,threads):
		hashes = hashes + que.get()
	return hashes

def squash_test_time(seed, iterations):
	hash_value = hashlib.sha3_256(str(time_module.time()).encode()).digest()
	_seed = seed[:-32]
	ctime = time_module.time()
	for i in range(iterations):
			hash_value = hash(_seed + hash_value)
	return (time_module.time() - ctime)

def run_squash_test_time(seed, iterations, threads):
	iter_per_thread = int(iterations//(threads*128))
	thread_list = [None] * threads
	times = []
	que = queue.Queue()
	for i in range(0,threads):
		thread_list[i] = Thread(target=lambda q, arg1, arg2: q.put(squash_test_time(arg1, arg2)), args=(que, seed, iter_per_thread))
		thread_list[i].start()
	for i in range(0,threads):
		times.append(que.get())
	return max(times)


def squash_init(time, iterations, threads):
	seed = bytes.fromhex(open("hex.txt","r").read()[:-1])

	if time:
		_time = run_squash_test_time(seed, iterations, threads)
		_per_hash = _time / iterations
		return([_time,_per_hash])
	else:
		_hashes = run_squash_iterate(seed, iterations, threads)
		return(_hashes)



def keccak_iterate(seed, iterations):
	_hashes = [seed]
	for i in range(iterations):
		_hashes.append(hashlib.sha3_256(_hashes[-1]).digest())
	_hashes = [h.hex() for h in _hashes]
	return(_hashes)

def keccak_test_time(seed, iterations):
	ctime = time_module.time()
	for i in range(iterations):
		seed = hashlib.sha3_256(seed).digest()
	_time = time_module.time() - ctime
	return(_time)

def keccak_init(time, iterations):
	seed = hashlib.sha3_256(str(time_module.time()).encode()).digest()
	
	if time:
		_time = keccak_test_time(seed, iterations)
		_per_hash = _time / iterations
		return([_time,_per_hash])
	else:
		_hashes = keccak_iterate(seed, iterations)
		return(_hashes)


def init():
	keccak, squash, iterations, threads, time, collisions, probability, similarity, write, out = parse_args()
	try:
		os.mkdir(result_path("",out))
	except:
		pass
	return([keccak, squash, iterations, threads, time, collisions, probability, similarity, write, out])

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

def test_collisions(hashes, write = False, out = "results"):
	collisions = 0
	_hashes = sorted(hashes[:])
	l = len(hashes)
	
	for i in range(l):
		try:
			if _hashes[i] == _hashes[i+1]:
				collisions = collisions + 1
		except:
			break
	if write:
		f = open(result_path("testresults.txt",out),"a")
		f.write("Found a total number of {} Collisions in {} hashes.\n".format(collisions,l))
		f.write("Collision probability is {}%.\n".format(int(1000000*collisions/l)/100))
		f.close()
	else:
		print("Found a total number of {} Collisions.\n".format(collisions))
	return


def test_hash_time(write = False, time = False, iterations = 2**16, out = "results", threads = 1):
	if time:
		data = squash_init(time, iterations<<4, threads)
		if write:
			f = open(result_path("testresults.txt",out),"a")
			f.write("[Squash] Calculation of {} hashes on {} threads took {}s\n".format(iterations<<4, threads, int(10*data[0])/10))
			f.write("[Squash] Calculation per hash took {}ns\n\n".format(int(1000000000*data[1])))
			f.close()
		else:
			print("[Squash] Calculation of {} hashes took {}s".format(iterations<<4, data[0]))
			print("[Squash] Calculation per hash took {}ns\n".format(int(1000000000*data[1])))
	return(squash_init(False, iterations, threads))

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
	keccak, squash, iterations, threads, time, collisions, probability, similarity, write, out = init()

	open(result_path("testresults.txt",out),"w").write('')
	if keccak:
		hashes = test_keccak_time(write=write, time=time, iterations=iterations, out=out)
		if collisions:
			test_collisions(hashes, write=write, out=out)
		if probability:
			evaluate_probability(hashes, write=write, out=out)
		if similarity:
			evaluate_similarity(hashes, 16, write=write, out=out)
	if squash:
		hashes = test_hash_time(write=write, time=time, iterations=iterations, out=out, threads=threads)
		if collisions:
			test_collisions(hashes, write=write, out=out)
		if probability:
			evaluate_probability(hashes, write=write, out=out)
		if similarity:
			evaluate_similarity(hashes, 16, write=write, out=out)
