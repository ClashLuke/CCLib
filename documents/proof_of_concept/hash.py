import binascii
from Crypto.Cipher import AES

def encrypt(key, iv, plain_text):
	return(AES.new(key, AES.MODE_CBC, iv).encrypt(plain_text))

def crc32(message):
	return(binascii.crc32(message) & 0xFFFFFFFF)

def read(message, location):
	return(pad_encode(message[location:location+0x10], 0xF, '\x00'))

def pad_classic(data, lenght, placeholder):
	return (data + placeholder * (-(len(data))&lenght))

def pad_encode(data, lenght, placeholder):
	return (data + (placeholder * (-(len(data))&lenght)).encode())

def ror(val, r_bits):
    return(((val & 0xFFFFFFFFFFFFFFFF) >> r_bits) | ((val << (0x3F-r_bits)) & 0xFFFFFFFFFFFFFFFF))

def hash(data):
	crc = ["","",""]	
	crc[0] = pad_classic(hex(crc32(data))[2:], 0x7, '0')
	bits1 = (read(data, int(crc[0][0:4],16))+read(data, int(crc[0][4:],16)))

	crc[1] = pad_classic(hex(crc32(bytes.fromhex(crc[0])+bits1))[2:], 0x7, '0')
	crc[2] = pad_classic(hex(ror(int(crc[0]+pad_classic(hex((int(crc[0],16) + int(crc[1],16))&0xFFFFFFFF)[2:], 0x7, '0'),16), int(crc[1],16)&0x3F))[2:], 0x7, '0')
	bits2 = bytes.fromhex(''.join(crc))

	if int((int(crc[0],16) / int(crc[1],16)))&1:
		bits3 = read(data, int(crc[2][0:4],16))
	else:
		bits3 = read(data, int(crc[2][4:8],16))
	return(bytes.fromhex(encrypt(bits3, bits2, bits1).hex()))
