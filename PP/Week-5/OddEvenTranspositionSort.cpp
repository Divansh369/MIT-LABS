#include <omp.h>
#include <ctime>
#include <cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include <unistd.h>

#define MAX_VALUE 1000

void odd_even_sort(int* a, int n)
{
    int phase, i, temp;
    for(phase = 0; phase < n; phase++)
    {
        if(phase % 2==0) //even phase
        {
            #pragma omp parallel for shared(a, n) private(i, temp)
            for(i = 1; i < n; i += 2)
            {
                if(a[i-1] > a[i])
                {
                    temp = a[i];
                    a[i] = a[i-1];
                    a[i-1] = temp;
                }
            }
        }
        else //odd phase
        {
            #pragma omp parallel for shared(a, n) private(i, temp)
            for(i = 1; i < n-1; i += 2)
            {
                if(a[i] > a[i+1])
                {
                    temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;                        
                }
            }
        }            
    }
}

void generate_array(int* a, int size)
{
    int i = 0;
    srand(time(NULL));
    for(i = 0; i < size; i++)
    {
        a[i] = rand() % MAX_VALUE;
    }
}

int main()
{
    printf("Array Size\tThreads\tSequential Time (s)\tParallel Time (s)\tSpeedup\t\tEfficiency\n");

    for (int size = 200; size <= 1000; size += 200) {
        for (int threads = 2; threads <= 8; threads += 2) {
            double sequential_time = 0, parallel_time = 0;
            int *a = (int*)calloc(size, sizeof(int));
            int *initial = (int*)calloc(size, sizeof(int));

            generate_array(a, size);
            memcpy(initial, a, size * sizeof(int));

            // Sequential operation
            clock_t start = clock();sleep(1);
            odd_even_sort(a, size);
            clock_t end = clock();
            sequential_time = ((double)(end - start)) / CLOCKS_PER_SEC;

            // Parallel operation
            #pragma omp parallel
            start = clock();sleep(1);
            odd_even_sort(a, size);
            end = clock();
            parallel_time = ((double)(end - start)) / CLOCKS_PER_SEC;

            double speedup = sequential_time / parallel_time;
            double efficiency = speedup / threads;

            printf("%d\t\t%d\t%.6f\t\t%.6f\t\t%.6f\t%.6f\n", size, threads, sequential_time, parallel_time, speedup, efficiency);

            free(a);
            free(initial);
        }
    }

    return 0;
}
