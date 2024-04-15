#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 100

void generate_matrix(int** matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % MAX_VALUE;
        }
    }
}

void generate_vector(int* vector, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        vector[i] = rand() % MAX_VALUE;
    }
}

void matrix_vector_multiplication_sequential(int** matrix, int* vector, int* result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        result[i] = 0;
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

void matrix_vector_multiplication_parallel(int** matrix, int* vector, int* result, int rows, int cols, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < rows; i++) {
        result[i] = 0;
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used_sequential = 0;
    double cpu_time_used_parallel = 0;

    printf("Matrix Size\tVector Size\tThreads\tSequential Time (s)\tParallel Time (s)\tSpeedup\t\tEfficiency\n");

    for (int size = 200; size <= 1000; size += 200) {
            for (int num_threads = 2; num_threads <= 8; num_threads += 2) {
                int **matrix = (int **)malloc(size * sizeof(int *));
                int *vector = (int *)malloc(size * sizeof(int));
                int *result_sequential = (int *)malloc(size * sizeof(int));
                int *result_parallel = (int *)malloc(size * sizeof(int));

                for (int i = 0; i < size; i++) {
                    matrix[i] = (int *)malloc(size * sizeof(int));
                }

                generate_matrix(matrix, size, size);
                generate_vector(vector, size);

                start = clock();
                matrix_vector_multiplication_sequential(matrix, vector, result_sequential, size, size);
                end = clock();
                cpu_time_used_sequential = ((double)(end - start)) / CLOCKS_PER_SEC;

                start = clock();
                matrix_vector_multiplication_parallel(matrix, vector, result_parallel, size, size, num_threads);
                end = clock();
                cpu_time_used_parallel = ((double)(end - start)) / CLOCKS_PER_SEC;

                printf("%dx%d\t\t%dx1\t\t%d\t%.6f\t\t%.6f\t\t%.6f\t%.6f\n", size, size, size, num_threads, cpu_time_used_sequential, cpu_time_used_parallel, cpu_time_used_sequential / cpu_time_used_parallel, (cpu_time_used_sequential / cpu_time_used_parallel) / num_threads);

                for (int i = 0; i < size; i++) {
                    free(matrix[i]);
                }
                free(matrix);
                free(vector);
                free(result_sequential);
                free(result_parallel);
            }
    }

    return 0;
}
