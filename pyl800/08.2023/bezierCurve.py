import numpy as np
import matplotlib.pyplot as plt
import math

x=[0,1,2,1.5,3,4]
y=[0,1,0.2,1.3,9,3.2]
n=len(x)

def C(n,r):
	f=math.factorial
	return f(n)/(f(r)*f(n-r))

def Px(t,x):
	sum=0
	for i in range(n):
		sum=sum+(C(n-1,i))*((1-t)**(n-1-i))*(t**(i))*x[i]
	return sum

def Py(t,y):
	sum=0
	for i in range(n):
		sum=sum+(C(n-1,i))*((1-t)**(n-1-i))*(t**(i))*y[i]
	return sum

t=np.arange(0,1,0.005)
px=Px(t,x)
py=Py(t,y)

plt.plot(px,py)
plt.grid()
plt.plot(x,y,'*r-',linewidth=0.5)
plt.show()
