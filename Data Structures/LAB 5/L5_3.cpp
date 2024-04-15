#include<iostream>
using namespace std;
int top=-1;
char data;
char stack[100];
bool valid=true;
bool isempty()
{
	if(top==-1)
		return true;
	else
		return false;
}

void push(char data)
{

		top++;
		stack[top]=data;

	
}
char pop()
{
	if(isempty())
	  cout<<"Stack is empty";
	else
	{
		data=stack[top];
		top--;
		return data;
	}
}

int main()
{
	int n;
	cout<<"Enter size of stack: ";
	cin>>n;
	char P[n];
	cout<<"Input expression: ";
	for (int i=0;i<n;i++){
		cin>>P[i];
	}
	int h=n-1;
	int l=0;
	int m;
	while (h>l){
		if (P[h]==P[l]){
			m=1;
			}
		else{
			m=0;
			break;}
		h--;
		l++;
		}
	switch (m){
		case 1: {
			cout<<"\nPallindrome.";
			break;
		}
		case 0: {
			cout<<"\nNot a pallindrome.";
			break;
		}
	}
	}
