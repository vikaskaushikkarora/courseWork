import numpy as np
import matplotlib.pyplot as plt
from numpy import pi,exp,log,sin,cos

A=np.loadtxt("/home/vikas/Desktop/work/zeros6") # Vector for energy levels
A.sort() # Vector for energy levels in ascending order
n=len(A)

B1=A.copy()
B2=A.copy()
B1=np.delete(B1,0)
B2=np.delete(B2,n-1)
C=B1-B2 # Vector for spacing between energy levels
n=len(C)
Cav=np.sum(C)/n
C=C/Cav

def f(s):
	return (32/(pi*pi))*(s*s*exp(-4*s*s/pi))

D=np.linspace(0,3.5,500)
plt.hist(C,bins=D,density=True)
plt.plot(D,f(D),'-r',label='Theoretcial Distribution for non-integrable systems')
string="The average spacing is :\n "+str(Cav)
plt.text(2.0,0.5,string,bbox=dict(facecolor='red',alpha=0.5))
plt.title("Zeros of Reimann Zeta Function as Energy Level Spacing")
plt.xlabel("Normal Spacing $s$")
plt.ylabel("Probability Density")
plt.xlim(0,3.5)
plt.ylim(0,1.3)
plt.legend()
#plt.savefig("/home/vikas/Desktop/work/zerosOfReimannZetaSpacing.png",dpi=500)
plt.show()


