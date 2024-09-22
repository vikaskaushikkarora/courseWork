# Plotting the data

# Import libraries
import numpy as np
import matplotlib.pyplot as plt

# Import data
D=np.loadtxt("/home/vikas/work/data.txt")
t=D[:,0]
P=D[:,1]

# Plotting the data
plt.plot(t,P)

# Annotation
plt.xlabel("Time")
plt.ylabel("Concentration of P")
plt.title("Deterministic Autoactivator System")
plt.grid()
#plt.show()
plt.savefig("plot.png",dpi=500)
