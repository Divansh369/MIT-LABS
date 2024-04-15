#include <ctime>
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
	start = clock();sleep(1);
	printf("A+B: %d\n",A+B);
	printf("A-B: %d\n",A-B);
	printf("A*B: %d\n",A*B);
	printf("A/B: %d\n",A/B);
	end = clock();
    cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %0.3f\n",cpu_time_used);
	return 0;
}
