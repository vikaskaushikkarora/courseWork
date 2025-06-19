# Plotting the graph
import numpy as np
import matplotlib.pyplot as plt

# Importing the required data
D=np.loadtxt("data.txt")
D1=np.loadtxt("data1.txt")

def f(x):
    return 0.04+((x*x/2)-10*x+10*np.arctan(x))/1000

array=np.arange(0,25,1)
x=np.arange(-2,25,0.01)
plt.plot(x,f(x),'r-',label="Potential")
plt.hist(D1,bins=array,density=True)
plt.xlabel("Protein Number")
plt.title("Probability Distribution Over all Ensembles")
plt.legend()
plt.savefig("q2.pdf",dpi=300)
