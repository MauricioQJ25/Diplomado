#include <stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel 
   {
      int id = omp_get_thread_num();
      #pragma omp sigle
      {
      printf("Es una %d ",id);
      #pragma omp task
      printf("prueba ");
      #pragma omp task
      printf ("del ejemplo \n");
     }


   }

}
