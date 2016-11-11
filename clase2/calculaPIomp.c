#include <stdio.h>
#include <time.h>
#include <omp.h>

int num_steps= 100000000;
double step;

int main(int argc, char* argv[])
{
   
   double x, pi, sum=0.0;
   double empezar, terminar;
   int i;
   step = 1.0/(double)num_steps;
   
   empezar = omp_get_wtime();
   #pragma omp parallel for reduction(+:sum) private(x)           //sum es compartida, i es privada automaticamente
   for(i = 0; i<num_steps; i++){
      x=(i + .5)*step;
      sum = sum + 4.0/(1.0 + x*x);}
   pi = sum * step;
   terminar = omp_get_wtime();
   
   printf("El valor de PI es %15.12f\n", pi);
   printf("El tiempo para calcular PI fue %lf segundos\n",terminar-empezar);
   return 0;
   

}
