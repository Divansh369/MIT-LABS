#include <cstring>
#include <ctime>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used = 0;
    int N;
    
    printf("Enter N: \n");
    scanf("%d", &N);
    
    char str[N], newstr[N * (N + 1) / 2 + 1];
    
    printf("Enter your text: ");
    scanf("%s", str);

    start = clock();

    int k = 0;
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j <= i; j++) {
            newstr[k++] = str[i];
        }
    }
    newstr[k] = '\0';
    end = clock();
    cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nNew Text: %s\n", newstr);
    printf("\nTotal time taken: %0.3f seconds\n", cpu_time_used);
    return 0;
}