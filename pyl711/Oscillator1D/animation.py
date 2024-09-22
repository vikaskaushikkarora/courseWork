import time
st=time.time()
import os
import multiprocessing
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt

#Load data about x,y axies and number of time intervals
A=np.loadtxt("data.txt")
x=A[:,0]
y=A[:,1]
B=np.loadtxt("dataextra.txt")
n=int(B[0])
m=int(B[1])
l=int(B[2])

#define several parameters
pp=10 #Number of parallel processes
s=5 #speed of animation
DPI=400 #image qaulty
FRAMERATE=60 #video fps
N=int(n/s)

fig = plt.figure()
ax = plt.axes([0.0001,0.001,0.999,0.999])

#define the process of plotting individual images for jth parallel process
def makeVideo(j):
	for i in range(int(j*N/pp),int((j+1)*N/pp)):
		#set background
		ax.set_facecolor('black')
		ax.set_xticks([])
		ax.set_yticks([])
		ax.set_xlim(-15,15)
		ax.set_ylim(-3,3)
		string="images/image"+str(s*i)+".txt"
		for j in range(m):
			for k in range(l):
				plt.plot(x[j*n*l+k*n:j*n*l+(k)*n+s*i],y[j*n*l+k*n:j*n*l+(k)*n+s*i],'-r',linewidth=0.2)
		# Saving Plot Images
		string="images/plot"+str(i)+".png"
		plt.savefig(string,dpi=DPI)
		print((i/n)*100,"% is complete .")
		ax.clear()

#remove the images folder if any
os.system("rm -r images")
os.system("mkdir images")

#start several parallel processes for plotting the images
processes=[]
for j in range(pp):
  P=multiprocessing.Process(target=makeVideo,args=[j])
  P.start()
  processes.append(P)
  
for process in processes:
  process.join()

#start the process of making video/animation from the individual images
#(using ffmpeg)
os.system("rm output.mp4")
string1="ffmpeg -framerate "+str(FRAMERATE)+" -i images/plot%d.png -c:v libx264 -vf format=yuv420p output.mp4"
os.system(string1)
ft=time.time()
print("The time taken is",ft-st,"seconds")
os.system("rm -r images")
