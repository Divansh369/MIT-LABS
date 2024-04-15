#include<iostream>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;
    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new int;
    }
    void queueEnqueue(int data)
    {
        if (capacity == rear) {
            cout<<"\nQueue is full\n";
            return;
        }
        else {
            queue[rear] = data;
            rear++;
        }
        return;
    }
    void queueDequeue()
    {
        if (front == rear) {
            cout<<"\nQueue is  empty\n";
            return;
        }
        else {
            for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
        return;
    }
    void queueDisplay()
    {
        int i;
        if (front == rear) {
            cout<<"\nQueue is Empty\n";
            return;
        }
        for (i = front; i < rear; i++) {
            cout<<queue[i]<<" <-- ";
        }
        return;
    }
};
int main ()
{
    int choice,x,n,i;
    cout<<"Enter size of queue: ";
    cin>>x;
    Queue q(x);
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
			while (n>0){
				cout<<"Enter element: ";
            	cin>>i;
				q.queueEnqueue(i);
				n--;  }
            break;
            case 2:
			cout<<"\nHow  many elements would you like to delete? ";
			cin>>n;
			while (n>0){
				q.queueDequeue();
				n--;}
            break;
            case 3:
           	 	q.queueDisplay();
           		break;
            case 4:
            	exit(0);
            	break;
            default:
            cout<<"Invalid choice.";
        }
    }
	return 0;
}
