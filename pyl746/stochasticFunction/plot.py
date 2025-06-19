import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/work/data.txt")
t=A[:,0]
X=A[:,1]
Y=A[:,2]

plt.plot(t,X,'r-',linewidth=0.3)
plt.plot(t,Y,'k-',linewidth=0.3)
plt.show()
