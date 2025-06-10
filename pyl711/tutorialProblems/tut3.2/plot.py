import numpy as np
import matplotlib.pyplot as plt
import multiprocessing

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
n=len(A[:,0])
m=len(A[0,:])
B=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
C=np.ones(m)
D=np.loadtxt("/home/vikas/Desktop/work/data2.txt")

for i in range(n):
		plt.plot(B[i]*C,6+5*A[i,:],'ro',markersize=0.02)

plt.plot(B,D,'ko',markersize=0.25)

plt.grid()
plt.show()
