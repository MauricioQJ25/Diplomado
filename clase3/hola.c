#include <stdio.h>
#include <mpi.h>


main ( int arc, char *argv[]){
  int id, np, v, sv, len;
  char nombre[20];  
MPI_Init(&arc, &argv);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &id);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   printf("hola desde el proceso %d de %d\n", id, np);
   MPI_Get_version(&v, &sv);
   MPI_Get_processor_name(nombre, &len);
   printf("La version es %d . %d", v ,sv);
   printf("El nombre del host es %s\n", nombre);
MPI_Finalize();
}
