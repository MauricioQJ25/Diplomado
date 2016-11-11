#include <omp.h>
#include <stdio.h>

int main(){
int i;
int  id,nth;
#pragma omp parallel
// num_threads(2) private(i)
{
//omp_set_num_threads(5);

//num_threads(5);

//int i; 
   printf("Hola Mundo\n");
#pragma omp parallel for
   for(i = 0; i < 10; i++){
     printf("Iteracion %d\n",i);
     id=omp_get_thread_num();
     nth=omp_get_num_threads();
     printf("Hola desde el hilo %d de %d\n",id,nth);
     }
}
     printf("Adios\n");
     return 0;
}
