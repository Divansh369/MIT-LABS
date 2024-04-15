#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void generateRandomVector(int *vector, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        vector[i] = rand() % 100; 
    }
}

void VectorAddition(int *a, int *b, int *c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

void VectorSubtraction(int *a, int *b, int *c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }
}

void VectorMultiplication(int *a, int *b, int *c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }
}

int main() {
    printf("Vector Size\tThreads\tSequential Time (s)\tParallel Time (s)\tSpeedup\t\tEfficiency\n");

    for (int size = 200; size <= 1000; size += 200) {
        int v1[size], v2[size], add[size], sub[size], mult[size];

        generateRandomVector(v1, size);
        generateRandomVector(v2, size);

        for (int num_threads = 2; num_threads <= 8; num_threads += 2) {
            double sequential_time = 0, parallel_time = 0;

            // Sequential operations
            clock_t start = clock();sleep(1);
            VectorAddition(v1, v2, add, size);
            VectorSubtraction(v1, v2, sub, size);
            VectorMultiplication(v1, v2, mult, size);
            clock_t end = clock();
            sequential_time = ((double)(end - start)) / CLOCKS_PER_SEC;

            // Parallel operations
            start = clock();sleep(1);
            #pragma omp parallel sections
            {
                #pragma omp section
                VectorAddition(v1, v2, add, size);
                #pragma omp section
                VectorSubtraction(v1, v2, sub, size);
                #pragma omp section
                VectorMultiplication(v1, v2, mult, size);
            }
            end = clock();
            parallel_time = ((double)(end - start)) / CLOCKS_PER_SEC;

            double speedup = sequential_time / parallel_time;
            double efficiency = speedup / num_threads;

            printf("%d\t\t%d\t%.6f\t\t%.6f\t\t%.6f\t%.6f\n", size, num_threads, sequential_time, parallel_time, speedup, efficiency);
        }
    }
    return 0;
}