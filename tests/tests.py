from utils import sinit, padr, plot_data, show_help, parse_args, result_path, init

def bit_histogram():
	values = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	f = open("hashes.txt",'r')	
	lenght = len(f.readline()[:-1])
	line = f.readline()
	while line:
		if line.replace('\n','').replace(' ','') == "":
			continue
		for i in range(lenght):
			values[i] = values[i] + int(line[i],16)
		line = f.readline()
	f.close()
	values = [v/sum(1 for line in open("hashes.txt",'r')) for v in values]
	return [values, [i for i in range(len(values))]]

def bucket_histogram(buckets):
	values = []
	for i in range(buckets+1):
		values.append(0)
	f = open("hashes.txt",'r')	
	line = f.readline()
	while line:
		values[int(line[:-1],16)&buckets] += 1
		line = f.readline()
	f.close()
	return [values, [i for i in range(len(values))]]

def test_collisions(write = False, out = "results"):
	collisions = 0
	f = open("hashes.txt",'r')
	line = f.readline()
	while line:
		try:
			line2 = f.readline()
			if line == line2:
				collisions = collisions + 1
			line = line2
		except:
			break
	f.close()
	l = sum(1 for line in open("hashes.txt",'r'))
	if write:
		f = open(result_path("testresults.txt",out),"a")
		f.write("Found a total number of {} Collisions in {} hashes.\n".format(collisions,l))
		f.close()
	else:
		print("Found a total number of {} Collisions.\n".format(collisions))
	return


def test_hash_time(write = False, time = False, iterations = 2**16, out = "results"):
	if time:
		data = sinit(time)
		if write:
			f = open(result_path("testresults.txt",out),"a")
			f.write("Calculation of {} hashes took {}s\n".format(1<<32, int(10*data[0])/10))
			f.write("Calculation per hash took {}ns\n\n".format(int(1000000000*data[1])))
			f.close()
		else:
			print("Calculation of {} hashes took {}s".format(1<<28, data[0]))
			print("Calculation per hash took {}ns\n".format(int(1000000000*data[1])))
	sinit(False, iterations)
	return

if __name__ == "__main__":
	iterations, time, collisions, bit, bucket, write, plot, out = init()

	open(result_path("testresults.txt",out),"w").write('')
	test_hash_time(write=write, time=time, iterations=iterations, out=out)
	if collisions:
		test_collisions(write=write, out=out)
	if bucket:
		plot_data(data=bucket_histogram(0xFFFF),name="squash_bucket_histogram", plot=plot, out=out)
	if bit:
		plot_data(data=bit_histogram(),name="squash_bit_histogram", plot=plot, out=out)
