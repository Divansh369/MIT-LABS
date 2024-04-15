#include <omp.h>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(){
	int N;clock_t start, end;
	double cpu_time_used=0;
	printf("Enter N: \n");
	scanf("%d", &N);
	char str1[N],str2[N]; 
	printf("Enter S1: \n");
	scanf("%s", str1);
	printf("Enter S2: \n");
	scanf("%s", str2);
	printf("Result string: \n");
	start = clock();sleep(1);
	#pragma omp for 
	for (int i=0;i<N;i++){
		printf("%c%c",str1[i],str2[i]);
	}
	end = clock();
    cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %0.3f\n",cpu_time_used);
	return 0;
}