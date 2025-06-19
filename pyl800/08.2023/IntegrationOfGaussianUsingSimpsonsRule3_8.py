import numpy as np
import matplotlib.pyplot as plt
from numpy import pi,exp,cos,sin,log,sqrt

#define gaussian and it's derivative
def gaussian(x,s):
	return ((2*pi*s*s)**(-0.5))*exp((-x*x)/(2*s*s))

#Simpson's Rule for integration

#from -sigma to sigma
s=1
x=np.linspace(-s,s,31) #n should be 3m+1
n=len(x)
h=x[1]-x[0]
y=gaussian(x,s)

sum=y[0]+y[n-1]
for i in range(1,n-1):
	if (i%3==0):
		sum=sum+2*y[i]
	else:
		sum=sum+3*y[i]
integrate=sum*3*h/8

print("The area between -sigma to sigma is : ",integrate)

#from custom values
s=1
x0=(sqrt(2*s*s))*log(sqrt(2*pi*s*s)*0.01)
x=np.linspace(x0,-x0,31)
n=len(x)
h=x[1]-x[0]
y=gaussian(x,s)

sum=y[0]+y[n-1]
for i in range(1,n-1):
	if (i%3==0):
		sum=sum+2*y[i]
	else:
		sum=sum+3*y[i]
integrate=sum*3*h/8

print("The area between xvalues for which y becomes 0.01 is :",integrate)

'''
#Plotting
x0=np.arange(-5,5,0.01)
y0=gaussian(x0,s)
plt.plot(x0,y0)
plt.grid()
plt.show()
'''
