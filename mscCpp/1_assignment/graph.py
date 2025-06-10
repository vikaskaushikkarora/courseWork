import numpy as np 
import matplotlib.pyplot as plt 

A=np.loadtxt("data.txt")
x=A[:,0]
y=A[:,1]
z=A[:,2]
plt.plot(x,y,'b',label='Charge')
plt.plot(x,z,'r',label='Current')
plt.legend(loc=1,fontsize=15)
plt.xlabel('Time',size=15)
plt.grid()
plt.tight_layout()
plt.savefig('rlc-plot.png',dpi=300) # High dpi indicates the higher resolution #
