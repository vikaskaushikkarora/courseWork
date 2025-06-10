from numpy import *
import matplotlib.pyplot as plt

D=loadtxt("a.dat")
X=D[:,0]
Y=D[:,1]
n=len(X)

s=500 # speed of animation
for i in range(int(n/s)):
    plt.plot(0,0,'ro',markersize=10)
    plt.plot(X[0:s*i],Y[0:s*i])
    plt.plot(X[s*i],Y[s*i],'ko')
    plt.title("Mercury Precession")
    plt.grid()
    plt.pause(0.1)
    plt.clf()

plt.show()
