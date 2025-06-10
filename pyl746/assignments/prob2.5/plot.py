# Persistent Random Walk : Animation

import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/work/data.txt") # Load the data
n=len(A[:,0])
C=np.linspace(-n,n,2*n) # bin for the histogram

# Animation
s=10 # speed of the animation
for i in range(int(n/s)):
	plt.hist(A[s*i,:],bins=C,density=True)
	#plt.ylim(-0.01,0.25)
	string="Random Walk With Memory at time = "+str(round((s*i*0.01),2))
	plt.title(string)
	plt.grid()
	plt.pause(0.1)
	plt.clf()
	
plt.show()
