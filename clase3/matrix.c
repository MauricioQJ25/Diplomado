#include <stdio.h>
#include <mpi.h>


int main ( int arc, char *argv[]){
  
int id, np, datos[10][5],i,j; 
MPI_Status estado;
MPI_Init(&arc, &argv);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &id);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   if(np != 6) {
      printf("Se requieren 6 procesos \n");
      MPI_Finalize();
      return 0;
   }

   if (id==0){
      //llenadatos(datos);
      for (i = 0; i <5 ; i++){
      MPI_Send(&datos[i*2][0],10,MPI_INT,i+1,i+1,MPI_COMM_WORLD);
      }
      for(i=0;i<5;i++){
         MPI_Recv(&datos[i*2][0],10,MPI_INT,i+1,i+1,MPI_COMM_WORLD,&estado);
      }
      //Imprimir(datos);
   }
   else{
      MPI_Recv(datos,10,MPI_INT,0,id,MPI_COMM_WORLD,&estado);
      for(i=0;i<2;i++)
         for(j=0;j<5;j++)
            datos[i][j]++;
   
   MPI_Send(datos,10, MPI_INT,0,id,MPI_COMM_WORLD);
   }
MPI_Finalize();
return 0;

}//fin de main

/*
void llenardatos(int *datos){

int i,j;
for (i=0;i<5;i++)
   for (j=0;j<10;i++)
   datos[i][j]=i*j;
}

void Imprimir(int *datos){
int i,j;
for (i=0;i<5;i++)
   for (j=0;j<10;i++)
   printf("El valor del dato[%d][%d] es %d",i,j,datos[i][j]);

}
*/
