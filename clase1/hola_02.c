#include <omp.h>
#include <stdio.h>

int main(){
int nth,id;
#pragma omp parallel
{
   id=omp_get_thread_num();
   nth=omp_get_num_threads();

   printf("Hola desde el hilo %d de %d\n",id,nth);
}
     
  
}
