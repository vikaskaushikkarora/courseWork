import numpy as np
import matplotlib.pyplot as plt

a=1
b=1
m1=1
m2=1

def fx1(t,x1,x2,vx1,vx2):
	return vx1

def fvx1(t,x1,x2,vx1,vx2):
	return -((a+b)/m1)*x1+(b/m1)*x2

def fx2(t,x1,x2,vx1,vx2):
	return vx2

def fvx2(t,x1,x2,vx1,vx2):
	return -(b/m2)*x2

n=50000	
t=np.linspace(0,50,n)
h=t[1]-t[0]
x1=np.zeros(n)
vx1=np.zeros(n)
x2=np.zeros(n)
vx2=np.zeros(n)

x1[0]=0.5
vx1[0]=1
x2[0]=0.1
vx2[0]=-0.3

for i in range(n-1):
	k1=fx1(t[i],x1[i],x2[i],vx1[i],vx2[i])
	l1=fvx1(t[i],x1[i],x2[i],vx1[i],vx2[i])
	q1=fx2(t[i],x1[i],x2[i],vx1[i],vx2[i])
	r1=fvx2(t[i],x1[i],x2[i],vx1[i],vx2[i])
	
	k2=fx1(t[i],x1[i]+0.5*h*k1,x2[i]+0.5*h*q1,vx1[i]+0.5*h*l1,vx2[i]+0.5*h*r1)
	l2=fvx1(t[i],x1[i]+0.5*h*k1,x2[i]+0.5*h*q1,vx1[i]+0.5*h*l1,vx2[i]+0.5*h*r1)
	q2=fx2(t[i],x1[i]+0.5*h*k1,x2[i]+0.5*h*q1,vx1[i]+0.5*h*l1,vx2[i]+0.5*h*r1)
	r2=fvx2(t[i],x1[i]+0.5*h*k1,x2[i]+0.5*h*q1,vx1[i]+0.5*h*l1,vx2[i]+0.5*h*r1)
	
	k3=fx1(t[i],x1[i]+0.5*h*k2,x2[i]+0.5*h*q2,vx1[i]+0.5*h*l2,vx2[i]+0.5*h*r2)
	l3=fvx1(t[i],x1[i]+0.5*h*k2,x2[i]+0.5*h*q2,vx1[i]+0.5*h*l2,vx2[i]+0.5*h*r2)
	q3=fx2(t[i],x1[i]+0.5*h*k2,x2[i]+0.5*h*q2,vx1[i]+0.5*h*l2,vx2[i]+0.5*h*r2)
	r3=fvx2(t[i],x1[i]+0.5*h*k2,x2[i]+0.5*h*q2,vx1[i]+0.5*h*l2,vx2[i]+0.5*h*r2)
	
	k4=fx1(t[i],x1[i]+h*k3,x2[i]+h*q3,vx1[i]+h*l3,vx2[i]+h*r3)
	l4=fvx1(t[i],x1[i]+h*k3,x2[i]+h*q3,vx1[i]+h*l3,vx2[i]+h*r3)
	q4=fx2(t[i],x1[i]+h*k3,x2[i]+h*q3,vx1[i]+h*l3,vx2[i]+h*r3)
	r4=fvx2(t[i],x1[i]+h*k3,x2[i]+h*q3,vx1[i]+h*l3,vx2[i]+h*r3)
	
	x1[i+1]=x1[i]+h*(k1+2*k2+2*k3+k4)/6
	x2[i+1]=x2[i]+h*(q1+2*q2+2*q3+q4)/6
	vx1[i+1]=vx1[i]+h*(l1+2*l2+2*l3+l4)/6
	vx2[i+1]=vx2[i]+h*(r1+2*r2+2*r3+r4)/6

#'''
plt.plot(t,x1,'-k')
plt.plot(t,x2,'-r')
plt.legend(['m1','m2'])
plt.grid()
plt.show()
'''
s=250 #speed of animation
L1=10
L2=10
for i in range(int(n/s)):
	plt.plot([0,L1+x1[s*i]],[0,0],'r-')
	plt.plot([L1+x1[s*i],L1+L2+x2[s*i]],[0,0],'b-')
	plt.plot(L1+x1[s*i],0,'ro',markersize=20)
	plt.plot(L1+L2+x2[s*i],0,'bo',markersize=20)
	plt.legend(['m1','m2'])
	plt.xlim(0,30)
	plt.ylim(-0.5,0.5)
	plt.pause(0.01)
	plt.clf()
plt.show()
'''
