import numpy as np 
from numpy import pi,exp,sqrt 
import matplotlib.pyplot as plt 
import os

v=0 
D=0.1 
s=0.1 
t=np.linspace(0,0.1,2000) 
x=np.linspace(-1,1,400) 

n=len(t) 
m=len(x) 
dt=t[1]-t[0] 
dx=x[1]-x[0] 

u=np.zeros((n,m),dtype=float) 
#initial condition

for i in range(int(m/4)): 
	u[0,i]=0 
for i in range(int(m/4),int(3*m/4)): 
        u[0,i]=-x[i]+0.5
for i in range(int(3*m/4),m): 
        u[0,i]=0

'''
for i in range(int(m/4)): 
	u[0,i]=0 
for i in range(int(m/4),m): 
        u[0,i]=((x[i]+0.5)**0.5)*exp(-10*(x[i]+0.5)) 
'''
#boundary condition 
u[:,0]=0 
u[:,m-1]=0 

for i in range(n-1): 
        for j in range(1,m-1): 
                u[i+1,j]=u[i,j]-0.5*v*(dt/dx)*(u[i,j+1]-u[i,j-1])+D*(dt/(dx*dx))*(u[i,j+1]+u[i,j-1]-2*u[i,j]) 

os.system("rm -r images")
os.system("mkdir images")

s=1
plt.rcParams['axes.facecolor']='black'
plt.xticks=([])
plt.yticks=([])
plt.grid(linestyle=':')
for i in range(int(n/s)): 
        plt.plot(x,u[s*i,:],'r-') 
        plt.xlim(-1,1)
        plt.ylim(0,0.55)
        plt.rcParams['axes.facecolor']='black'
        plt.xticks=([])
        plt.yticks=([])
        striing="Time : "+str(round(100*i*dt,2))
        plt.title(striing)
        plt.grid(linestyle=':')
        string="images/plot"+str(i)+".png"
        plt.savefig(string,dpi=250)
        plt.clf()

os.system("rm output.mp4")
FRAMERATE=60
string1="ffmpeg -framerate "+str(FRAMERATE)+" -i images/plot%d.png -c:v libx264 -vf format=yuv420p output.mp4"
os.system(string1)
os.system("rm -rf images")
