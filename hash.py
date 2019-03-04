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
	return((v>>bits)|((v<<(64-bits))&0xffffffffffffffff))

def swap(v):
	v=(((v&0xff00ff00ff00ff00ff00ff00ff00ff00)>>8) |((v&0x00ff00ff00ff00ff00ff00ff00ff00ff)<<8))&0xffffffffffffffffffffffffffffffff
	v=(((v&0xffff0000ffff0000ffff0000ffff0000)>>16)|((v&0x0000ffff0000ffff0000ffff0000ffff)<<16))&0xffffffffffffffffffffffffffffffff
	v=(((v&0xffffffff00000000ffffffff00000000)>>32)|((v&0x00000000ffffffff00000000ffffffff)<<32))&0xffffffffffffffffffffffffffffffff
	v=((v>>64)|(v<<64))&0xffffffffffffffffffffffffffffffff
	return v


def hash(data, scratchpad):
	crc = [["","","",""],["","","",""],["","","",""]]
	crc[0][0] = crc32(data[ 0: 4])
	crc[0][1] = crc32(data[ 4: 8])
	crc[0][2] = crc32(data[ 8:12])
	crc[0][3] = crc32(data[12:  ])

	crc[1][0] = crc32(read(scratchpad, crc[0][0][0:4])+read(scratchpad, crc[0][0][4:]))
	crc[1][1] = crc32(read(scratchpad, crc[0][1][0:4])+read(scratchpad, crc[0][1][4:]))
	crc[1][2] = crc32(read(scratchpad, crc[0][2][0:4])+read(scratchpad, crc[0][2][4:]))
	crc[1][3] = crc32(read(scratchpad, crc[0][3][0:4])+read(scratchpad, crc[0][3][4:]))

	crc_int = [[int(c,16) for c in crc[0][0:]],[int(c,16) for c in crc[1][0:]]]

	crc[2][0] = pad_classic(hex(((crc_int[0][0] + crc_int[0][1])&0xffffffff) ^ int(crc_int[0][0] // crc_int[0][1]))[2:],7,'0')
	crc[2][1] = pad_classic(hex(((crc_int[1][0] + crc_int[1][1])&0xffffffff) ^ int(crc_int[1][0] // crc_int[1][1]))[2:],7,'0')
	crc[2][2] = pad_classic(hex(((crc_int[0][2] + crc_int[0][3])&0xffffffff) ^ int(crc_int[0][2] // crc_int[0][3]))[2:],7,'0')
	crc[2][3] = pad_classic(hex(((crc_int[1][2] + crc_int[1][3])&0xffffffff) ^ int(crc_int[1][2] // crc_int[1][3]))[2:],7,'0')

	bits = [''.join(crc[0]),''.join(crc[1]),''.join(crc[2])]


	bits[0] = pad_classic(hex(ror(int(bits[0],16),int(bits[0][0:2],16)&0x7F))[2:],31,'0')
	bits[1] = pad_classic(hex(ror(int(bits[1],16),int(bits[1][0:2],16)&0x7F))[2:],31,'0')
	bits[2] = pad_classic(hex(ror(int(bits[2],16),int(bits[2][0:2],16)&0x7F))[2:],31,'0')

	bits[2] = bits[2] + read(scratchpad, bits[0][0:2]).hex() + read(scratchpad, bits[0][2:4]).hex() + read(scratchpad, bits[0][4:6]).hex() + read(scratchpad, bits[0][6:8]).hex()

	bits = [bytes.fromhex(b) for b in bits]

	return(bytes.fromhex(encrypt(bits[0], bits[1], bits[2]).hex()))
