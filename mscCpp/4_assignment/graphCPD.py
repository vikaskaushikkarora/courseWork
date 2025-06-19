import numpy as np
import matplotlib.pyplot as plt 

A=np.loadtxt("data1.txt")
x=A[:,0]
y=A[:,1]
z=A[:,2]
plt.plot(x,y,'-b',linewidth=0.4,label='First Object')
plt.plot(x,z,'-r',linewidth=0.4,label='Second Object')
plt.xlabel('Time (s)')
plt.ylabel('Perturbation (cm)')
plt.title('Coupled Oscillators ( Perturbations from mean positions )',color='blue')
plt.legend()
plt.grid()
plt.tight_layout()
plt.savefig("plot1.png",dpi=300)
