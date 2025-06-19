import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/datax1.txt")
C=np.loadtxt("/home/vikas/Desktop/work/mapdata.txt")

Nx1=len(A)
Nx=len(C)

x=C[:,0]
y=C[:,1]

x1=np.zeros(2*Nx1)
y1=np.zeros(2*Nx1)

for i in range(Nx1-1):
	x1[2*i]=A[i]
	y1[2*i]=A[i]
	x1[2*i+1]=A[i]
	y1[2*i+1]=A[i+1]

for i in range(2*Nx1):
	plt.plot([-1,1],[-1,1]) #Plot straight line
	plt.plot(x,y) #Plot the map equation
	plt.plot(x1[i],y1[i],'*r')
	plt.plot(x1[0:i+1],y1[0:i+1],'r-')
	plt.xlim(0,1)
	plt.ylim(0,1)
	plt.grid()
	plt.pause(0.1)
	plt.clf()

'''
a=np.arange(1,Nx1+1,1)
plt.plot(a,A)
'''

plt.grid()
plt.show()
	
