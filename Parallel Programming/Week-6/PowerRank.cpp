#include <cstdlib>
#include <stdio.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int rank, size, x, result;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("\nEnter the value of x: ");
        scanf("%d", &x);
    }

    MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

    result = pow(x, rank);

    int *results = NULL;
    if (rank == 0) {
        results = (int *)malloc(size * sizeof(int));
    }
    MPI_Gather(&result, 1, MPI_INT, results, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("\nResults:\n");
        for (int i = 0; i < size; i++) {
            printf("Process %d: %d\n", i, results[i]);
        }
        free(results);
    }

    MPI_Finalize();
    return 0;
}
