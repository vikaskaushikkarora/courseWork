import numpy as np
import matplotlib.pyplot as plt

A=np.array([[16,3],[7,-11]],dtype=float)
n=len(A[0,:])
B=np.array([11,13],dtype=float)

x=np.array([1,1],dtype=float)
m=10 #number of iterations


for i in range(n):
	if (A[i,i]==0 and i<n-1):
		tempArray=A[i,:].copy()
		A[i,:]=A[i+1,:]
		A[i+1,:]=tempArray
	elif (A[i,i]==0 and i==n-1):
		tempArray=A[i,:].copy()
		A[i,:]=A[0,:]
		A[0,:]=tempArray

for i in range(m):
	for j in range(n):
		sum=0
		for k in range(n):
			if k!=j:
				sum=sum+A[j,k]*x[k]
				#print(sum)
		x[j]=(B[j]-sum)/(A[j,j])

	print("x is : ",x)

