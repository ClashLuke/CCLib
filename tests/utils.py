import time as time_module
import os
import queue
import hashlib
import sys

def parse_args():
	iterations = ("--iterations" in sys.argv) or ("-i" in sys.argv)
	time = ("--time" in sys.argv) or ("-t" in sys.argv)
	collisions = ("--collisions" in sys.argv) or ("-c" in sys.argv)
	bit = ("--bit" in sys.argv) or ("-b" in sys.argv)
	bucket = ("--bucket" in sys.argv) or ("-B" in sys.argv)

	write = ("--write" in sys.argv) or ("-w" in sys.argv)
	plot = ("--plot" in sys.argv) or ("-P" in sys.argv)
	out = ("--out" in sys.argv) or ("-o" in sys.argv)

	help = ("--help" in sys.argv) or ("-h" in sys.argv)

	if help or len(sys.argv) == 1 or not(time or collisions or bit or bucket) or not(iterations):
		show_help()
	if iterations:
		for i in range(len(sys.argv)):
			if sys.argv[i] == "-i" or sys.argv[i] == "--iterations":
				try:
					iterations = int(sys.argv[i+1])
					break
				except:
					print("Please enter a valid iteration number.")
					sys.exit()
		
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
					sys.exit()
	else:
		out = "results"
	return([iterations, time, collisions, bit, bucket, write, plot, out])
			

def show_help():
	print("Test options")
	print("-i, --iterations          Set the number of iterations")
	print("-b, --bit                 Enable bit histogram")
	print("-B, --bucket              Enable bucket histogram")
	print("-c, --collisions          Enable collision testing")
	print("-t, --time                Enable runtime testing")
	print('')
	print("Output options")
	print("-o, --out                 Specify out directory")
	print("-P, --plot                Show plots instead of writing them")
	print("-w, --write               Write to a file instead of console outputs")
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

def iterate(seed, iterations):
	if sys.platform == "linux" or sys.platform == "linux2":
		os.system("./hash.o 1 {}".format(iterations))
	else:
		os.system(  "hash.o 1 {}".format(iterations))
	os.system("sort hashes.txt -o hashes.txt")
	return

def test_time(seed):
	ctime = time_module.time()
	if sys.platform == "linux" or sys.platform == "linux2":
		os.system("./hash.o 0")
	else:
		os.system(  "hash.o 0")
	return(time_module.time()-ctime)


def sinit(time, iterations=0):
	seed = bytes.fromhex(open("hex.txt","r").read()[:-1])
	os.system("gcc squash.c aes.c -O3 -march=native -o hash.o -maes")
	if time:
		_time = test_time(seed)
		_per_hash = _time / 2**32
		return([_time,_per_hash])
	else:
		iterate(seed, iterations)
		return

def init():
	iterations, time, collisions, bit, bucket, write, plot, out = parse_args()
	try:
		os.mkdir(result_path("",out))
	except:
		pass
	return([iterations, time, collisions, bit, bucket, write, plot, out])
	

