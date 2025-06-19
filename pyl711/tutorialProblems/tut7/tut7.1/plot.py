import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
t=A[:,0]
x=A[:,1]
y=A[:,2]
z=A[:,3]

fig=plt.figure()
ax=plt.axes(projection='3d')
ax.plot3D(x,y,z,'k-',linewidth=0.3)
plt.savefig("/home/vikas/Desktop/Downloads/fig.png",dpi=300)
plt.show()
