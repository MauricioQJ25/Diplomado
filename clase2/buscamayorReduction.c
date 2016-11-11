#include <stdio.h>
#include <stdlib.h>

int *formaVect(int n);
void llenaVect(int *v, int n);
main(){
   int  *A;
   A=formaVect(20);
   llenaVect(A,20);
   imprimeVect(A,20);
   int mayor=BuscaMayor(A,20);
   printf("\nEl mayor es %d\n", mayor);
}

int *formaVect(int n){
   int *v;
   v=(int *)malloc(n*sizeof(int));
   return v;   
}

void llenaVect(int *v,int n){
   int i;
      for(i=0;i<n;i++)
         v[i]=rand()%100;
}

void imprimeVect(int *v, int n){
   int i;
      for(i=0;i<n;i++)
         printf("%d,\t",v[i]);
}

int BuscaMayor(int *A, int n){
   int i;
   int maxi;
   maxi=A[0];
   #pragma omp parallel
   {
      #pragma omp for reduction(max: maxi)
      for(i = 0;i < n; i++){
         if(maxi < A[i]) 
            maxi = A[i];
      }//fin de for
   }//fin de pragma omp parallel
  return maxi;
}//fin de BuscaMayor
