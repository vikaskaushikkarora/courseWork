import numpy as np
import matplotlib.pyplot as plt 

A=np.loadtxt("data1.txt")
x=A[:,0]
a=A[:,1]
b=A[:,2]
c=A[:,3]
d=A[:,4]
k=A[:,5]
k12=A[:,6]
m=A[:,7]
y=0.5*m*c*c + 0.5*m*d*d
z=0.5*k*a*a+0.5*k*b*b+0.5*k12*(a-b)**2
w=y+z
plt.plot(x,y,'-b',linewidth=0.4,label='Total Kinetic Energy')
plt.plot(x,z,'-r',linewidth=0.4,label='Total Potential Energy')
plt.plot(x,w,'-g',linewidth=0.5,label='Total Mechanical Energy')
plt.xlabel('Time (s)')
plt.ylabel(r'Energies ($10^{-4}$ Joules)')
plt.title('Coupled Oscillators ( Energy )',color='blue')
plt.legend()
plt.grid()
plt.tight_layout()
plt.savefig("plot3.png",dpi=300)
