import numpy as np
import matplotlib.pyplot as plt

x=[0,1,2.5,4.5]
n=len(x)
h=x[1]-x[0]
y=[0,1,-2,3]
P=np.zeros((n,n))
P[:,0]=y[0:n]

def interpolation(z,x,P,n):
	sum=0
	for i in range(n):
		product=1
		for j in range(i):
			product=product*(z-x[j])
		sum=sum+P[0,i]*product
	return sum

for j in range(1,n):
	for i in range(n-j):
		P[i,j]=(P[i+1,j-1]-P[i,j-1])/(x[i+j]-x[i])

z=np.arange(x[0]-0.1,x[n-1]+0.1,0.01)
nz=len(z)
interpolated=np.zeros(nz)
for i in range(nz):
	interpolated[i]=interpolation(z[i],x,P,n)
plt.plot(z,interpolated,'k-',label='Original')
plt.plot(x,y,'*r')

#===============================================================

#Leave 1st point
x=[0,1,2.5]
n=len(x)
h=x[1]-x[0]
y=[0,1,-2]
P=np.zeros((n,n))
P[:,0]=y[0:n]

def interpolation(z,x,P,n):
	sum=0
	for i in range(n):
		product=1
		for j in range(i):
			product=product*(z-x[j])
		sum=sum+P[0,i]*product
	return sum

for j in range(1,n):
	for i in range(n-j):
		P[i,j]=(P[i+1,j-1]-P[i,j-1])/(x[i+j]-x[i])
		
z1=np.arange(x[0]-0.1,x[n-1]+0.1,0.01)
nz1=len(z1)
interpolated1=np.zeros(nz1)
for i in range(nz1):
	interpolated1[i]=interpolation(z1[i],x,P,n)
plt.plot(z1,interpolated1,'b-',label='Leaving 1st point')
plt.plot(x,y,'*r')

#==========================================================

#Leave Last point
x=[1,2.5,4.5]
n=len(x)
h=x[1]-x[0]
y=[1,-2,3]
P=np.zeros((n,n))
P[:,0]=y[0:n]

def interpolation(z,x,P,n):
	sum=0
	for i in range(n):
		product=1
		for j in range(i):
			product=product*(z-x[j])
		sum=sum+P[0,i]*product
	return sum

for j in range(1,n):
	for i in range(n-j):
		P[i,j]=(P[i+1,j-1]-P[i,j-1])/(x[i+j]-x[i])
		
z2=np.arange(x[0]-0.1,x[n-1]+0.1,0.01)
nz2=len(z2)
interpolated2=np.zeros(nz2)
for i in range(nz2):
	interpolated2[i]=interpolation(z2[i],x,P,n)
plt.plot(z2,interpolated2,'g-',label='Leaving Last point')
plt.plot(x,y,'*r')


plt.legend()
plt.grid()
plt.show()
