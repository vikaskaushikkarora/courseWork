import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/work/data.txt")
B=A[0,:]
m=int(len(B)/4) # 4 is the species number plus 1 for time

for i in range(m):
	plt.plot(A[:,4*i],A[:,4*i+3]) # use 4*i+1 or 4*i+2 for A and B species

plt.grid()
plt.show()
