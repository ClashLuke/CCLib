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
	return(((v<<bits)|(v>>(128-bits)))&0xffffffffffffffffffffffffffffffff)

def rol(v, bits):
	return(((v>>bits)|(v<<(128-bits)))&0xffffffffffffffffffffffffffffffff)


def swap(v):
	v=(((v&0xff00ff00ff00ff00ff00ff00ff00ff00)>>8) |((v&0x00ff00ff00ff00ff00ff00ff00ff00ff)<<8))&0xffffffffffffffffffffffffffffffff
	v=(((v&0xffff0000ffff0000ffff0000ffff0000)>>16)|((v&0x0000ffff0000ffff0000ffff0000ffff)<<16))&0xffffffffffffffffffffffffffffffff
	v=(((v&0xffffffff00000000ffffffff00000000)>>32)|((v&0x00000000ffffffff00000000ffffffff)<<32))&0xffffffffffffffffffffffffffffffff
	v=((v>>64)|(v<<64))&0xffffffffffffffffffffffffffffffff
	return v
def small_swap(v):
	v=(((v&0xff00ff00ff00ff00)>>8) |((v&0x00ff00ff00ff00ff)<<8))&0xffffffffffffffff
	v=(((v&0xffff0000ffff0000)>>16)|((v&0x0000ffff0000ffff)<<16))&0xffffffffffffffff
	v=(((v&0xffffffff00000000)>>32)|((v&0x00000000ffffffff)<<32))&0xffffffffffffffff
	return v


def hash(data, scratchpad):
	crc = ["","","",""]
	bits = ["","",""]
	crc[0] = crc32(data[ 0: 4]) + crc32(data[ 4: 8])
	crc[1] = pad_classic(hex(int(crc32(read(scratchpad, crc[0][0:4])+read(scratchpad, crc[0][4:])),16) ^ int(data[ 8:16].hex(),16))[2:],15,'0')

	crc_int = [int(crc[1],16),int(data[16:24].hex(),16)]

	if crc_int[1] != 0:
		crc[2] = pad_classic(hex(((crc_int[0] + crc_int[1])&0xffffffffffffffff) ^ int(crc_int[0] // crc_int[1]))[2:],15,'0')
	else:
		crc[2] = pad_classic(hex(((crc_int[0] + crc_int[1])&0xffffffffffffffff) ^ int(crc_int[1] // crc_int[0]))[2:],15,'0')
		
	crc[3] = pad_classic(hex(small_swap(int(data[24:  ].hex(),16)))[2:],15,'0')

	bits[0] = ''.join(crc)
	bits[1] = pad_classic(hex(ror(int(bits[0],16),int(bits[0][0:2],16)&0x7F))[2:],31,'0')
	bits[2] = pad_classic(hex(swap(int(bits[1],16)))[2:],31,'0')

	bits = [bytes.fromhex(b) for b in bits]
	return(bytes.fromhex(encrypt(bits[2], bits[1], bits[0]).hex()))
