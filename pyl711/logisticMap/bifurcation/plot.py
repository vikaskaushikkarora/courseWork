import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
n=len(A[:,0])
m=len(A[0,:])
B=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
C=np.ones(m)

for i in range(n):
		plt.plot(B[i]*C,A[i,:],'ro',markersize=0.02)

plt.grid()
plt.show()
