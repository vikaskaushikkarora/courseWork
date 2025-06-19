from numpy import *
import matplotlib.pyplot as plt

D=loadtxt("data/a.dat")
plt.plot(D[:,0],D[:,1],label="Temperature : 30 K")
plt.xlabel("Pressure (P)")
plt.ylabel(r"Chemical Potential ($\mu$)")
plt.title(r"Relationship between $\mu$ and P for Hydrogen")
plt.legend(loc="lower right")
plt.savefig("muVersusP.pdf",dpi=500)
