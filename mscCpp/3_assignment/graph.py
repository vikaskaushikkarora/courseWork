import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt('data.txt')
x=A[:,1]
y=A[:,2]
Ex=A[0,5]
Ey=A[0,6]
Bz=A[0,7]
s="Ex = "+str(Ex)+"\nEy = "+str(Ey)+"\nBz = "+str(Bz)
plt.plot(x,y,'-r',label=s)
plt.title("Path of A Charged Particle",color='blue')
plt.xlabel("x")
plt.ylabel("y")
plt.grid(linestyle='-.',linewidth=0.3)
plt.tight_layout()
plt.legend()
plt.savefig('chargedParticle.png',dpi=300)
