#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

int id, np, dato, *datos;
MPI_Init (&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&id);
MPI_Comm_size(MPI_COMM_WORLD,&np);

dato = id+1;

if(id == 0)
  datos=(int *)malloc(np*sizeof(int));

MPI_Gather(&dato,1,MPI_INT,datos,1,MPI_INT,0,MPI_COMM_WORLD);
MPI_Barrier(MPI_COMM_WORLD);
if(id==0){
  imprimeVect(datos,10);
  printf("\n");
}
MPI_Finalize();

}

void imprimeVect(int *v, int n){
   int i;
      for(i=0;i<n;i++)
         printf("%d,\t",v[i]);
}

