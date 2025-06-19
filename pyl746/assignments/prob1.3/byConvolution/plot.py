import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/work/data.txt")
t=A[:,0]
fx1=A[:,1]
fx2=A[:,2]
conv=A[:,3]

plt.plot(t,fx1,'k-',label="X1")
plt.plot(t,fx2,'b-',label="X2")
plt.plot(t,conv,'r-',label="Y")
plt.xlabel("Value of Random Variable")
plt.ylabel("Probability Density")
plt.title(r"Y=X1+X2 for $\lambda$ = 0.5")
plt.grid()
plt.legend()
plt.savefig("/sdcard/plot.png",dpi=300)
