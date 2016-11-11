#include <stdio.h>
#include <mpi.h>


int main ( int arc, char *argv[]){
  
int id, np, dato; 
MPI_Status estado;
MPI_Init(&arc, &argv);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &id);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   if(np != 2) {
      printf("Se requieren 2 procesos \n");
      MPI_Finalize();
      return 1;
   }
   if (id==0){
      dato = 7;
      MPI_Send(&dato, 1,MPI_INT,1,11, MPI_COMM_WORLD);
   }
   else{
      //
      MPI_Recv(&dato, 1,MPI_INT,0,11, MPI_COMM_WORLD, &estado);
      printf("El dato es %d\n", dato);
   }
MPI_Finalize();
return 0;

}//fin de main
