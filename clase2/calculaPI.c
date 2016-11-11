#include <stdio.h>
#include <time.h>
#include <omp.h>

double num_steps= 100000000;
double step;

int main(int argc, char* argv[])
{
 //  clock_t start, stop;
   double empezar, terminar;
   double x, pi, sum=0.0;
   int i;
   step = 1.0/(double)num_steps;
  // start = clock ();
  empezar = omp_get_wtime();
   for(i = 0; i < num_steps; i++){
      x=(i + .5)*step;
      sum = sum + 4.0/(1.0 + x*x);}
   pi = sum * step;
  // stop = clock();
  terminar = omp_get_wtime();
   
   printf("El valor de PI es %15.12f\n", pi);
  // printf("El tiempo para calcular PI fue %lf milisegundos\n", (double)(stop-start)/1000.0);
   printf("El tiempo para calcular PI fue %lf segundos\n",terminar-empezar);
   return 0;
   

}
