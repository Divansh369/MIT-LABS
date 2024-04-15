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
int onesComplement(int num) {
    return ~num;
}
void processMatrixsequential(int **a, int **b, int **d,int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != 0 && j != 0 && i != size - 1 && j != size - 1) {
                b[i][j] = onesComplement(a[i][j]);
            } else {
                b[i][j] = a[i][j];
                d[i][j] = a[i][j];
            }
        }
    }
}
void processMatrixparallel(int **a, int **b, int **d,int size,int num) {
    #pragma omp for collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != 0 && j != 0 && i != size - 1 && j != size - 1) {
                b[i][j] = onesComplement(a[i][j]);
            } else {
                b[i][j] = a[i][j];
                d[i][j] = a[i][j];
            }
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
            int **b = (int **)malloc(size * sizeof(int *));
            int **d = (int **)malloc(size * sizeof(int *));
            for (int i = 0; i < size; i++) {
                a[i] = (int *)malloc(size * sizeof(int));
                b[i] = (int *)malloc(size * sizeof(int));
                d[i] = (int *)malloc(size * sizeof(int));
            }

            generate_matrix(a, size, size);

            start = clock();sleep(1);
            processMatrixsequential(a,b,d, size);
            end = clock();sleep(1);
            cpu_time_used_sequential = ((double)(end - start)) / CLOCKS_PER_SEC;

            start = clock();
            processMatrixparallel(a, b,d, size,num_threads);
            end = clock();
            cpu_time_used_parallel = ((double)(end - start)) / CLOCKS_PER_SEC;

            printf("%dx%d\t\t%d\t%.6f\t\t%.6f\t\t%.6f\t%.6f\n", size, size, num_threads, cpu_time_used_sequential, cpu_time_used_parallel, cpu_time_used_sequential / cpu_time_used_parallel, (cpu_time_used_sequential / cpu_time_used_parallel) / num_threads);
            for (int i = 0; i < size; i++) {
                free(a[i]);
                free(b[i]);
                free(d[i]);
            }
            free(a);
            free(b);
            free(d);
        }
    }
    return 0;
}