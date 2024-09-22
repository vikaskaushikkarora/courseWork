import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
x=A[:,0]
y=A[:,1]
B=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
n=int(B[0])
mx=int(B[1])
mvx=int(B[2])

fig = plt.figure()
ax = plt.axes()

for j in range(mx):
	for k in range(mvx):
		ax.plot(x[j*n*mvx+k*n:j*n*mvx+(k+1)*n],y[j*n*mvx+k*n:j*n*mvx+(k+1)*n],'-r')

ax.set_xlim(-6,6)
ax.set_ylim(-6,6)
ax.set_title('For positive $\mu$, attracted towards the limit cycle')
ax.grid()
plt.show()

