#include <stdio.h>
#include <mpi.h>


int main ( int arc, char *argv[]){
  
int id, np, dato=0;
int NP=1,NPM; 
MPI_Status estado;
MPI_Init(&arc, &argv);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &id);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   if(np != 4) {
      printf("Se requieren 4 procesos \n");
      MPI_Finalize();
      return 1;
   }
   if (id==0){
    
      MPI_Send(&dato, 1,MPI_INT,NP,11, MPI_COMM_WORLD);
      MPI_Recv(&dato, 1,MPI_INT,3,12, MPI_COMM_WORLD, &estado);
      printf("dato=%d\n",dato);
   }
   else{
          NPM=NP - 1;
          
          MPI_Recv(&dato, 1,MPI_INT,NPM,11, MPI_COMM_WORLD, &estado);
          dato++;

          if (id == (np-1))   
          MPI_Send (&dato,1,MPI_INT,0,11,MPI_COMM_WORLD); 
          
          
          else{
          NP++;
          MPI_Send (&dato,1,MPI_INT,NP,11,MPI_COMM_WORLD);
        }
   }
MPI_Finalize();
return 0;

}//fin de main
