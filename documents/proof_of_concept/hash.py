import binascii
from Crypto.Cipher import AES

def encrypt(key, iv, plain_text):
	return(AES.new(key, AES.MODE_CBC, iv).encrypt(plain_text))

def crc32(message):
	return(binascii.crc32(message) & 0xFFFFFFFF)

def read(message, location):
	value = message[location:location+0x10]
	return(pad(value, 0xF, '\x00'))

def pad(data, lenght, placeholder):
	return (data + placeholder * (-(len(data))&lenght))

def hash(data):
	data = data * int(0x10000//len(data))
	data = pad(data, 0xFFFF, '\x00')
	
	crc1 = hex(crc32(data.encode())).replace('0x','')
	crc1 = pad(crc1, 0x7, '0')
	bits1 = (read(data, int(crc1[0:4],16))+read(data, int(crc1[4:],16))).encode()

	crc2 = hex(crc32(bits1))[2:]
	crc2 = pad(crc2, 0x7, '0')
	bits2 = (read(data, int(crc2[0:4],16))+read(data, int(crc2[4:],16))).encode()

	hex_string1 = hex(int(int.from_bytes(bits1[0:16], byteorder='big')+int(crc1[0:4],16)) // (int.from_bytes(bits2[16:], byteorder='big')+int(crc2[4:],16)))[2:]
	hex_string2 = hex(int(int.from_bytes(bits2[0:16], byteorder='big')+int(crc2[0:4],16)) // (int.from_bytes(bits1[16:], byteorder='big')+int(crc1[4:],16)))[2:]
	plain_text1 = bytes.fromhex(pad(hex_string1, 0x1F, '0'))
	plain_text2 = bytes.fromhex(pad(hex_string2, 0x1F, '0'))

	return(bytes.fromhex(encrypt(bits1[0:16],bits1[16:], plain_text1).hex()+encrypt(bits2[0:16],bits2[16:], plain_text2).hex()))



