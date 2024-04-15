#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1; 
    return(node);
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    return x;
}
 
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left),  
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}
 
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    // Update height
    node->height = 1 + max(height(node->left),
                        height(node->right));
 
    /* Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}

void preorder(struct Node *root) {
  if (root != NULL)
  {
  	cout<< root -> key << " "; 
    preorder(root -> left); 
    preorder(root -> right); 
  }
}

void postorder(struct Node *root) {
  if (root != NULL)
  {
    postorder(root -> left); 
    postorder(root -> right); 
    cout<< root -> key << " "; 
  }
}

void inorder(struct Node *root) {
  if (root != NULL)
  {
    inorder(root -> left); 
    cout<< root -> key << " "; 
    inorder(root -> right); 
  }
}

void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void levelorder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{
    struct Node* root=NULL;
    int n,r;
    cout<<"Enter number of nodes: ";
 	cin>>n;
 	for (int i=0;i<n;i++){
		cout<<"Enter node: ";
 		cin>>r;
 		root=insert(root,r);
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
