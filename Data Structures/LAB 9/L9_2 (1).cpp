#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};
void create_node(int x, int y, struct Node** temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL) {
        r = (struct Node*)malloc(sizeof(struct Node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else {
        r->coeff = x;
        r->pow = y;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}
void polyadd(struct Node* poly1, struct Node* poly2,
             struct Node* poly)
{
    while (poly1->next && poly2->next) {
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly->next = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next) {
        if (poly1->next) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next
            = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}
void show(struct Node* node)
{
    while (node->next != NULL) {
        cout<<node->coeff<<"*(X^"<<node->pow<<")";
        node = node->next;
        if (node->coeff > 0) {
            if (node->next != NULL)
                cout<<"+";
        }
    }
}
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    int a,b,i,j,x,y;
    char alpha[26];
    cout<<"Example representation of second degree polynomial: A(X^2)+B(X^1)+C.\n\n\n";
    cout<<"\nEnter degree of first polynomial: ";
	cin>>a;
	if (a>26){
		cout<<"\nPolynomial degree is too high!";
		exit(1);
		}
	else if (a<0){
		cout<<"\nPolynomial degree cannot be negative!";
		exit(1);
		}
	for (i=65 ; i<91 ; i++) {
    	alpha[i-65] = char(i);
	}
	for (i=a;i>=0;i--){
		cout<<"Enter value of "<<alpha[a-i]<<": ";
		cin>>x;
		create_node(x, i, &poly1);
	}
	cout<<"\nEnter degree of second polynomial: ";
	cin>>b;
	if (b>26){
		cout<<"\nPolynomial degree is too high!";
		exit(1);
		}
	else if (b<0){
		cout<<"\nPolynomial degree cannot be negative!";
		exit(1);
		}
	for (j=b;j>=0;j--){
		cout<<"Enter value of "<<alpha[b-j]<<": ";
		cin>>y;
		create_node(y, j, &poly2);
	}
	cout<<"\nFirst polynomial: ";
	show(poly1);
	cout<<"\nSecond polynomial: ";
	show(poly2);
    poly = (struct Node*)malloc(sizeof(struct Node));
    polyadd(poly1, poly2, poly);
    printf("\n\n\nSum of both polynomials: ");
    show(poly);
    
    return 0;
}
