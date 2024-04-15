#include <cstdlib>
#include <stdio.h>
#include <mpi.h>

#define ARRAY_SIZE 100

int main(int argc, char* argv[]) {
    int myrank, numprocs;
    int data;
    int result;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    if (numprocs < 2) {
        printf("This program requires at least 2 processes.\n");
        MPI_Finalize();
        return 1;
    }

    if (myrank == 0) {
        int array[ARRAY_SIZE];
        printf("Enter %d elements of the array:\n", numprocs);
        for (int i = 0; i < numprocs; ++i) {
            scanf("%d", &array[i]);
        }

        for (int dest = 1; dest < numprocs; ++dest) {
            MPI_Buffer_attach(malloc(1000), 1000); // Attach buffer
            MPI_Bsend(&array[dest - 1], 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
            printf("Root: Sent element %d to process %d\n", array[dest - 1], dest);
        }
    } else {
        MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d: Received element %d\n", myrank, data);
        if (myrank % 2 == 0) {
            result = data * data; 
            printf("Process %d: Square of %d is %d\n", myrank, data, result);
        } else {
            result = data * data * data; 
            printf("Process %d: Cube of %d is %d\n", myrank, data, result);
        }
    }

    MPI_Finalize();
    return 0;
}
