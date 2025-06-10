import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt") #Vector for energy levels
A.sort() #Vector for energy levels in ascending order
n=len(A)

B1=A.copy()
B2=A.copy()
B1=np.delete(B1,0)
B2=np.delete(B2,n-1)
C=B1-B2 #vector for spacing between energy levels
n=len(C)

Cav=np.sum(C)/n

D=np.linspace(0,1,50)
plt.hist(C,bins=D,density=True)
plt.yscale("log")
string="The average spacing is :\n "+str(Cav)
plt.text(0.6,1,string,bbox=dict(facecolor='red',alpha=0.5))
plt.title("2D Harmonic Potential Energy Level Spacing")
plt.xlabel("Normal Spacing $s$")
plt.ylabel("Probability Density")
#plt.show()
plt.savefig("/home/vikas/Desktop/work/harmonicPotentialSpacing1.png",dpi=400)
