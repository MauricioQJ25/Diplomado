#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int *formaVect(int n);
void llenaVect(int *v, int n);
void sumaVects(int *a, int *b, int *c, int n);

main(){
   int *a, *b, *c, *d, *e, *f;

   a=formaVect(20);
   b=formaVect(20);
   c=formaVect(20);

   d=formaVect(20);
   e=formaVect(20);
   f=formaVect(20);

   llenaVect(a,20);
   llenaVect(b,20);

   llenaVect(e,20);
   llenaVect(f,20);

   int n=20, j=0,  i=0;

   double empezar, terminar;
   empezar = omp_get_wtime();
   #pragma omp parallel 
   {
   #pragma  parallel  for
      for(i=0;i<n;i++){
         c[i]=a[i]+b[i];
         d[j]=e[j]+f[j];

   } 
   terminar = omp_get_wtime();
   printf("El tiempo para calcular las sumas  fue %lf segundos\n",terminar-empezar);
   }
   //sumaVects(a,b,c,20);
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

void sumaVects(int *a,int *b,int *c, int n){
   int i;
   int nth,id;
   int inicio,fin;
   int bloque;
      #pragma omp parallel private(id, inicio, fin, i)
      {
       id=omp_get_thread_num();
       nth=omp_get_num_threads();
       bloque = n/nth;
       inicio= id*bloque;
       fin = inicio + bloque;
       for(i=inicio;i<fin;i++){
         c[i] = a[i] + b[i];
      }
      }
}

void imprimeVect(int *v, int n){
   int i;
      for(i=0;i<n;i++)
         printf("%d,\t",v[i]);
}
