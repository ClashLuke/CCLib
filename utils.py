from hash import hash
from threading import Thread
import time as time_module
import os.path
import queue
import hashlib
import sys

def parse_args():
	keccak = ("--keccak" in sys.argv) or ("-k" in sys.argv)
	squash = ("--squash" in sys.argv) or ("-s" in sys.argv)
	iterations = ("--iterations" in sys.argv) or ("-i" in sys.argv)
	threads = ("--threads" in sys.argv) or ("-t" in sys.argv)

	time = ("--time" in sys.argv) or ("-T" in sys.argv)
	collisions = ("--collisions" in sys.argv) or ("-c" in sys.argv)
	probability = ("--probability" in sys.argv) or ("-p" in sys.argv)
	similarity = ("--similarity" in sys.argv) or ("-S" in sys.argv)
	bit = ("--bit" in sys.argv) or ("-b" in sys.argv)
	bucket = ("--bucket" in sys.argv) or ("-B" in sys.argv)

	write = ("--write" in sys.argv) or ("-w" in sys.argv)
	plot = ("--plot" in sys.argv) or ("-P" in sys.argv)
	out = ("--out" in sys.argv) or ("-o" in sys.argv)

	help = ("--help" in sys.argv) or ("-h" in sys.argv)

	if help or len(sys.argv) == 1 or not(keccak or squash) or not(time or collisions or probability or similarity or bit or bucket):
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
	return([keccak, squash, iterations, threads, time, collisions, probability, similarity, bit, bucket, write, plot, out])
			

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
	print("-b, --bit                 Enable bit histogram")
	print("-B, --bucket              Enable bucket histogram")
	print('')
	print("Output options")
	print("-w, --write               Write to a file instead of console outputs")
	print("-P, --plot                Show plots instead of writing them")
	print("-o, --out                 Specify out directory")
	print('')
	print("-h, --help                Display this help message")
	exit()

def pad_classic(data, lenght, placeholder):
	return (placeholder * (-(len(data))&lenght) + data)

def plot_data(data, name, plot, out):
	import matplotlib.pyplot as plt	
	plt.clf()
	plt.scatter(data[1],data[0],s=0.2)
	if plot:
		plot.show(block=True)
	else:
		plt.savefig(result_path(name+".svg", out))
		plt.savefig(result_path(name+".png", out))

def result_path(name, folder):
	return(os.path.join(os.path.dirname(os.path.realpath(__file__))+'/'+folder+'/', name))

def padr(data, lenght):
	data = str(data)
	return (data + (' ' * (-(len(data))&lenght))[:-1])

def squash_iterate(seed, start, end):
	hashes = []
	for i in range(start, end):
		hashes.append(hash(bytes.fromhex(pad_classic(hex(i)[2:],63,'0')),seed).hex())
	hashes = [h + '0' * (-(len(h))&0x1F) for h in hashes]
	return hashes

def run_squash_iterate(seed, iterations, threads):
	iter_per_thread = int(iterations//(threads))
	thread_list = [None] * threads
	hashes = []
	que = queue.Queue()
	for i in range(0,threads):
		thread_list[i] = Thread(target=lambda q, arg1, arg2, arg3: q.put(squash_iterate(arg1, arg2, arg3)), args=(que, seed,i*iter_per_thread,(i+1)*iter_per_thread))
		thread_list[i].start()
	for i in range(0,threads):
		hashes = hashes + que.get()
	return hashes

def squash_test_time(seed, iterations):
	hash_value = hashlib.sha3_256(str(time_module.time()).encode()).digest()
	ctime = time_module.time()
	for i in range(iterations):
			hash_value = hash(hash_value, seed)
	return (time_module.time() - ctime)

def run_squash_test_time(seed, iterations, threads):
	iter_per_thread = int(iterations//(threads))
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
	keccak, squash, iterations, threads, time, collisions, probability, similarity, bit, bucket, write, plot, out = parse_args()
	try:
		os.mkdir(result_path("",out))
	except:
		pass
	return([keccak, squash, iterations, threads, time, collisions, probability, similarity, bit, bucket, write, plot, out])
	
