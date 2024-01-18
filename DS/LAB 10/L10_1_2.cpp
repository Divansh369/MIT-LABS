#include <iostream>
#include <stdlib.h>
using namespace std;
  
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void printInorder(struct node* n)
{
    if (n == NULL)
        return;
    printInorder(n->left);
    cout << n->data << " ";
    printInorder(n->right);
}
 void printPreorder(struct node* n)
{
    if (n == NULL)
        return;
    cout << n->data << " ";
    printPreorder(n->left);
    printPreorder(n->right);
} 
 void printPostorder(struct node* n)
{
    if (n == NULL)
        return;
    printPostorder(n->left);
    printPostorder(n->right);
    cout << n->data << " ";
} 
int getLeafCount(struct node* node) 
{ 
    if(node == NULL)     
        return 0; 
    if(node->left == NULL && node->right == NULL) 
        return 1;         
    else
        return getLeafCount(node->left)+ getLeafCount(node->right); 
} 
void findParent(struct node* node,
                int val, int parent)
{
    if (node == NULL)
        return;
    if (node->data == val) {
        cout << parent;
    }
    else{
        findParent(node->left, val, node->data);
        findParent(node->right, val, node->data);
    }
}
bool printAncestors(struct node *root, int target)
{
  if (root == NULL)
     return false;
 
  if (root->data == target)
     return true;
  if ( printAncestors(root->left, target) ||
       printAncestors(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
  return false;
}
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int main()
{
    struct node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
  	root->left->right = newNode(5);
  	root->right->left = newNode(6);
  	root->right->right = newNode(7);
	cout<<"Binary Tree:"<< endl;
    cout<<"     1"<< endl;
    cout<<"   /   \\ "<< endl;
    cout<<"  2     3"<< endl;
    cout<<" / \\   / \\  " << endl;
    cout<<"4  5  6   7" << endl;

	cout<<"\n\nPreorder Traversal: ";
	printPreorder(root);
	cout<<"\n\nInorder Traversal: ";
	printInorder(root);
	cout<<"\n\nPostorder Traversal: ";
	printPostorder(root);
	
	cout << "\n\n\nLeaf count of the tree is: "<<getLeafCount(root) << endl; 
	cout << "\n\nDepth of the tree is: "<<maxDepth(root) << endl;

	int i,j;
	cout << "\n\n\nEnter node of which parent is to be found: ";
	cin>>i;
	cout << "\nParent of given node: ";
	findParent(root, i, -1);
	cout << "\n\n\nEnter node of which ancestors are to be found: ";
	cin>>j;
	cout << "\nAncestors of given node: ";
	printAncestors(root, j);
	
    getchar();
    return 0;
}
