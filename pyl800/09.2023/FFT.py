from cmath import *
import matplotlib.pyplot as plt
import numpy as np
from numpy import exp,log2,pi,sin,cos

n=32
m=int(log2(n))
j=1j
t=np.linspace(0,4*pi,n)
a=sin(t)

def bitreverse(i,n):
	return int(format(i,'0%db'%n)[::-1],2)

A=np.zeros((n,m+1),dtype=float)
B=np.zeros((n,m+1),dtype=float)
C=A+1j*B

w=np.zeros(n,dtype=complex)
for i in range(n):
	w[i]=exp(2*pi*i*j/n)

for i in range(n):
	C[i,0]=a[bitreverse(i,m)]
	
for j in range(1,m+1):
	for i in range(n):	
		C[i,j]=w[int(i%(2**(m-j)))]*C[int((2**j)*int(i/(2**j))+i%(2**(j-1))+2**(j-1)),j-1]+C[int((2**j)*int(i/(2**j))+i%(2**(j-1))),j-1]

print(C[:,m])
