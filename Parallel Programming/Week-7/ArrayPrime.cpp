#include <stdio.h>
#include <mpi.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return 0; }
    return 1; }

int main(int argc, char* argv[]) {
    int myrank, numprocs;
    int N = 8; 
    int array[N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    if (numprocs != N) {
        printf("This program requires %d processes.\n", N);
        MPI_Finalize();
        return 1;
    }

    if (myrank == 0) {
        printf("Enter %d elements of the array:\n", N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &array[i]);
        }
    }

    // Broadcast the array to all processes
    MPI_Bcast(array, N, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process checks if its element is prime
    if (isPrime(array[myrank])) {
        printf("Process %d: %d is prime.\n", myrank, array[myrank]);
    } else {
        printf("Process %d: %d is not prime.\n", myrank, array[myrank]);
    }

    MPI_Finalize();
    return 0;
}
