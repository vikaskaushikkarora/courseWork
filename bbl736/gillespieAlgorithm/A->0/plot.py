import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/work/data.txt")
B=A[0,:]
m=int(len(B)/2)

for i in range(m):
	plt.plot(A[:,2*i],A[:,2*i+1])
	
plt.grid()
plt.show()
