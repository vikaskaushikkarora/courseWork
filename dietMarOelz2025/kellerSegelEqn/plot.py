import numpy as np
import matplotlib.pyplot as plt

#Load data about x,y axies and number of time intervals
a=np.loadtxt("a.dat")
u=np.loadtxt("u.dat")
S=np.loadtxt("S.dat")
n=len(u[:,0])
x=np.linspace(a[0,0],a[0,1],int(a[0,2]))

fig,ax = plt.subplots()
ax.plot(x,u[0,:],'k-',label='begining u')
ax.plot(x,S[0,:],'b--',label='begining S')
ax.plot(x,u[1000,:],'r-',label='final u')
ax.plot(x,S[1000,:],'b-',label='final S')

#ax.set_xlim(0,10)
#ax.set_ylim(-2,22)
ax.legend()

plt.savefig("/sdcard/Pictures/image.pdf",dpi=300)

