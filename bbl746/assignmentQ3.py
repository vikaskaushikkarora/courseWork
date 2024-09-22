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

alphaR=np.zeros(n,dtype=float)
alphaR[0]=((F[0]/R[0])**2)/(1+(F[0]/R[0])**2)
alphaP=1-alphaR

#parameters
tauR=4
tauP=2
tauF=1/120
tauAA=1/120

def fR(R,P,F,alphaR):
	return alphaR*min(1,F/R)*R/tauR

def fP(R,P,F,alphaP):
	return alphaP*min(1,F/R)*R/tauP

def fF(R,P,F):
	return (P/tauF)-(min(1,F/R)*R/tauAA)
	
for i in range(n-1):
	R[i+1]=R[i]+dt*fR(R[i],P[i],F[i],alphaR[i])
	P[i+1]=P[i]+dt*fP(R[i],P[i],F[i],alphaP[i])
	F[i+1]=F[i]+dt*fF(R[i],P[i],F[i])
	alphaR[i+1]=((F[i+1]/R[i+1])**2)/(1+(F[i+1]/R[i+1])**2)
	alphaP[i+1]=1-alphaR[i+1]

plt.plot(t,alphaR)
plt.title(r"$\alpha_{R}$ versus Time")
plt.ylabel(r"$\alpha_{R}$")
plt.xlabel("Time")
plt.grid()
#plt.savefig("/home/vikas/Desktop/work/fig3.png",dpi=500)
plt.show()
