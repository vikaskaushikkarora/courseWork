import numpy as np
import matplotlib.pyplot as plt

N=1000000
# Create N random numbers between -1 and 1 uniformly
ax=np.random.randint(10000,size=(N))
bx=np.random.rand(N)
x=((-1)**(ax))*bx # x-coordinate
ay=np.random.randint(10000,size=(N))
by=np.random.rand(N)
y=((-1)**(ay))*by # y-coordinate
R=x*x+y*y # Distance from origin

#Count how many of the points are inside the circle
def f(x):
	count=0
	for i in range(x):
		if(R[i]<=1):
			count=count+1
	return 4*count/x

n=np.linspace(100,N,100,dtype=int)
ln=len(n)
m=np.zeros(ln)
for i in range(ln):
	m[i]=f(n[i])

PI=np.pi*np.ones(ln)
plt.plot(n,PI,'r-')
plt.plot(n,m,'k-')
plt.grid()
plt.show()

