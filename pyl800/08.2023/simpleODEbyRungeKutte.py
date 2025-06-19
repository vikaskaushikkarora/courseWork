import numpy as np
import matplotlib.pyplot as plt

k=1
gamma=0.3

def f(t,x):
	return -2*t*x*x

def g(h,x0):
	t=np.arange(0,10,h)
	n=len(t)
	x=np.zeros(n)
	x[0]=x0
	for i in range(n-1):
		k1=f(t[i],x[i])
		k2=f(t[i]+0.5*h,x[i]+0.5*h*k1)
		k3=f(t[i]+0.5*h,x[i]+0.5*h*k2)
		k4=f(t[i]+h,x[i]+h*k3)
		x[i+1]=x[i]+h*(k1+2*k2+2*k3+k4)/6
	plt.plot(t,x)

g(0.2,10)
g(0.02,10)

plt.grid()
plt.show()
