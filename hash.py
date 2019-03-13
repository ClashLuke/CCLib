import binascii
from Crypto.Cipher import AES

def encrypt(key, iv, plain_text):
	return(AES.new(key, AES.MODE_CBC, iv).encrypt(plain_text))

def crc32(message):
	return(pad_classic(hex(binascii.crc32(message) & 0xFFFFFFFF)[2:],7,'0'))

def read(message, location):
	location = int(location, 16)
	return(pad_encode(message[location:location+4], 3, '\x00'))

def pad_classic(data, lenght, placeholder):
	return (placeholder * (-(len(data))&lenght) + data)

def pad_encode(data, lenght, placeholder):
	return (data + (placeholder * (-(len(data))&lenght)).encode())


def ror(v, bits):
	return(((v<<bits)|(v>>(256-bits)))&0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff)

def hash(data, scratchpad):
	crc = ["","","",""]
	bits = ["",""]
	crc[0] = crc32(data[ 0: 4]) + crc32(data[ 4: 8])
	crc[1] = pad_classic(hex(int(crc32(read(scratchpad, crc[0][0:4])+read(scratchpad, crc[0][4:])),16) ^ int(data[ 8:16].hex(),16))[2:],15,'0')

	crc_int = [int(crc[1],16),int(data[16:24].hex(),16)]

	crc[2] = pad_classic(hex(((crc_int[1] + crc_int[0])&0xffffffffffffffff) ^ int(crc_int[1] // crc_int[0]))[2:],15,'0')
	crc[3] = pad_classic(data[24:  ].hex(),15,'0')

	bits[0] = ''.join(crc)
	bits[1] = pad_classic(hex(ror(int(bits[0],16),int(bits[0][0:2],16)&0xFF))[2:],31,'0')

	bits = [bytes.fromhex(b) for b in bits]
	return(bytes.fromhex(encrypt(bits[1][16:], bits[1][0:16], bits[0]).hex()))
