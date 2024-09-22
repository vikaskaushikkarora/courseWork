def bitreverse(i,n):
	return int(format(i,'0%db'%n)[::-1],2)

n=4
for i in range(2**n):
	print(i,"\t",bitreverse(i,n))

