#include <stdio.h>
#include <mpi.h>


main ( int arc, char *argv[]){
  int id, np;  
MPI_Init(&arc, &argv);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &id);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   printf("hola desde el proceso %d de %d\n", id, np);
MPI_Finalize();
}
