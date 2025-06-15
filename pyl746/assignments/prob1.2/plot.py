import numpy as np
import matplotlib.pyplot as plt

C=np.linspace(-2,4,1000)
A=np.loadtxt("/home/vikas/work/data.txt")
x1=A[:,0]
x2=A[:,1]
y=A[:,2]

plt.hist(y,bins=C,density=True)
plt.title("Probability Density for Y=X1+X2")
plt.xlabel("Random Variable")
plt.ylabel("Probability Density")
plt.grid()
plt.savefig("/sdcard/plot.png",dpi=300)
