#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char* argv[]) {
    int myid, numprocs, namelen, num1 = 50, num2 = 25;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Init(&argc, &argv); // starts MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &myid); // get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs); // get number of processes
    MPI_Get_processor_name(processor_name, &namelen);
    if (myid % 4 == 0) 
        printf("Sum: %d\n", num1 + num2);  
    if (myid % 4 == 1) 
        printf("Difference: %d\n", num1 - num2);   
    if (myid % 4 == 2) 
        printf("Product: %d\n", num1 * num2); 
    if (myid % 4 == 3) 
    	printf("Division: %d\n", num1 / num2);
    MPI_Finalize();
    return 0;
}
