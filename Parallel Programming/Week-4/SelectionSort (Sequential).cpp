#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_VALUE 100

void generateArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

double sequentialSort(int arr[], int size) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();sleep(1);
    selectionSort(arr, size);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

double parallelSort(int arr[], int size, int num_threads) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();sleep(1);
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < size; i++) {
        selectionSort(arr, size);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

int main() {
    printf("Array Size\tThreads\tSequential Time (s)\tParallel Time (s)\tSpeedup\t\tEfficiency\n");

    for (int size = 200; size <= 1000; size += 200) {
        int arr[size];

        generateArray(arr, size);

        for (int num_threads = 2; num_threads <= 8; num_threads += 2) {
            double sequential_time = sequentialSort(arr, size);
            double parallel_time = parallelSort(arr, size, num_threads);
            double speedup = sequential_time / parallel_time;
            double efficiency = speedup / num_threads;

            printf("%d\t\t%d\t%.6f\t\t%.6f\t\t%.6f\t%.6f\n", size, num_threads, sequential_time, parallel_time, speedup, efficiency);
        }
    }

    return 0;
}
