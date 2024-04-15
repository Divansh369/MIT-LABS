#include <iostream>
using namespace std;
int stack[1000], n, top=-1,val3;

void push(int val) 
{
   if(top+1<n){
   		top++;
      	stack[top]=val;
   }
   else {
      	cout<<"Stack overflow"<<endl;
   }
}
void pop() {
   if(top<=-1)
   cout<<"Stack underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() 
{
   if(top>=0) 
   {
      cout<<"Stack element(s):"<<endl;
      for (int i=top; i>=0; i--)
      cout<<stack[i]<<endl;
   } else
   cout<<"Stack is empty";
}
int main() {
	cout<<"Enter size of stack:"<<endl;
	cin>>n;
   int ch, val;
   cout<<"1) Push to stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter a choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val3;
            push(val3);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Incorrect choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}
