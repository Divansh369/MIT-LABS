#include <omp.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>

int main ()
{
   int sum = 0;
   clock_t start, end;
	double cpu_time_used=0;  
	int low,high;
	printf("Enter Lower Limit: ");
	scanf("%d",&low);
	printf("Enter Uppper Limit: ");
	scanf("%d",&high);
   int total_threads_used;
   	start = clock();
	sleep(1);
   #pragma omp parallel num_threads(high-low+1) reduction (+:sum)
   {
        total_threads_used = high-low+1;
        #pragma omp for
        for(int i=low;i<=high;i++){
            sum = sum + i;
        } 
	}
    printf("\n\nThe total sum is %d\n\n\n", sum);
    end = clock();
	cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken: %0.3f\n",cpu_time_used);
    return 0;
}
