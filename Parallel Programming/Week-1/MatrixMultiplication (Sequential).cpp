#include <ctime>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define MAX_VALUE 100
void generate_matrix(int** matrix, int rows, int cols) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
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
void generate_array(int* a, int size)
{
    int i = 0;
	srand(time(NULL));
	for(i = 0; i < size; i++)
    {
		a[i] = rand() % MAX_VALUE;
    }
}
void print_array(int* a, int size) {
    printf("\nVector:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
	int m,n;clock_t start, end;
	double cpu_time_used=0;
	printf("Enter m: \n");
	scanf("%d", &m);
	printf("Enter n: \n");
	scanf("%d", &n);
	int **mat = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    generate_matrix(mat, m, n);
	print_matrix(mat, m, n);
	int *vector = (int*)calloc(n, sizeof(int));
	generate_array(vector,n);
	print_array(vector,n);
	printf("\nResult matrix: \n");
	start = clock();sleep(1);
	int sum=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			sum=sum+(mat[i][j]*vector[j]);
		}
	 	printf("%d\n",sum);
	 	sum=0;
	}
	end = clock();
    cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %0.3f\n",cpu_time_used);
	return 0;
}