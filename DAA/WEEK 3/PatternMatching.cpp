#include <stdio.h>
#include <iostream>
#include <string.h>
 
void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    
    for (int i = 0; i <= N - M; i++) {
        int j;

        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j==M) 
            printf("\nPattern found at index %d ", i);
    }
}
int main()
{
    char txt[30],pat[30];
    std::cout<<"Enter text: ";
	std::cin>>txt;
	std::cout<<"Enter pattern: ";
	std::cin>>pat;
    search(pat, txt);
    return 0;
}
