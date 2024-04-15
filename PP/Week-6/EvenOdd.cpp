#include <stdio.h> 
#include <mpi.h> 
#include <stdlib.h>
 
int main(int argc, char* argv[])
{
	int myid, numprocs=10, namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
 
	MPI_Init(&argc, &argv);        // starts MPI
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);  // get current process id
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);      // get number of processeser
	MPI_Get_processor_name(processor_name, &namelen);
	printf("Rank %d: ", myid);
	if (myid % 2 == 0) {
		printf("Hello\n");
	}
	else {
		printf("World\n");
	}
 
	MPI_Finalize();
 
	return 0;
}
