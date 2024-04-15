#include <bits/stdc++.h>
using namespace std;

struct node {
   int data;
   struct node *next;
};
struct node *insertEnd(struct node *head,int num){
    struct node ptr=(struct node)malloc(sizeof(struct node));
    struct node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=ptr;
    ptr->data=num;
    ptr->next=NULL;
    return head;
}

struct node *insertBeg(struct node *head,int num){
    struct node ptr=(struct node)malloc(sizeof(struct node));
    ptr->data=num;
    ptr->next=head;
    return ptr;
}

struct node *insertBef(struct node *head,int num,int ele){
    struct node ptr=(struct node)malloc(sizeof(struct node));
    struct node *temp=head;
    struct node *q=temp->next;
    while(q->data!=num){
        temp=temp->next;
        q=q->next;
    }
    ptr->data=ele;
    temp->next=ptr;
    ptr->next=q;
    return head;
}

struct node *deleteNode(struct node *head,int num){
    if(head->data==num){
        head=head->next;
        return head;
    }
    struct node ptr=(struct node)malloc(sizeof(struct node));
    struct node *temp=head;
    struct node *q=temp->next;
    while(q->data!=num){
        temp=temp->next;
        q=q->next;
    }
    temp->next=q->next;
    return head;
}

struct node *insertAft(struct node *head,int num,int ele){
    struct node ptr=(struct node)malloc(sizeof(struct node));
    struct node *temp=head;
    while(temp->data!=num){
        temp=temp->next;
    }
    ptr->data=ele;
    ptr->next=temp->next;
    temp->next=ptr;
    return head;
}
void display() {
   struct node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
	}
}
 int main(){ 
 	struct node head=(struct node)malloc(sizeof(struct node));
 	head->data=0;
 	head->next=NULL;
 	int a,x,i,j,y;
	do{
 		cout<<"\n1) Insert an element in the beginning of the list.";
 		cout<<"\n2) Insert an element at the end of the list.";
		cout<<"\n3) Insert an element before another element in the existing list.";
 		cout<<"\n4) Insert an element after another element in the existing list.";
 		cout<<"\n5) Delete a given element from the list.";
 		cout<<"\n6) Print the list.";
 		cout<<"\n7) Exit.";
		cout<<"\n\n\nEnter a choice: ";
		cin>>x;
		
		switch(x) {
			case 1:
				cout<<"\nEnter element: ";
				cin>>i;
				head=insertBeg(head,i);
				break;
			case 2:
				cout<<"\nEnter element: ";
				cin>>i;
				head=insertEnd(head,i);
				break;
			case 3:
				cout<<"\nEnter element before which element is to be inserted: ";
				cin>>j;
				cout<<"\nEnter element: ";
				cin>>i;
				had=insertBef(head,i,j);
				break;
			case 4:
				cout<<"\nEnter element before which element is to be inserted: ";
				cin>>j;
				cout<<"\nEnter element: ";
				cin>>i;
				head=insertAft(head,i,j);
				break;
			case 5:
				cout<<"\nEnter position at which element is to be deleted: ";
				cin>>i;
				head=deleteNode(head,i);
				break;
			case 6:
				cout<<"\n\n\n";
				cout<< "Linked List: ";
				display();
				cout<<"\n\n\n";
				break;
			case 7:
				exit(0);
				break;
			default:
				cout<< "\n\n\nInvalid choice.\n\n\n";
				break;
		}
		 	}
 	while (x!=7);
	return 0;	
	 }
      
