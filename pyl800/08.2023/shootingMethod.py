import numpy as np
import matplotlib.pyplot as plt

x=np.linspace(-5,5,1000)
n=len(x)
dx=x[1]-x[0]

psi=np.zeros(n)
phi=np.zeros(n)
psi[0]=0
phi[0]=0.01

#Schrodinger Eqn: psi'' + (y^2)*psi = E*psi
m=200
for i in range(m):
	E=-i*(0.1)
	sum=(psi[0])**2
	for j in range(0,n-1):
		psi[j+1]=psi[j]+dx*phi[j]
		phi[j+1]=phi[j]+dx*(E-x[j]*x[j])*psi[j]
		sum=sum+2*(psi[j+1])**2
	sum=sum-(psi[n-1])**2
	sum=np.sqrt(sum*dx/2)
	psi=psi/sum
	if (abs(psi[n-1])<0.01):
		print("Ground State Energy is : ",E)
		plt.plot(x,psi,linewidth=0.4)
		break
plt.grid()
plt.show()
