#include <stdio.h>
#include <mpi.h>
int main(int argc, char* argv[]) {
    int myrank, numprocs;
    int number;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    if (numprocs < 2) {
        printf("This program requires at least 2 processes.\n");
        MPI_Finalize();
        return 1;}
    if (myrank == 0) {
        for (int dest = 1; dest < numprocs; ++dest) {
            number = dest;
            MPI_Send(&number, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
            printf("Master: Sent number %d to process %d\n", number, dest);}
    } else {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d: Received number %d\n", myrank, number);}
    MPI_Finalize();
    return 0;
}