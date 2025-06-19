import os
import numpy as np
import matplotlib.pyplot as plt

#Load data about x,y axes and number of time intervals
a=np.loadtxt("a.dat")
u=np.loadtxt("u.dat")
S=np.loadtxt("S.dat")
n=len(u[:,0])
x=np.linspace(a[0,0],a[0,1],int(a[0,2]))

#define several parameters
pp=10 #Number of parallel processes
s=80 #speed of animation
DPI=350 #image qaulty
FRAMERATE=60 #video fps
N=int(n/s)

#remove the images folder if any
os.system("rm -r images")
os.system("mkdir images")

fig,ax = plt.subplots()
for i in range(N):
	fig,ax = plt.subplots()
	ax.plot(x,u[0,:],'k-',label='Initial Cell Density')
	ax.plot(x,S[0,:],'b-.',label='Initial chemoattractant Density')
	ax.plot(x,S[s*i,:],'b-',label='Chemoattractant Density')
	ax.plot(x,u[s*i,:],'r-',label='Present Cell Density')
	ax.legend(loc='upper left',fontsize=10)
	ax.set_xlim(0,10)
	ax.set_ylim(-2,33)
	ax.set_xlabel("Position",fontsize=10)
	ax.set_ylabel("Density",fontsize=10)
	plt.tight_layout()
	
	# Saving Plot Images
	string="images/plot"+str(i)+".png"
	plt.savefig(string,dpi=DPI)
	print((i/N)*100,"% is complete .")
	ax.clear()

#start the process of making video/animation from the individual images
os.system("rm output.mp4")
string1="ffmpeg -framerate "+str(FRAMERATE)+" -i images/plot%d.png -c:v libx264 -vf format=yuv420p output.mp4"
os.system(string1)
#os.system("rm -r images")
