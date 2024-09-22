import time
st=time.time()
import os
import multiprocessing
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt

# Load data about x,y axies and number of time intervals
A=np.loadtxt("/home/vikas/Desktop/work/data.txt")
B=np.loadtxt("/home/vikas/Desktop/work/data1.txt")
n=int(B[0])
m=int(B[1])

# Define several parameters
pp=10 # Number of parallel processes
DPI=250 # Image qaulty
FRAMERATE=10 # Video fps

fig = plt.figure()
ax = plt.axes([0.01,0.01,0.98,0.98])

# Define the process of plotting individual images for jth parallel process
def makeVideo(j):
	for i in range(int(j*n/pp),int((j+1)*n/pp)):
		# Set background
		ax.set_facecolor('black')
		ax.set_xticks([])
		ax.set_yticks([])
		ax.set_xlim(-0.1,1.1)
		ax.set_ylim(-0.1,1.1)
		string="images/image"+str(i)+".txt"
		plt.plot(A[i*m:(i+1)*m,0],A[i*m:(i+1)*m,1],'*r',markersize=0.05)
		# Saving Plot Images
		string="images/plot"+str(i)+".png"
		plt.savefig(string,dpi=DPI)
		print((i/n)*100,"% is complete .")
		ax.clear()

# Remove the images folder if any
os.system("rm -r images")
os.system("mkdir images")

# Start several parallel processes for plotting the images
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
