from numpy import *
import matplotlib.pyplot as plt

for i in range(7):
    string = "data/"+str(30+i)+".dat"
    string1 = "Temperature : "+str(30+i)+" K"
    D=loadtxt(string)
    plt.plot(D[:,0],D[:,1],label=string1)

plt.xlabel("Volume (V)")
plt.ylabel("Pressure (P)")
plt.title(r"Various Isotherms for Hydrogen ($T_{c}$ : 33.23K)")
plt.ylim(5,30)
plt.xlim(0,0.4)
plt.legend()
plt.savefig("pVersusV.pdf",dpi=500)
