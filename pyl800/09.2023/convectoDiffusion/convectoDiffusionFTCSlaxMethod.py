import numpy as np
from numpy import pi,exp,sqrt
import matplotlib.pyplot as plt

v=0.5
D=0.1
s=0.1
t=np.linspace(0,1,8000)
x=np.linspace(-1,1,200)

n=len(t)
m=len(x)
dt=t[1]-t[0]
dx=x[1]-x[0]

u=np.zeros((n,m),dtype=float)
#initial condition
u[0,:]=((2*pi*s*s)**(-0.5))*exp(-((x+0.2)**2)/(2*s*s))
#boundary condition
u[:,0]=0
u[:,m-1]=0

for i in range(n-1):
	for j in range(1,m-1):
		u[i+1,j]=0.5*(u[i,j+1]+u[i,j-1])-0.5*v*(dt/dx)*(u[i,j+1]-u[i,j-1])+D*(dt/(dx*dx))*(u[i,j+1]+u[i,j-1]-2*u[i,j])

s=50
for i in range(int(n/s)):
	plt.plot(x,u[s*i,:],'r-')
	plt.xlim(-1,1)
	plt.ylim(0,4.5)
	plt.grid()
	plt.pause(0.01)
	plt.clf()

plt.show()
