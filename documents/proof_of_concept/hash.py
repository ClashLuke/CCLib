import binascii
from Crypto.Cipher import AES

def encrypt(key, iv, plain_text):
	return(AES.new(key, AES.MODE_CBC, iv).encrypt(plain_text))

def crc32(message):
	return(binascii.crc32(message) & 0xFFFFFFFF)

def read(message, location):
	value = message[location:location+0x10]
	return(pad_encode(value, 0xF, '\x00'))

def pad_classic(data, lenght, placeholder):
	return (data + placeholder * (-(len(data))&lenght))

def pad_encode(data, lenght, placeholder):
	return (data + (placeholder * (-(len(data))&lenght)).encode())

def hash(data):	
	crc1 = hex(crc32(data)).replace('0x','')
	crc1 = pad_classic(crc1, 0x7, '0')
	bits1 = (read(data, int(crc1[0:4],16))+read(data, int(crc1[4:],16)))

	crc2 = hex(crc32(data+bits1))[2:]
	crc2 = pad_classic(crc2, 0x7, '0')
	bits2 = (read(data, int(crc2[0:4],16))+read(data, int(crc2[4:],16)))

	crc3 = hex((int(crc1,16) + int(crc2,16))&0xFFFFFFFF)
	crc3 = pad_classic(crc2, 0x7, '0')
	bits3 = (read(data, int(crc3[0:4],16))+read(data, int(crc3[4:],16)))

	if int((int(crc1,16) / int(crc2,16)))&1:
		bits2 = bits2[:16]
	else:
		bits2 = bits2[16:]
	return(bytes.fromhex(encrypt(bits1, bits2, bits3).hex()))



