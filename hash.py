import binascii
from Crypto.Cipher import AES

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
