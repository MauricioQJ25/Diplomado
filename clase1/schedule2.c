#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define CHUNKSIZE 5
#define N 20

int main (int argc, char *argv[]) {

int nthreads, tid, i, chunk;
float a[N], b[N], c[N];


for (i=0; i < N; i++)
  a[i] = b[i] = i * 1.0;

chunk = CHUNKSIZE;

#pragma omp parallel  private(tid)
{
  tid=omp_get_thread_num();  
 
   if (tid == 0)
    {
    nthreads=omp_get_num_threads();   
    printf("Numero de hilos = %d\n", nthreads);
    }
  printf("Iniciando Hilo - %d ...\n",tid);

  #pragma omp for schedule(dynamic,5)
  for (i=0; i<N; i++)
    {
    c[i] = a[i] + b[i];
    printf("Hilo %d: c[%d]= %f\n",tid,i,c[i]);
    }

  } 

}
