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
bool validity(char P[],bool valid)
{
	char popped;
	valid=true;
	int i;
	for(i=0;P[i]!='\0';i++)
	{
		if(P[i]=='('||P[i]=='['||P[i]=='{')
			push(P[i]);
		else if(P[i]==')'||P[i]==']'||P[i]=='}')
		{
			if(isempty())
				valid=false;
			else
			{
				popped=pop();
				if(P[i]==')')
				{
					
					if(int(P[i])!=popped+1)
					{
						valid=false;
						
					}
				
				}
				else
				{
				if(int(P[i])!=popped+2)
					valid=false;
				}
				
			}
			
		}
	}
	if(!isempty())
	{
			valid=false;
	}
return valid;

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
	valid=validity(P,valid);
	if(valid==false)
		cout<<"Invalid expression.";
	else
		cout<<"Valid expression.";	
}

