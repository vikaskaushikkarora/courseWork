import numpy as np
import matplotlib.pyplot as plt

A=np.array([[2,1,-1],[-3,-1,2],[-2,1,2]],dtype=float)
n=len(A[0,:])
B=np.array([8,-11,-3],dtype=float)

A0=A.copy()
B0=B.copy()

# Gauss Elimination Method with partial pivoting
for j in range(n-1):
	#Partial Pivoting
	temp=j
	for k in range(j,n):
		if(abs(A[k,j])>abs(A[temp,j])):
			temp=k
			
	temprow=A[j,:].copy()
	A[j,:]=A[temp,:]
	A[temp,:]=temprow
	tempelement=B[j].copy()
	B[j]=B[temp]
	B[temp]=tempelement
	#Elimination
	for i in range(j,n-1):
		B[i+1]=B[i+1]-(A[i+1,j]/A[j,j])*B[j]
		A[i+1,:]=A[i+1,:]-(A[i+1,j]/A[j,j])*A[j,:]
	
B[n-1]=B[n-1]/A[n-1,n-1]	
A[n-1,:]=A[n-1,:]/A[n-1,n-1]

#Backwards Substitution Method
x=np.zeros(n)
for i in range(n):
	val=B[n-1-i]
	for j in range(i):
		val=val-A[n-1-i,n-1-j]*x[n-1-j]
	x[n-1-i]=val/A[n-1-i,n-1-i]

print("The solution vector x is : ",x)

#Let's check wether our solution is right or not
print("Ax is : ",np.dot(A0,x))
print("B is : ",B0)

