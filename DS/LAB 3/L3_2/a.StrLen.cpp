#include <iostream>
using namespace std;
 
int main()
{
	char s[30];
	int i,l=0;
	cout<<"enter the string: ";
	gets(s);
	for(i=0;s[i]!='\0';++i)
	{
		l++;
	}
	cout<<"length of the string is: "<<l<<endl;
 
	return 0;
}
