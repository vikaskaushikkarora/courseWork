import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/work/data.txt")
C=np.arange(0,20,0.01)

plt.hist(A[:,2],bins=C,density=True)
plt.xlabel("Random Variable")
plt.ylabel("Probability Density")
plt.title("Probability Density for Y=X1+X2")
plt.grid()
plt.savefig("/sdcard/plot.png",dpi=300)
