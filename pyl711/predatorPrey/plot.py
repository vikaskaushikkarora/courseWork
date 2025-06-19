import numpy as np
import matplotlib.pyplot as plt

A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
x=A[:,0]
y=A[:,1]
B=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
n=int(B[0])
mx=int(B[1])
my=int(B[2])

fig = plt.figure()
ax = plt.axes()

for j in range(mx):
	for k in range(my):
		ax.plot(x[j*n*my+k*n:j*n*my+(k+1)*n],y[j*n*my+k*n:j*n*my+(k+1)*n],'-r')

ax.set_xlim(-0.5,8)
ax.set_ylim(-0.5,8)
ax.grid()
plt.show()

