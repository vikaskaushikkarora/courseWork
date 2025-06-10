# Zeros for volume in Van Der Walls Equation for various regimes
# Import libraries
from numpy import *
import matplotlib.pyplot as plt

p=0.02 # pressure
b=1 # van der Walls coefficient
a=1 # van der Walls coefficient
K=1 # boltzmann constant
T=0.4 # Temperature , critical temperature is 0.297

# Van der Waals Equation of state 
def f(v):
    return p*v**(3)-(p*b+K*T)*v**(2)+a*v-a*b

v=linspace(0,20,100000)
plt.plot(v,f(v),label=r"y=p$x^{3}$-(pb+KT)$x^{2}$+ax-ab")
plt.grid('.')
plt.legend()
plt.xlabel("Volume")
plt.title(r"p=0.01, T=0.4, a=1, b=1, K=1, $T_c=0.297$")
plt.tight_layout()
plt.savefig("TaboveTc.pdf",dpi=500)
