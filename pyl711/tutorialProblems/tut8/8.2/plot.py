import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
x=A[:,0]
y=A[:,1]

plt.plot(x,y,'r*',markersize=0.3)
plt.show()
