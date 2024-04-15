#include <cstring>
#include <ctime>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <time.h>
#include <string>

int main(){
	char str[20];
	clock_t start, end;
	double cpu_time_used=0; 
	printf("Enter your text: \n");
	scanf("%s", str);start = clock();
	for (int i=0;i<strlen(str);i++){
		
		if (islower(str[i])){
			str[i]=toupper(str[i]);
		}
		else if (isupper(str[i])){
			str[i]=tolower(str[i]);
		}
		
	}end = clock();
    	cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
    	printf("Time taken: %0.3f\n",((double) (end - start)) / CLOCKS_PER_SEC);
	printf("\nNew Text: %s",str);
	printf("\nTotal time taken: %0.3f\n",cpu_time_used);
	return 0;
}
