#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t start, end;
    double cpu_time_used = 0;
    int m, n;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    char A[m][n];
    int B[m][n];
	start = clock();
    srand(time(NULL));
    printf("\nMatrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 'A' + rand() % 26; 
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = rand() % 5;
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\nOutput string STR: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < B[i][j]; k++) {
                printf("%c", A[i][j]);
            }
        }
    }
    printf("\n");
	end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %0.3f\n", cpu_time_used);
    return 0;
}