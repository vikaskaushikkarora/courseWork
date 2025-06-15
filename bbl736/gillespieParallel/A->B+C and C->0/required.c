// Include Libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<pthread.h>

// Define Parameters
#define NTHREADS 10
#define numSteps 100
#define rateRXN1 1
#define rateRXN2 0.5
#define numEnsemble 200/NTHREADS //number of ensemble per thread

