#include <stdio.h>
#include <mpi.h>


main ( int arc, char *argv[]){

MPI_Init(&arc, &argv);
   printf("Hola Mundo\n");
MPI_Finalize();
}
