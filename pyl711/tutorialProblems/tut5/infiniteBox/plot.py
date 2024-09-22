import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
C=np.arange(0.01,2,0.02)
plt.hist(A,bins=C,density=True)
#plt.plot(C,1.7*np.exp(-2*C*C))
plt.show()
