# Correlation between critical temperature and boiling point for 19 gases
# Import Required Libraries
from numpy import *
import matplotlib.pyplot as plt

R=0.082057366080960 # Gas Constant in Litre-atm convention

#Import data for van der waals constants and boiling points for 19 gases
D=loadtxt("a.dat")
a=D[:,0] 
b=(D[:,1])*(1e-2)
Tb=D[:,2] # Boiling Points

# Critical Temperatures Calculation
Tc = 8*a/(27*R*b) 

# Linear Fitting 
coefficients = polyfit(Tc,Tb, 1)
slope,intercept = coefficients
x=linspace(min(Tc),max(Tc),1000)
y=slope*x+intercept

# Plotiing
fig,ax = plt.subplots()
plt.plot(x,y,'r-',label="Linear Fit")
plt.plot(Tc,Tb,'ko',label="Data points")
plt.xlabel("Crtitical Temperature (K)")
plt.ylabel("Boiling Point (K)")
plt.title("Correlation between Boiling Point and Critical Temperature")
text="Slope : "+str(round(slope,2))
plt.text(0.8,0.2,text,horizontalalignment='center',verticalalignment='center',transform=ax.transAxes)
plt.tight_layout()
plt.legend()
plt.savefig("plot.pdf",dpi=500)
