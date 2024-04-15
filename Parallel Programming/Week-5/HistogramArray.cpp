#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_VALUE 10

void generate_array(int* a, int size)
{
    int i = 0;
    srand(time(0));
    for(i = 0; i < size; i++)
    {
        a[i] = rand() % MAX_VALUE;
    }
}

int main() {
    printf("Array Size\tThreads\tTime (s)\n");
    int temp;
    for (int size = 200; size <= 2000; size += 200) {
        for (int num_threads = 2; num_threads <= 8; num_threads += 2) {
            double cpu_time_used = 0;
            int *array = (int*)calloc(size, sizeof(int));
            generate_array(array, size);

            clock_t start = clock();sleep(1);
            int i,j;
            #pragma omp parallel for num_threads(num_threads) shared(array, size) private(i, j, temp)
            for (i = 0; i < size; ++i) {
                for (j = 0; j < size; ++j) {
                    if (array[j] < temp) {
                        // Do nothing
                    } else {
                        // Print #
                        --array[j];
                    }
                    --temp;
                }
            }
            clock_t end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("%d\t\t%d\t%.6f\n",  size, num_threads, cpu_time_used);

            free(array);
        }
    }
    return 0;
}
