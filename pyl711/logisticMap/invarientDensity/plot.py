import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
B=np.arange(0,1,0.00001)
plt.hist(A,bins=B,density=True)
plt.ylim(-0.1,10)
plt.show()

