#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
    node* next;
    node* prev;
    int data;
};
node* head = NULL;
void insert_end(node** head)
{
    cout << "\nEnter Data for New Node: ";
    node* new_node = new node;
    cin >> new_node->data;
 
    if (*head == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    }
    else {
        node* curr = *head;
 
        while (curr->next != *head)
            curr = curr->next;
        new_node->next = curr->next;
        new_node->prev = curr;
        (curr->next)->prev = new_node;
        curr->next = new_node;
    }
}
void insert_after(node** head)
{
    node* new_node = new node;
    cout << "\nEnter Data for New Node: ";
    cin >> new_node->data;
 
    if (*head == NULL) {
        cout << "\nThere is No element in the List";
        cout << "\nCreating a new node";
        new_node->prev = new_node;
        new_node->next = new_node;
        *head = new_node;
    }
    else {
        int num;
        cout << "Enter After Element: ";
        cin >> num;
        node* curr = *head;
 
        while (curr->data != num) {
            curr = curr->next;
            if (curr == *head) {
 
                cout << "\nEntered Element"
                     << " Not Found in "
                        "List\n";
                return;
            }
        }
        new_node->next = curr->next;
        new_node->prev = curr;
        (curr->next)->prev = new_node;
        curr->next = new_node;
    }
}
void insert_front(node** head)
{
    cout << "\nEnter Data for New Node: ";
    node* new_node = new node;
    cin >> new_node->data;
 
    if (*head == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    }
    else {
        new_node->next = *head;
        new_node->prev = (*head)->prev;
        ((*head)->prev)->next = new_node;
        (*head)->prev = new_node;
        *head = new_node;
    }
}
void insert_before(node** head)
{
    node* new_node = new node;
 
    if (*head == NULL) {
        cout << "List is Empty!! Creating New node...";
        cout << "\nEnter Data for New Node: ";
        cin >> new_node->data; 
        new_node->prev = new_node;
        new_node->next = new_node;
        *head = new_node;
    }
 
    else {
        int num;
        cout << "\nEnter Before Element:  b";
        cin >> num;
        if ((*head)->data == num)
            insert_front(head);
 
        else {
            node* curr = (*head)->next;
 
            while (curr->data != num) {
                if (curr == *head) {
                    cout << "\nEntered Element Not Found "
                            "in List!!\n";
                    return;
                }
                curr = curr->next;
            }
            cout << "\nEnter Data For New Node:";
            cin >> new_node->data;
            new_node->next = curr;
            new_node->prev = curr->prev;
            (curr->prev)->next = new_node;
            curr->prev = new_node;
        }
    }
}
void delete_end(node** head)
{
    if (*head == NULL) {
        cout << "\nList is Empty!!\n";
    }
    else if ((*head)->next == *head) {
        delete *head;
        *head = NULL;
    }
    else {
        node* curr = new node;
        curr = *head;
        while (curr->next != (*head)) {
            curr = curr->next;
        }
        (curr->prev)->next = curr->next;
        (curr->next)->prev = curr->prev;
        delete curr;
    }
}
void display(node* head)
{
    node* curr = head;
    if (curr == NULL)
        cout << "\n List is Empty!!";
    else {
        do {
            cout << curr->data << "<-";
            curr = curr->next;
        } while (curr != head);
    }
}
int main()
{
    int a,b,i,j,n,ch;
    cout<<"Enter size of the doubly linked list: ";
	cin>>n;
    do{
 		cout<<"\n1) Insert an element at the rear end of the list.";
 		cout<<"\n2) Delete an element from the rear end of the list.";
		cout<<"\n3) Insert an element at a given position of the list.";
 		cout<<"\n4) Delete an element from a given position of the list.";
 		cout<<"\n5) Insert an element after another element.";
 		cout<<"\n6) Insert an element before another element.";
 		cout<<"\n7) Print the list."; 
 		cout<<"\n8) Exit.";
		cout<<"\n\n\nEnter a choice: ";
		cin>>ch;
		
		switch(ch) {
			case 1:
				insert_end(&head);
				break;
			case 2:
				delete_end(&head);
				break;
			case 3:
				cout<<"\nEnter position: ";
				cin>>b;
				if (b>n || b<0){
					cout<<"\nInvalid Position!";
					exit(1);
				}	
				cout<<"\nEnter element: ";
				cin>>a;	
				break;
			case 4:
				cout<<"\nEnter position: ";
				cin>>b;
				if (b>n || b<0){
					cout<<"\nInvalid Position!";
					exit(1);
				}	
				break;
			case 5:
				insert_after(&head);
				break;
			case 6:
				insert_before(&head);
				break;
			case 7:
				cout<<"\nDOUBLY LINKED LIST:\n";
				display(head);
				break;
			case 8:
				exit(0);
				break;
			default:
				cout<< "\n\n\nInvalid choice!\n\n\n";
				continue;
		}
		 	}
 	while (ch!=8);
	return 0;	
	 }
