import numpy as np
import matplotlib.pyplot as plt

x=np.linspace(-1,1,5)
y=(1+np.exp(-5*x))**(-1)
n=len(x)

A=np.zeros((3*n-4,3*n-4))
B=np.zeros(3*n-4)

B[0]=y[0]
for i in range(1,2*(n-1)):
	if(i%2==0):
		B[i]=y[int(i/2)]
	else:
		B[i]=y[int((i+1)/2)]

A[0,0]=x[0]*x[0]
A[0,1]=x[0]
A[1,0]=x[1]*x[1]
A[1,1]=x[1]

for i in range(2,2*(n-1)):
	if(i%2==0):
		a=int(i/2)
		A[i,int(2+3*((i/2)-1))]=x[a]*x[a]
		A[i,int(2+3*((i/2)-1)+1)]=x[a]
		A[i,int(2+3*((i/2)-1)+2)]=1
	else:
		a=int((i+1)/2)
		A[i,int(2+3*((i-3)/2))]=x[a]*x[a]
		A[i,int(2+3*((i-3)/2)+1)]=x[a]
		A[i,int(2+3*((i-3)/2)+2)]=1

A[2*(n-1),0]=2*x[1]
A[2*(n-1),1]=1
A[2*(n-1),2]=-2*x[1]
A[2*(n-1),3]=-1

for i in range(2*(n-1)+1,3*n-4):
	A[i,int(2+3*(i-2*(n-1)-1))]=2*x[i-2*(n-1)+1]
	A[i,int(2+3*(i-2*(n-1)-1)+1)]=1
	A[i,int(2+3*(i-2*(n-1)-1)+2)]=0
	A[i,int(2+3*(i-2*(n-1)-1)+3)]=-2*x[i-2*(n-1)+1]
	A[i,int(2+3*(i-2*(n-1)-1)+4)]=-1
	A[i,int(2+3*(i-2*(n-1)-1)+5)]=0


invA=np.linalg.inv(A)
X=np.dot(invA,B)

#print(B)
#print(A)
#print(X)

a=np.zeros(n-1)
b=np.zeros(n-1)
c=np.zeros(n-1)

a[0]=X[0]
b[0]=X[1]
c[0]=0

for i in range(1,n-1):
	a[i]=X[2+(i-1)*3]
	b[i]=X[3+(i-1)*3]
	c[i]=X[4+(i-1)*3]
	
#print(a)
#print(b)
#print(c)

plt.plot(x,y,'r*')

def spline(x,a,b,c):
	return a*x*x+b*x+c
for i in range(n-1):
	xplot=np.linspace(x[i],x[i+1],100)
	yplot=spline(xplot,a[i],b[i],c[i])
	plt.plot(xplot,yplot)

plt.grid()
plt.show()

