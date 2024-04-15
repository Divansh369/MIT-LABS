#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
 
struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
struct node* insertNode(struct node* root, int value)
{
	if (root==NULL){
		return newNode(value);
	}
    if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    else if (value < root->data){
        root->left = insertNode(root->left, value);
    }
    return root;
}

void inorder(struct node *root) {
  if (root != NULL)
  {
    inorder(root -> left); 
    cout<< root -> data << " "; 
    inorder(root -> right); 
  }
}

void preorder(struct node *root) {
  if (root != NULL)
  {
  	cout<< root -> data << " "; 
    preorder(root -> left); 
    preorder(root -> right); 
  }
}

void postorder(struct node *root) {
  if (root != NULL)
  {
    postorder(root -> left); 
    postorder(root -> right); 
    cout<< root -> data << " "; 
  }
}

int height(node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void levelorder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{
    struct node* root=NULL;
    int n,r;
    cout<<"Enter number of nodes: ";
 	cin>>n;
 	for (int i=0;i<n;i++){
 		if (i==0){
 			cout<<"Enter value of root: ";
 			cin>>r;
 			root=insertNode(root,r);
		 }
		else{
			cout<<"Enter node: ";
 			cin>>r;
 			insertNode(root,r);
		}
 			
	 }
    cout<<"\nPreorder traversal of given BST is: "<<endl;
    preorder(root);
    cout<<"\nInorder traversal of given BST is: "<<endl;
    inorder(root);
	cout<<"\nPostorder traversal of given BST is: "<<endl;
    postorder(root);
    cout<<"\nLevel-order traversal of given BST is: "<<endl;
    levelorder(root);
    return 0;
}
