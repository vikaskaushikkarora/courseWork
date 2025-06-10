import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("data.txt")
x=A[:,0]
y=A[:,1]
z=A[:,2]
w=A[:,3]

plt.plot(x,y,color='red',label='Parent Nuclie')
plt.plot(x,z,color='blue',label='Daughter Nuclie')
plt.plot(x,w,color='black',label='Granddaughter Nuclie')
#plt.tight_layout()
plt.legend()
plt.xlabel('Time')
plt.ylabel('Number of Nuclie')
plt.grid(lw=0.3)
plt.savefig('plot.png',dpi=300)
