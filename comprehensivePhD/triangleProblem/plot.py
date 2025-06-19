import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("data.txt")
B=np.loadtxt("data1.txt")
C=np.loadtxt("data2.txt")
x=A[:,0]
y=A[:,1]
n=len(x)

plt.plot(x,y,'k*',markersize=0.2)
plt.savefig("plotQ5.pdf",dpi=250)
