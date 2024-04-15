#include <omp.h>
#include <cstring>
#include <ctime>
#include <stdio.h>
#include <string>
#include <time.h>
#include <unistd.h>


int main(){
    char str[50],newstr[50];
    clock_t start, end;
    double cpu_time_used=0;
    printf("Enter your text: \n");
    scanf("%s", str);
    start = clock();sleep(1);
    for (int i=0;i<strlen(str);i++){
        #pragma omp parallel num_threads(3)
        {
        if (islower(str[i])){
            newstr[i]=toupper(str[i]);
            }
        if (isupper(str[i])){
            newstr[i]=tolower(str[i]);}}}
    newstr[strlen(str)] = '\0';
    end = clock();  
    cpu_time_used=cpu_time_used +((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %0.3f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("\nNew Text: %s\n",newstr);
    return 0;}