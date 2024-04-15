#include<iostream>
using namespace std;
     
int front=-1;  
int rear=-1;
int x=30;  
int queue[30];  
void Enqueue(int element)  
{  
    if(front==-1 && rear==-1) {
        front=0;  
        rear=0;  
        queue[rear]=element;  
    }  
    else if((rear+1)%x==front) 
    {  
        cout<<"Queue overflow\n";  
    }  
    else  
    {  
        rear=(rear+1)%x;       
        queue[rear]=element;       
    }  
}  
int Dequeue()  
{  
    if((front==-1) && (rear==-1))  
    {  
        cout<<"\nQueue underflow\n";  
    }  
 else if(front==rear)  
{  
   cout<<"\nThe dequeued element is "<<queue[front];  
   front=-1;  
   rear=-1;  
}   
else  
{  
    cout<<"\nThe dequeued element is "<<queue[front];  
   front=(front+1)%x;  
}  
}    
void display()  
{  
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        cout<<"\nQueue is empty\n";  
    }  
    else  
    {  
        cout<<"\nElements in a Queue are: ";  
        while(i<=rear)  
        {  
            cout<<queue[i]<<" <-- ";  
            i=(i+1%x);  
        }  
    }  
}  
int main()   
{  
   cout<<"Enter size of queue: ";
   cin>>x;
   int queue[x];
   int choice,i,n;    
   while(choice != 4)  
    {     
        cout<<"\n\n1. Insert elements.\n2. Delete elements.\n3. Display the queue.\n4. Exit.\n";  
        cout<<"\nEnter your choice: ";  
        cin>>choice;  
    	switch(choice)  
    {  
        case 1:
			cout<<"\nHow  many elements would you like to enter? "; 
			cin>>n;
			while (n>0) {
				cout<<"Enter element: ";
            	cin>>i;
				Enqueue(i) ;
				n--;  }   
        break;  
        case 2:  
			cout<<"\nHow  many elements would you like to delete? "; 
			cin>>n;
			while (n>0) {
				Dequeue() ;
				n--;}    
        break;  
        case 3:  
        	display() ;  
        	break;
        case 4:  
            	exit(0);  
            	break;  
            default:   
            printf("\nPlease enter a valid choice!\n"); 
  
    }}  
    return 0;  
} 
