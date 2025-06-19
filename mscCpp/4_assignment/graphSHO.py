import numpy as np
import matplotlib.pyplot as plt 

A=np.loadtxt("data.txt")
x=A[:,0]
y=A[:,1]
z=A[:,2]
plt.plot(x,y,'-b',label='Distance from center (cm)')
plt.plot(x,z,'-r',label='Speed of the object (cm/s)')
plt.xlabel('Time (s)')
plt.title('Simple Harmonic Oscillator',color='blue')
plt.legend()
plt.grid()
plt.tight_layout()
plt.savefig("plot.png",dpi=300)
