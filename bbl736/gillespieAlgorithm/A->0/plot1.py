import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/work/data1.txt")

C=np.linspace(0,0.03,40)
plt.hist(A[0,:],bins=C)
plt.show()
