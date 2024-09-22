import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
B=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
C=np.loadtxt("/home/vikas/Desktop/work/data2.txt")
x=A[:,0]
y=A[:,1]
n=len(x)

'''
def f(x):
	return (x*x*x)*(1+x*x)**(-1)

for i in range(n):
	plt.plot(B,C)
	plt.plot(x[int(f(i)):i+1],y[int(f(i)):i+1],'k-',linewidth=0.5)
	plt.plot(x[0:i+1],y[0:i+1],'ro',markersize=0.3)
	plt.plot(x[i],y[i],'ro')
	plt.xlim(-0.1,1.1)
	plt.ylim(-0.1,1)
	plt.pause(0.01)
	plt.clf()

'''
plt.plot(x,y,'r*',markersize=0.3)
plt.show()
