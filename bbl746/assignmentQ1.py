import numpy as np
import matplotlib.pyplot as plt

dt=0.005
t=np.arange(0,100,dt)
n=len(t)

R=np.zeros(n,dtype=float)
P=np.zeros(n,dtype=float)
F=np.zeros(n,dtype=float)

R[0]=1
P[0]=1
F[0]=10

#control parameters
alphaR=0.75
alphaP=1-alphaR
tauR=4
tauP=2
tauF=1/120
tauAA=1/120

def fR(R,P,F):
	return alphaR*min(1,F/R)*R/tauR

def fP(R,P,F):
	return alphaP*min(1,F/R)*R/tauP

def fF(R,P,F):
	return (P/tauF)-(min(1,F/R)*R/tauAA)

for i in range(n-1):
	R[i+1]=R[i]+dt*fR(R[i],P[i],F[i])
	P[i+1]=P[i]+dt*fP(R[i],P[i],F[i])
	F[i+1]=F[i]+dt*fF(R[i],P[i],F[i])

plt.plot(t,R,label='R')
plt.plot(t,P,label='P')
plt.plot(t,F,label='F')
plt.yscale("log")
plt.title("Abundance versus Time (log scale)")
plt.xlabel("Time")
plt.ylabel("Abundance of a specific protein")
plt.legend()
plt.grid()
#plt.savefig("/home/vikas/Desktop/work/fig11.png",dpi=500)
plt.show()
