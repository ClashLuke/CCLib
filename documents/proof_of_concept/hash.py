import binascii
from Crypto.Cipher import AES

def encrypt(key, plain_text):
	return(AES.new(key[0:16], AES.MODE_CBC, key[16:]).encrypt(plain_text))

def crc32(message):
	return(binascii.crc32(message) & 0xFFFFFFFF)

def read(message, location):
	return(message[location:location+0x10] + '\x00' * ((-len(message))&0xF))

def hash(data):
	data = data * int(0x10000//len(data))
	data = data + '\x00' * (-(len(data))&0xFFFF)

	crc1 = hex(crc32(data.encode()))[2:]
	bits = ''.join([read(data, int(crc1[0:4],16)), read(data, int(crc1[4:],16))])

	crc2 = hex(crc32(bits.encode()))

	hex_string = hex(int(int.from_bytes(read(data, int(crc2[0:4],16)).encode(), byteorder='big')+1) // (int.from_bytes(read(data, int(crc2[4:],16)).encode(), byteorder='big')+1))[2:]
	
	plain_text = bytes.fromhex(hex_string + '0' * ((-len(hex_string))&0x1F))

	return(encrypt(bits, plain_text))

