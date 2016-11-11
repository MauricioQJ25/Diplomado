#include <stdio.h>
#include <stdlib.h>

int *formaVect(int n);
void llenaVect(int *v, int n);
void productoVects(int *a, int *b, int n);

main(){
   int *a, *b, *c;
   c=formaVect(20);
   a=formaVect(20);
   b=formaVect(20);
   llenaVect(a,20);
   llenaVect(b,20);
   productoVects(a,b,20);
   //imprimeVect(c,20);
   
}

int *formaVect(int n){
   int *v;
   v=(int *)malloc(n*sizeof(int));
   return v;   
}

void llenaVect(int *v,int n){
   int i;
      for(i=0;i<n;i++)
         v[i]=rand()%20;
}

void productoVects(int *a,int *b, int n){
   int i;
   int res= 0;
   // int nth,id;
   // int inicio,fin;
   // int bloque;
      //#pragma omp parallel private(id, inicio, fin, i)
     // {
       //id=omp_get_thread_num();
       //nth=omp_get_num_threads();
       //bloque = n/nth;
       //inicio= id*bloque;
       //fin = inicio + bloque;
       for(i=0;i<n;i++){
         res = res + a[i]*b[i];
         printf("el valor es %d\n",res);
      }
     // }
     //return res;
}



void imprimeVect(int *v, int n){
   int i;
      for(i=0;i<n;i++)
         printf("%d,\t",v[i]);
}
