import numpy as np
import matplotlib.pyplot as plt

#Load data about x,y axies and number of time intervals
a=np.loadtxt("a.dat")
u=np.loadtxt("u.dat")
n=len(u[:,0])
x=np.linspace(a[0,0],a[0,1],int(a[0,2]))

fig,ax = plt.subplots()
ax.plot(x,u[0,:],'k-',label='begining')
ax.plot(x,u[1500,:],'r-',label='end')

ax.set_xlim(-20,20)
ax.set_ylim(-2,1100)
ax.legend()

plt.show()

