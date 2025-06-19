import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

'''
A=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
x=A[:,0]
y=A[:,1]
z=A[:,2]

fig=plt.figure()
ax=plt.axes(projection='3d')
ax.plot3D(x,y,z,'k*',linewidth=0.3)
plt.show()
'''

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
B=A[:,0]
C=A[:,1]
n=len(B)
for i in range(10):
	plt.plot(B[10*i:10*(i+1)],C[10*i:10*(i+1)],'*',markersize=2)

plt.xscale("log")
plt.yscale("log")

def test(x,a,b):
	return a*(x**b)

param,param_cov = curve_fit(test,B[10:40],C[10:40])
b=param[1]

string="The correlation dimension is :\n "+str(b)
plt.text(1,1,string,bbox=dict(facecolor='red',alpha=0.5))
plt.grid()
plt.savefig("/home/vikas/Downloads/fig2.png",dpi=300)
plt.show()

