#include <ctime>
#include <ctime>
 #include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){
	clock_t start, end;
	double cpu_time_used=0;
	int rev=0;
	int X[9]={18, 523, 301, 1234, 2, 14, 108, 150, 1928};
	printf("Input Array: 18\t523\t301\t1234\t2\t14\t108\t150\t1928\nOutpt Array: ");
	start = clock();
	sleep(1);		
	for (int j=0;j<9;j++){
			for (int k=X[j];k>0;k=k/10){
				rev=(rev*10)+(k%10);
				}
			printf("%d\t",rev);
			rev=0;
			}
		end = clock();
    	cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\n\nTime taken to reverse elements of entire array: %0.3f\n",cpu_time_used);
    return 0;
    }
