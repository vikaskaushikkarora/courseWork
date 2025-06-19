import numpy as np
import matplotlib.pyplot as plt
from numpy import pi,exp,sqrt

A=np.loadtxt("/home/vikas/work/data.txt")
Nd=A[0,:]
d=len(Nd)-1
N=int(Nd[0])

mean0=4.5
variance0=5.25
mean=d*mean0
variance=d*variance0
std=sqrt(variance)

def f(x):
    return ((2*pi*variance)**(-0.5))*exp(-1*((x-mean)**2)*((2*variance)**(-1)))

C=np.arange(mean-4*std,mean+4*std,1)
sum=A[1:N+1,d]
string="The number of dice is : "+str(d)

plt.plot(C,f(C),label="Theoretical Prediction")
plt.hist(sum,bins=C,density=True)
plt.xlabel("Sum of the number appearing on the faces")
plt.ylabel("Probability Density")
plt.title(string)
plt.grid()
plt.legend()
plt.savefig("/sdcard/plot.png",dpi=300)
