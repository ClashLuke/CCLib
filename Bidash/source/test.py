def l(num):
	s = str(num)
	s = ' '*(4-len(s))+s
	return s

def g(num):
	s = str(num)
	s = ' '*(3-len(s))+s
	return s

for i in range(128):
	j=i+128
	k=i+256
	m=i+384
	n=i+512
	o=i+640
	p=i+768
	q=i+896
	print("\t\tmix[{}] = mix[{}] = mix[{}] = mix[{}] =\n\t\tmix[{}] = mix[{}] = mix[{}] = mix[{}];".format(g(j),g(k),l(m),g(n),g(o),g(p),l(q),g(i)))
	
