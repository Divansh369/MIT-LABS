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
void generate_matrix(int** matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % MAX_VALUE; 
        }
    }
}
void print_matrix(int** matrix, int rows, int cols) {
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void processMatrix(int** A, int** B, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == i) {
                B[i][j] = 0;
            } else if (j > i) {
                int maxVal = A[i][0];
                for (int k = 1; k < cols; k++) {
                    if (A[i][k] > maxVal) {
                        maxVal = A[i][k];
                    }
                }
                B[i][j] = maxVal;
            } else {
                int minVal = A[i][0];
                for (int k = 1; k < cols; k++) {
                    if (A[i][k] < minVal) {
                        minVal = A[i][k];
                    }
                }
                B[i][j] = minVal;
            }
        }
    }
}
int main() {
    int rows, cols;clock_t start, end;
	double cpu_time_used=0;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    start = clock();
    int **A = (int **)malloc(rows * sizeof(int *));
    int **B = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        A[i] = (int *)malloc(cols * sizeof(int));
        B[i] = (int *)malloc(cols * sizeof(int));
    }
    generate_matrix(A, rows, cols);
    printf("\nMatrix A:\n");
    print_matrix(A, rows, cols);
    processMatrix(A, B, rows, cols);
    printf("\nMatrix B:\n");
    print_matrix(B, rows, cols);
    for (int i = 0; i < rows; i++) {
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);
    end = clock();
    cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %0.3f\n",cpu_time_used);
    return 0;
}