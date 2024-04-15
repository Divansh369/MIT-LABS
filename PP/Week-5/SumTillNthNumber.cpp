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
	int n;
	printf("Enter N: ");
	scanf("%d",&n);
   int total_threads_used;/*
   #pragma omp master 
   {start = clock();
	sleep(1);
   		

	omp_lock_t writelock;
     omp_init_lock(&writelock);
   #pragma omp parallel num_threads(n) reduction (+:sum)
   {
        total_threads_used = n;
        #pragma omp for
        for(int i=1;i<=n;i++){
		 	omp_set_lock(&writelock);
		 	#pragma omp critical
			#pragma omp atomic
            sum = sum + i;
            omp_unset_lock(&writelock);
        } 
    }
    omp_destroy_lock(&writelock);
	}*/
    start = clock();
	sleep(100);
    #pragma omp parallel for reduction(+:sum)
        for(int i=1;i<=n;i++){sum = sum + i;} 
    printf("\nThe total sum is %d\n", sum);
    end = clock();
	cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken: %0.3f\n",cpu_time_used);
    return 0;
}
