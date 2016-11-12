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
     for(i=0;i<6;i++)
         for(j=0;j<5;j++)
             datos[i][j]=5*i+j;  
  }

MPI_Scatter(datos,5,MPI_INT,&dato,5,MPI_INT,0,MPI_COMM_WORLD); 
   printf("%d,%d,%d,%d,%d",dato[0],dato[1],dato[2],dato[3],dato[4]);
   printf("\n");




MPI_Finalize();

}

void imprimeVect(int *v, int n){
   int i;
      for(i=0;i<n;i++)
         printf("%d,\t",v[i]);
}

