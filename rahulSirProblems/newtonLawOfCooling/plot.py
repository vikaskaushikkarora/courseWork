from numpy import *
import matplotlib.pyplot as plt

D=loadtxt("a.dat")

time=D[:,0]/60
plt.plot(time,D[:,1],label='Temp Normal')
plt.plot(time,D[:,2],label="Temp Newton's Law")

plt.xlabel("Time (in minutes)")
plt.ylabel("Temperature (in Kelvin)")
plt.title("Newton's Law Of Cooling vs Cooling Without Approximation")
plt.legend()
#plt.grid()
plt.savefig("result.pdf",dpi=300)
