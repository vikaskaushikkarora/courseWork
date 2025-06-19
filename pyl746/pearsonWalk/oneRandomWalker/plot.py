import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/work/data.txt")

X=A[:,0]
Y=A[:,1]

plt.plot(X,Y,'r-')
plt.grid()
plt.show()
