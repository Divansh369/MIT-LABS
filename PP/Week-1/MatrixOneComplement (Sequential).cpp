#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define MAX_VALUE 100

void decToBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}

int onesComplement(int num) {
    return ~num;
}

void processMatrix(int **A, int **B, int **D, int ROWS, int COLS) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i != 0 && j != 0 && i != ROWS - 1 && j != COLS - 1) {
                B[i][j] = onesComplement(A[i][j]);
                decToBinary(B[i][j]);
            } else {
                B[i][j] = A[i][j];
                D[i][j] = A[i][j];
            }
        }
    }
}

void generate_matrix(int **matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % MAX_VALUE;
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used = 0;
    int ROWS, COLS;  
    printf("Enter number of rows: \n");
    scanf("%d", &ROWS);
    printf("Enter number of columns: \n");
    scanf("%d", &COLS);
    int **A = (int **)malloc(ROWS * sizeof(int *));
    int **B = (int **)malloc(ROWS * sizeof(int *));
    int **D = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        A[i] = (int *)malloc(COLS * sizeof(int));
        B[i] = (int *)malloc(COLS * sizeof(int));
        D[i] = (int *)malloc(COLS * sizeof(int));
    }
    generate_matrix(A, ROWS, COLS);
    printf("\nMatrix before processing:\n");
    print_matrix(A, ROWS, COLS);
    start = clock();
    processMatrix(A, B, D, ROWS, COLS);
    printf("\nMatrix B after processing:\n");
    print_matrix(B, ROWS, COLS);
    printf("\nMatrix D after processing:\n");
    print_matrix(D, ROWS, COLS);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %0.3f\n", cpu_time_used);
    for (int i = 0; i < ROWS; i++) {
        free(A[i]);
        free(B[i]);
        free(D[i]);
    }
    free(A);
    free(B);
    free(D);
    return 0;
}