import numpy as np 
import matplotlib.pyplot as plt 

A=np.loadtxt("data0.txt")
x=A[:,0]
y=A[:,1]
z=A[:,2]
#plt.plot(x,y,'b',label='Distance of the ball from the surface')
plt.plot(x,y,'k',label='Distance of the ball (in m)')
plt.plot(x,z,'r',label='Speed of the ball (in m/s)')
plt.legend(loc=0,fontsize=10)
plt.xlabel('Time (s)',size=10)
#plt.ylim(0,1500)
plt.grid()
plt.title('Ball Falling Through A Viscous Medium',color='blue')
plt.tight_layout()
plt.savefig('viscousMedium.png',dpi=200) # High dpi indicates the higher resolution #
