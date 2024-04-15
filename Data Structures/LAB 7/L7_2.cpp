 #include<iostream>
using namespace std;
#include<string>
     
int front=-1;  
int rear=-1;
int x=30;  
string queue[30];  
void Enqueue(string element)  
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
   int choice; 
   string i;   
   do
    {     
        cout<<"\n1. Insert element.\n2. Delete element.\n3. Display the queue.\n4. Exit.\n";  
        cout<<"\nEnter your choice: ";  
        cin>>choice;  
    	switch(choice)  
    {  
        case 1:{
			cout<<"Enter element: ";
       	 	cin>>i;
			Enqueue(i); 
       		break;  }
        case 2:  {
			Dequeue() ; 
            break;  }
        case 3: {
        	display() ;  
        	break;}
        case 4:  {
            	exit(0);  
            	break;  }
        default:   {
           printf("\nPlease enter a valid choice!\n"); 
		   break;}
    }}
	while(choice != 4) ;  
    return 0;  
} 
