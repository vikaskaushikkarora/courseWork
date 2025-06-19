import numpy as np
import matplotlib.pyplot as plt

# Load the NTHREADS and numEnsemble
Y=np.loadtxt("/home/vikas/work/data.txt")
NTHREADS=Y[0]
numEnsemble=Y[1]

for i in range(int(NTHREADS)):
	string="/home/vikas/work/dataFiles/data"+str(i)+".txt"
	X=np.loadtxt(string)
	for i in range(int(numEnsemble)):
		Xi=X[i,:]
		t=Xi[0::4]
		C=Xi[3::4]
		plt.plot(t,C)

plt.grid()
plt.show()

