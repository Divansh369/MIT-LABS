#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAX_VALUE 100

void generate_matrix(int** matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % MAX_VALUE;
        }
    }
}

void matrix_multiplication_sequential(int** a, int** z, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            z[i][j] = a[i][j] * a[i][j];
        }
    }
}

void matrix_multiplication_parallel(int** a, int** z, int size,int num_threads) {
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            z[i][j] = a[i][j] * a[i][j];
        }
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used_sequential = 0;
    double cpu_time_used_parallel = 0;
    int num_threads = 1;

    printf("Matrix Size\tThreads\tSequential Time (s)\tParallel Time (s)\tSpeedup\t\tEfficiency\n");

    for (int size = 200; size <= 1000; size += 200) {
        for (num_threads = 2; num_threads <= 8; num_threads += 2) {
            int **a = (int **)malloc(size * sizeof(int *));
            int **z = (int **)malloc(size * sizeof(int *));
            for (int i = 0; i < size; i++) {
                a[i] = (int *)malloc(size * sizeof(int));
                z[i] = (int *)malloc(size * sizeof(int));
            }

            generate_matrix(a, size, size);

            start = clock();sleep(1);
            matrix_multiplication_sequential(a, z, size);
            end = clock();sleep(1);
            cpu_time_used_sequential = ((double)(end - start)) / CLOCKS_PER_SEC;

            start = clock();
            matrix_multiplication_parallel(a, z, size,num_threads);
            end = clock();
            cpu_time_used_parallel = ((double)(end - start)) / CLOCKS_PER_SEC;

            printf("%dx%d\t\t%d\t%.6f\t\t%.6f\t\t%.6f\t%.6f\n", size, size, num_threads, cpu_time_used_sequential, cpu_time_used_parallel, cpu_time_used_sequential / cpu_time_used_parallel, (cpu_time_used_sequential / cpu_time_used_parallel) / num_threads);

            for (int i = 0; i < size; i++) {
                free(a[i]);
                free(z[i]);
            }
            free(a);
            free(z);
        }
    }

    return 0;
}
