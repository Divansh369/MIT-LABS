#include<iostream>
using namespace std;
int main()
{
	char s[100],sub[20];
	int index,i,lsub=0,j=0,l=0;
	cout<<"Enter the string: "<<endl;
	gets(s);
	cout<<"Enter the word to be inserted: "<<endl;
	gets(sub);
	while(sub[j++]!='\0')
	{
		lsub++;
	}
	cout<<"Length of sub-string:"<<lsub;
	cout<<endl;
	j=0;
	while(s[j++]!='\0')
	{
		l++;
	}
	cout<<"Length of main string:"<<l;
	cout<<"\nEnter index where to add sub: \n";
	cin>>index;
	for(i=l;i!=index-1;i--)
	{
		s[i+lsub]=s[i];
	}
	i=index;
	for(j=0;j<lsub;j++)
	{
		s[i++]=sub[j];
	}
	cout<<"new string is:"<<endl<<s;
	return 0;
}
