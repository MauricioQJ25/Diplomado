#include <stdio.h>
#include <time.h>


int num_steps= 100000000;
double step;

int main(int argc, char* argv[])
{
   clock_t start, stop;
   double x, pi, sum=0.0;
   int i;
   step = 1.0/(double)num_steps;
   start = clock ();
   #pragma omp parallel for reduction(+:sum) private(x)           //sum es compartida, i es privada automaticamente
   for(i = 0; i<num_steps; i++){
      x=(i + .5)*step;
      sum = sum + 4.0/(1.0 + x*x);}
   pi = sum * step;
   stop = clock();
   
   printf("El valor de PI es %15.12f\n", pi);
   printf("El tiempo para calcular PI fue %lf milisegundos\n", (double)(stop-start)/1000.0);
   return 0;
   

}
