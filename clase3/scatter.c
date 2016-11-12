#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

int id, np, dato, *datos,i,j;
MPI_Init (&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&id);
MPI_Comm_size(MPI_COMM_WORLD,&np);

dato = id+1;

if(id == 0){
  datos=(int *)malloc(np*sizeof(int));
     for(i=0;i<np;i++)
         datos[i]=i++;
  }
MPI_Scatter(datos,1,MPI_INT,&dato,1,MPI_INT,0,MPI_COMM_WORLD); 
   printf("dato= %d ",dato);
   printf("\n");




MPI_Finalize();

}

void imprimeVect(int *v, int n){
   int i;
      for(i=0;i<n;i++)
         printf("%d,\t",v[i]);
}

