import numpy as np
import matplotlib.pyplot as plt

k=1
gamma=1.3

def fx(t,x,vx):
	return vx;

def fvx(t,x,vx):
	return -gamma*vx-k*x

n=10000	
t=np.linspace(0,10,n)
h=t[1]-t[0]
x=np.zeros(n)
vx=np.zeros(n)
x[0]=0
vx[0]=1

for i in range(n-1):
	k1=fx(t[i],x[i],vx[i])
	l1=fvx(t[i],x[i],vx[i])
	k2=fx(t[i],x[i]+0.5*h*k1,vx[i]+0.5*h*l1)
	l2=fvx(t[i],x[i]+0.5*h*k1,vx[i]+0.5*h*l1)
	k3=fx(t[i],x[i]+0.5*h*k2,vx[i]+0.5*h*l2)
	l3=fvx(t[i],x[i]+0.5*h*k2,vx[i]+0.5*h*l2)
	k4=fx(t[i],x[i]+h*k3,vx[i]+h*l3)
	l4=fvx(t[i],x[i]+h*k3,vx[i]+h*l3)
	x[i+1]=x[i]+h*(k1+2*k2+2*k3+k4)/6
	vx[i+1]=vx[i]+h*(l1+2*l2+2*l3+l4)/6

plt.plot(t,x,'-k')
plt.plot(t,vx,'-r')
plt.legend(['displacement','velocity'])
plt.grid()
plt.show()

