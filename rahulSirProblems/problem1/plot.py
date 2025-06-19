import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
B=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
C=np.arange(-B[0],B[0],0.005)
#C=np.arange(-2,2,0.1)
n=len(A)
plt.hist(A,bins=C,density=True)
plt.ylim(-0.1,1)
plt.show()
