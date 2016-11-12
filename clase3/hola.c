#include <stdio.h>
#include <mpi.h>


int main ( int arc, char *argv[]){
  
int id, np, dato[10],i; 
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
      //llenaArreglo(dato);
      for (i = 0; i <10 ; i++)
         dato[i]=i;
      MPI_Send(&dato, 10,MPI_INT,1,11, MPI_COMM_WORLD);
      MPI_Recv(&dato, 10,MPI_INT,1,12, MPI_COMM_WORLD, &estado);
      printf("dato=%d\n",dato);
   }
   else{
      //
      MPI_Recv(&dato, 1,MPI_INT,0,11, MPI_COMM_WORLD, &estado);
      //dato++;
      MPI_Send (&dato,1,MPI_INT,0,12,MPI_COMM_WORLD); 
     //imprimeArreglo(dato);
     //printf("El dato es %d\n", dato);
     for (i = 0; i <10 ; i++)
        dato[i]=i; 
   }
MPI_Finalize();
return 0;

}//fin de main


