#include<iostream>
using namespace std;

int main(){
	char str[50],word[25],newstr[50];
	int i,j=0,flag=0, k=0,n=0,len=0;

	cout<<"Enter the string: "<<endl;
	gets(str);
	cout<<"Enter the word to be deleted: "<<endl;
	gets(word);
	for(i=0;word[i]!='\0';i++)
		len++;
	
	for(i=0;str[i]!='\0';i++)
	{
		k=i;
		while(str[i]==word[j])
		{
			i++,j++;
			if(j==len)
			{
				flag=1;
				break;
			}
		}
		j=0;
		
		if(flag==0)
			i=k;
		
		else
			flag=0;
		
		newstr[n++]=str[i];
	}
	
	newstr[n]='\0';
	
	cout<<"The modified string is: "<<newstr;
	
	return 0;
}
