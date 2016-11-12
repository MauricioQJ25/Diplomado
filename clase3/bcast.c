#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){

int id, np, dato;
MPI_Init (&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&id);
MPI_Comm_size(MPI_COMM_WORLD,&np);

if(id==0)
  dato =10;

MPI_Bcast(&dato,1,MPI_INT,0,MPI_COMM_WORLD);
printf("dato= %d", dato);
MPI_Finalize();

}
