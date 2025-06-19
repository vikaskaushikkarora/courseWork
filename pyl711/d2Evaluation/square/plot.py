import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
B=A[:,0]
C=A[:,1]
n=len(B)

for i in range(10):
	plt.plot(B[int(i*n/10):int((i+1)*n/10)],C[int(i*n/10):int((i+1)*n/10)],'-')
	
plt.xscale("log")
plt.yscale("log")

def test(x,a,b):
	return a*(x**b)

param,param_cov = curve_fit(test,B[int(n/10):n],C[int(n/10):n])
b=param[1]
print("The correlation dimension is : ",b)
plt.show()

