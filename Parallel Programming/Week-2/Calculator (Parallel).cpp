#include <omp.h>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){
	clock_t start, end;
	double cpu_time_used=0;
	int A,B;
	printf("Enter A: \n");
	scanf("%d",&A);
	printf("Enter B: \n");
	scanf("%d",&B);
	start = clock();
	sleep(1);
	#pragma omp parallel num_threads(1)
	{
	printf("A+B: %d\n",A+B);
	printf("A-B: %d\n",A-B);
	printf("A*B: %d\n",A*B);
	printf("A/B: %d\n",A/B);
	}
	end = clock();
	printf("Time taken: %0.3f\n",((double) (end - start)) / CLOCKS_PER_SEC);
	return 0;
}
