#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

int id, np, dato, *datos,i,j,res;
MPI_Init (&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&id);
MPI_Comm_size(MPI_COMM_WORLD,&np);

dato = i+1;
MPI_Reduce(&dato,&res,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
if(id==0)
     printf("res=%d",res);


MPI_Finalize();

}

