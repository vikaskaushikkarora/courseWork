import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import fsolve

def f(x,v):
	return 1-((x-v)**(-2)+(x+v)**(-2))
	
n=2000
for i in range(n):
	v=-10+20*(i/n)
	x=fsolve(f,[-10,-5,-1,1,5,10],v)
	z=np.ones(6)*v
	plt.plot(z,x,'ro',markersize=2)

plt.ylim(-10,10)
plt.grid()
plt.show()

