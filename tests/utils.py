from hash import hash_windows, hash_linux
import time
import sys

def padr(data, lenght):
	return(data + ' ' * (-(len(data))&lenght))

def pad(data):
	return('0' * (len(data)&1) + data)

def read():
	out_list = open("out.txt","r").read().split('\n')[0:-1]
	out = []
	temp_out_list = []
	for o in out_list:
		temp_out = ""
		temp_out_list = o.split(' ')
		for t in temp_out_list:
			temp_out = temp_out + pad(t)
		out.append(temp_out)
	open("out.txt","w").write('')
	return (out)


def init():
	ctime = time.time()
	if sys.platform == "linux" or sys.platform == "linux2":
		hash_linux()
	else:
		hash_windows()
	hashes = read()
	ctime = int(time.time() - ctime)
	print("[Squash] Total calculation took {}s".format(ctime))
	print("[Squash] Calculation per hash took {}ns\n".format(int(1000000000*ctime/0x400000)))
	hashes = [h + '0' * (-(len(h))&0x1F) for h in hashes]
	
	return hashes
