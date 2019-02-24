import os

def pad(data):
	return ('0' * (len(data)&1) + data)


def hash_windows():
	os.system("hash.exe")

def hash_linux():
	os.system("./hash")




