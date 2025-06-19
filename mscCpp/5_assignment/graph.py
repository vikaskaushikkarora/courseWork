import numpy as np
import matplotlib.pyplot as plt

R=6371000

fig=plt.figure()
ax=plt.axes([0,0,1,1])

def fill_circle(R,a,b):
	X=np.linspace(a-R,a+R,1000)
	Y=b+(R**2-(X-a)**2)**0.5
	Z=b-(R**2-(X-a)**2)**0.5
	ax.fill_between(X,Y,Z,color='skyblue')
	ax.text(0,0,"EARTH",color='black',ha="center",va="center")

fill_circle(R,0,0)

def circle(R,a,b):
	X=np.linspace(a-R,a+R,1000)
	Y=b+(R**2-(X-a)**2)**0.5
	Z=b-(R**2-(X-a)**2)**0.5
	ax.plot(X,Y,color='white',linewidth=0.8,label="Satellite Orbit")
	ax.plot(X,Z,color='white',linewidth=0.8)

A=np.loadtxt("data.txt")
x=A[0:-1,1]
y=A[0:-1,2]
Rr=A[-1,0]
xf=A[-2,1]
yf=A[-2,2]
circle(Rr,0,0)
ax.plot(x,y,'-',color='lightcoral',linewidth=0.8,label="Launch Trajectory")
ax.plot(xf,yf,'or',markersize=3)
ax.axis("equal")
#ax.set_xticks([])
#ax.set_yticks([])
ax.set_facecolor('black')
ax.legend(loc=0)
ax.grid(linestyle='dotted',linewidth=0.15,color='lightyellow')
plt.savefig("plot.png",dpi=500)
