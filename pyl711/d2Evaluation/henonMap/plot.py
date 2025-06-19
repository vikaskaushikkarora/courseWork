import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit


A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
B=A[:,0]
C=A[:,1]
n=len(C)
plt.plot(B,C,'k*',markersize=0.8)
plt.xscale("log")
plt.yscale("log")

def test(x,a,b):
	return a*(x**b)

param,param_cov = curve_fit(test,B[200:int(0.5*n)],C[200:int(0.5*n)])
b=param[1]
print("The correlation dimension is : ",b)
plt.show()

'''
A1=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
x=A1[:,0]
n=len(A1)
y=A1[:,1]
plt.plot(x,y,'k*',markersize=0.5)
plt.show()
'''
