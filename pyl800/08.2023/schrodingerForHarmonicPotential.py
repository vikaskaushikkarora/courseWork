import numpy as np
import matplotlib.pyplot as plt

h=1
m=1
k=1
#h=1.05e-34 #reduced plank constant
#m=9.1e-31 #mass of electron

w=np.sqrt(k/m)
x0=5*np.sqrt(2*h/(m*w)) #parameter for range of x-axis
groundStateEnergy=0.5*h*w #ground state energy

x=np.linspace(-x0,x0,500)
n=len(x)
dx=x[1]-x[0]
N=n-2
D=np.zeros((N,N)) #matrix for d/dx
V=np.zeros((N,N)) #diagonal matrix for potential

#defining D and V Matrices
for i in range(1,N-1):
	D[i,i]=-2
	D[i,i-1]=1
	D[i,i+1]=1
	V[i,i]=0.5*k*x[i+1]*x[i+1]

V[0,0]=0.5*k*x[1]*x[1]
V[N-1,N-1]=0.5*k*x[N]*x[N]
D[0,1]=1
D[0,0]=-2
D[N-1,N-1]=-2
D[N-1,N-2]=1

#matrix for Hamiltonian
H=-(h*h/(2*m))*(dx**(-2))*D+V
a,B=np.linalg.eig(H) #inbuilt python command for eignvalues a and eignvectors B
z=x[1:N+1]

#getting energy and wavefunction for for reqd levels
for j in range(2):
	val=0
	energy=a[0]
	psi=np.zeros(N)
	for i in range(1,N):
		if(a[i]<energy):
			val=i
			energy=a[val]
	psi=B[:,val]
	print("Theoretical Energy for n = ",j," is : ",(2*j+1)*groundStateEnergy)
	print("Calculated Energy for n = ",j," is : ",energy)
	string="Energy n = "+str(j)
	plt.plot(z,psi,label=string)
	a=np.delete(a,val)
	B=np.delete(B,val,axis=1)
	N=len(a)

plt.grid()
plt.legend()
plt.show()

