import numpy as np
import matplotlib.pyplot as plt

dt=0.005
t=np.arange(0,400,dt)
n=len(t)

R=np.zeros(n,dtype=float)
P=np.zeros(n,dtype=float)
F=np.zeros(n,dtype=float)

R[0]=1
P[0]=1
F[0]=10

m=100
k=np.zeros(m)
alphaR=np.linspace(0,1,m)
alphaP=1-alphaR

#parameters
tauR=4
tauP=2
tauF=1/120
tauAA=1/120

def fit(x,y):
	n=np.size(x)
	z=np.multiply(x,y)
	x_square=np.multiply(x,x)
	A=np.ones((2,2))
	A[0,0]=sum(x)
	A[0,1]=n
	A[1,0]=sum(x_square)
	A[1,1]=sum(x)
	phi=np.array([sum(y),sum(z)])
	invA=np.linalg.inv(A)
	vec=np.dot(invA,phi)
	return vec[0]

def fR(R,P,F,alphaR):
	return alphaR*min(1,F/R)*R/tauR

def fP(R,P,F,alphaP):
	return alphaP*min(1,F/R)*R/tauP

def fF(R,P,F):
	return (P/tauF)-(min(1,F/R)*R/tauAA)
	
for j in range(m):
	for i in range(n-1):
		R[i+1]=R[i]+dt*fR(R[i],P[i],F[i],alphaR[j])
		P[i+1]=P[i]+dt*fP(R[i],P[i],F[i],alphaP[j])
		F[i+1]=F[i]+dt*fF(R[i],P[i],F[i])
	k[j]=fit(t[int(3*n/4):n-1],np.log(R[int(3*n/4):n-1]))

plt.plot(alphaR,k)
plt.title(r"Growth Rate versus $\alpha_{R}$")
plt.xlabel(r"$\alpha_{R}$")
plt.ylabel("Growth Rate")
plt.grid()
#plt.savefig("/home/vikas/Desktop/work/fig2.png",dpi=500)
plt.show()
