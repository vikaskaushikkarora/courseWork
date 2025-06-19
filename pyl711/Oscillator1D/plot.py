import numpy as np
import matplotlib.pyplot as plt
import os

A=np.loadtxt("data.txt")
x=A[:,0]
y=A[:,1]
B=np.loadtxt("dataextra.txt")
n=int(B[0])
m=int(B[1])
l=int(B[2])

fig = plt.figure()
ax = plt.axes()
'''ax.set_facecolor('black')
ax.set_xticks([])
ax.set_yticks([])
'''

for j in range(m):
	for k in range(l):
		ax.plot(x[j*n*l+k*n:j*n*l+(k+1)*n],y[j*n*l+k*n:j*n*l+(k+1)*n],'-r')

ax.set_xlim(-15,15)
ax.set_ylim(-3,3)
ax.grid()
plt.show()

