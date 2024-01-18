#include <iostream>
using namespace std;

struct node {
  int data; 
  struct node *right_child; 
  struct node *left_child; 
};

struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left_child = NULL;
    node->right_child = NULL;
 
    return (node);
}

struct node* insert(struct node * root, int x) {
  if (root == NULL)
    return newNode(x);
  else if (x > root -> data) 
    root -> right_child = insert(root -> right_child, x);
  else 
    root -> left_child = insert(root -> left_child, x);
  return root;
}

void inorder(struct node *root) {
  if (root != NULL)
  {
    inorder(root -> left_child); 
    cout<< root -> data << " "; 
    inorder(root -> right_child); 
  }
}

int height(struct node* root){
int lh = 0, rh = 0,h;
    if (root == NULL) {
        h= 0;
        return 0; 
    }
 
    lh = height(root->left_child);
    rh = height(root->right_child);
    h = max(lh, rh) + 1;
    return h;
}

int main() {
   int n,i,x,r;
   cout<<"Enter value of root: ";
   cin>> r;
   struct node *root;
  root = newNode(r);
  cout<<"Enter number of nodes: ";
  cin>>n;
  for (i=0;i<n;i++){
  	cout<<"Enter value: ";
  	cin>>x;
  	insert(root,x);
  }
  cout<<"Inorder traversal of given BST is: ";
  inorder(root);
  cout<<"\nHeight of given BST is: "<<height(root);
  return 0;
}
