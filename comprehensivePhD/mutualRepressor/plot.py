# Plotting the graph
import numpy as np
import matplotlib.pyplot as plt

# Importing the required data
D=np.loadtxt("data.txt")
D1=np.loadtxt("data1.txt")

array=np.arange(0,100,1)
plt.title("X protein distribution for different times")
plt.hist(D[:,0],bins=array,density=True,label="Initial 500 steps")
plt.hist(D1[:,0],bins=array,density=True,label="Next 500 steps")
plt.legend()
plt.savefig("q4.pdf",dpi=300)
