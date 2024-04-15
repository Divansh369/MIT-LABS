#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void generateArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; 
    }
}

void insertionSortSequential(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortParallel(int arr[], int size, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSortSequential(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j) {
            while (arr[i] <= pivot && i <= high - 1) {
                i++;
            }
            while (arr[j] > pivot && j >= low + 1) {
                j--;
            }
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        quickSortSequential(arr, low, j - 1);
        quickSortSequential(arr, j + 1, high);
    }
}

void quickSortParallel(int arr[], int low, int high, int num_threads) {
    if (low < high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while (i < j) {
            while (arr[i] <= pivot && i <= high - 1) {
                i++;
            }
            while (arr[j] > pivot && j >= low + 1) {
                j--;
            }
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        #pragma omp parallel sections num_threads(num_threads)
        {
            #pragma omp section
            quickSortParallel(arr, low, j - 1, num_threads);
            #pragma omp section
            quickSortParallel(arr, j + 1, high, num_threads);
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sequentialSort(int arr[], int size) {
    int mid = size / 2;
    insertionSortSequential(arr, size);
    quickSortSequential(arr, mid, size - 1);
    merge(arr, 0, mid - 1, size - 1);
}

void parallelSort(int arr[], int size, int num_threads) {
    int mid = size / 2;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            insertionSortParallel(arr, size, num_threads);
        }

        #pragma omp section
        {
            quickSortParallel(arr, mid, size - 1, num_threads);
        }
    }

    merge(arr, 0, mid - 1, size - 1);
}

int main() {
    clock_t start, end;
    double cpu_time_used_sequential = 0;
    double cpu_time_used_parallel = 0;
    int num_threads = 1;

    printf("Array Size\tThreads\tSequential Time (s)\tParallel Time (s)\tSpeedup\t\tEfficiency\n");

    for (int size = 200; size <= 1000; size += 200) {
        for (num_threads = 2; num_threads <= 8; num_threads += 2) {
            int arr[size];
            generateArray(arr, size);
            start = clock();sleep(1);
            sequentialSort(arr, size);
            end = clock();
            cpu_time_used_sequential = ((double)(end - start)) / CLOCKS_PER_SEC;

            start = clock();sleep(1);
            parallelSort(arr, size, num_threads);
            end = clock();
            cpu_time_used_parallel = ((double)(end - start)) / CLOCKS_PER_SEC;

            printf("%d\t\t%d\t%.6f\t\t%.6f\t\t%.6f\t%.6f\n", size, num_threads, cpu_time_used_sequential, cpu_time_used_parallel, cpu_time_used_sequential / cpu_time_used_parallel, (cpu_time_used_sequential / cpu_time_used_parallel) / num_threads);
        }
    }
    return 0;
}
