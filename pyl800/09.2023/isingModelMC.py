import numpy as np
import matplotlib.pyplot as plt

m=200
n=m*m
J=1 #Interaction
b=10000 #1/KT

A1=np.random.randint(2,size=(n))
A=(-1)**A1

energy=0
for i in range(n):
	energy=energy-J*A[i]*A[i-1]-J*A[i]*A[(i+1)%n]-J*A[i]*A[i-m]-J*A[i]*A[(i+m)%n]
energy=energy/2

N=500000
for j in range(N):
	r=np.random.randint(n)
	energy0=-J*A[r]/A[r-1]-J*A[r]*A[(r+1)%n]-J*A[r]*A[r-m]-J*A[r]*A[(r+m)%n]

	if(A[r]==-1):
		A[r]=1
	else:
		A[r]=-1

	energy1=-J*A[r]*A[r-1]-J*A[r]*A[(r+1)%n]-J*A[r]*A[r-m]-J*A[r]*A[(r+m)%n]
	energy10=energy1-energy0
	energy=energy+energy10

	if(energy10>0):
		p=np.exp(-energy10*b)
		p1=np.random.random(1)
		if(p1>p):
			energy=energy-energy10
			if(A[r]==-1):
				A[r]=1
			else:
				A[r]=-1			
	
	#print((j/N)*100)
	'''	
	B=A.copy()
	B.shape=(B.size//m,m)
	string="Energy is : "+str(energy)
	plt.title(string)
	plt.imshow(B)
	plt.pause(0.001)
	plt.clf()
	'''

B=A.copy()
B.shape=(B.size//m,m)
string="Energy is : "+str(energy)
plt.title(string)
plt.imshow(B)
plt.show()

