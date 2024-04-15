#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int myrank, numprocs;
    int value;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    if (numprocs < 2) {
        printf("This program requires at least 2 processes.\n");
        MPI_Finalize();
        return 1;
    }

    if (myrank == 0) {
        // Root process reads an integer value
        printf("Enter an integer value: \n");
        scanf("%d", &value);

        // Send the value to Process 1 with an incremented value
        value++;
        MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("\nRoot: Sent value %d to Process 1\n", value);

        // Receive the value from the last process (Process numprocs-1)
        MPI_Recv(&value, 1, MPI_INT, numprocs - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Root: Received value %d from Process %d\n", value, numprocs - 1);
    } else if (myrank < numprocs - 1) {
        // Intermediate processes
        MPI_Recv(&value, 1, MPI_INT, myrank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d: Received value %d from Process %d\n", myrank, value, myrank - 1);

        // Increment the value
        value++;

        // Send the value to the next process
        MPI_Send(&value, 1, MPI_INT, myrank + 1, 0, MPI_COMM_WORLD);
        printf("Process %d: Sent value %d to Process %d\n", myrank, value, myrank + 1);
    } else {
        // Last process (numprocs - 1)
        MPI_Recv(&value, 1, MPI_INT, myrank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d: Received value %d from Process %d\n", myrank, value, myrank - 1);

        // Increment the value
        value++;

        // Send the value back to the root process (Process 0)
        MPI_Send(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Process %d: Sent value %d back to the Root\n", myrank, value);
    }

    MPI_Finalize();
    return 0;
}
