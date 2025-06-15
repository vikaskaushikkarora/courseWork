import numpy as np
import matplotlib.pyplot as plt

x=np.linspace(0,1,100)
y=np.linspace(0,1,100)
mx=len(x)
my=len(y)

phi=np.zeros((mx,my),dtype=float)
phi[0,:]=1


