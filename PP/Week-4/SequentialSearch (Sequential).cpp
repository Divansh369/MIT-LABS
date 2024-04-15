#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

bool sequentialSearch(int element, int array[], int n) {
    for (int i = 0; i < n; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

bool parallelSearch(int element, int array[], int n, int num_threads) {
    bool found = false;
    #pragma omp parallel for num_threads(num_threads) shared(found)
    for (int i = 0; i < n; i++) {
        if (array[i] == element) {
            found = true;
        }
    }
    return found;
}

int main() {
    printf("Array Size\tThreads\t   Sequential Time (s)\t   Parallel Time (s)\tSpeedup\t\tEfficiency\n");

    for (int size = 200; size <= 1000; size += 200) {
        int arr[size];

        for (int num_threads = 2; num_threads <= 8; num_threads += 2) {
            double sequential_time = 0;
            double parallel_time = 0;

            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 100; 
            }
            int element_to_find = arr[rand() % 100]; 
            clock_t start = clock();sleep(1);
            sequentialSearch(element_to_find, arr, size);
            clock_t end = clock();
            sequential_time = ((double)(end - start)) / CLOCKS_PER_SEC;

            start = clock();sleep(1);
            parallelSearch(element_to_find, arr, size, num_threads);
            end = clock();
            parallel_time = ((double)(end - start)) / CLOCKS_PER_SEC;

            double speedup = sequential_time / parallel_time;
            double efficiency = speedup / num_threads;

            printf("%d\t\t%d\t%.6f\t\t%.6f\t\t%.6f\t%.6f\n", size,num_threads, sequential_time, parallel_time, speedup, efficiency);
        }
    }
    return 0;
}