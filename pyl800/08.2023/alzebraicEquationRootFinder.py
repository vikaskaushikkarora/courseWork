import numpy as np
import matplotlib.pyplot as plt

def f(x):
	return (x-2)*(x-3)*(x-5)

def slope(x,f,h):
	return (f(x+h)-f(x))/h

def bisection(f,a,b,tolerance):
	x=0.5*(a+b)
	y=f(x)
	count=1
	while(abs(y)>tolerance):
		if(y*f(a)>0):
			a=x
		else:
			b=x
		x=0.5*(a+b)
		y=f(x)
		count=count+1
	return x,count

def newtonRaphson(f,a,tolerance):
	count=0
	while(abs(f(a))>tolerance):
		a=a-f(a)*(slope(a,f,0.01))**(-1)
		count +=1
	return a,count

def regulaFalsi(f,a,b,tolerance):
	x=a-f(a)*(b-a)*(f(b)-f(a))**(-1)
	y=f(x)
	count=1
	while(abs(y)>tolerance):
		if(y*f(a)>0):
			a=x
		else:
			b=x
		x=a-f(a)*(b-a)*(f(b)-f(a))**(-1)
		y=f(x)
		count=count+1

	return x,count

def secant(f,a,b,tolerance):
	x=(b*f(a)-a*f(b))*(f(a)-f(b))**(-1)
	y=f(x)
	count=1
	while(abs(y)>tolerance):
		b=x
		x=a-f(a)*(b-a)*(f(b)-f(a))**(-1)
		y=f(x)
		count=count+1

	return x,count


result=bisection(f,2.80,3.25,0.001)
print("bisection root and steps : ",result)
result=newtonRaphson(f,3.25,0.001)
print("Newton Raphson root and steps : ",result)
result=regulaFalsi(f,2.75,3.15,0.001)
print("Regula Falsi root and steps : ",result)
result=secant(f,2.75,3.15,0.001)
print("Secant Method root and steps : ",result)

