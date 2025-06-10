import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
n=len(A)
B=np.loadtxt("/home/vikas/Desktop/work/data1.txt")

for i in range(n):
		plt.plot(B,A,'ro',markersize=0.02)

plt.grid()
plt.show()
