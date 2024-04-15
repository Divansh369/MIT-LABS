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

 int findHeightLeft(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->left; 
        }
        return hght; 
    }
 int findHeightRight(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->right; 
        }
        return hght; 
    }
    
int numOfNodes(node* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        int leftNodes = numOfNodes(root->left);
        int rightNodes = numOfNodes(root->right);
        
        return 1 + leftNodes + rightNodes; 
    }
 
int main()
{
 
    /* Constructed binary tree is
             0
            / \
           1   2
          / \ / \
         3  4 5  6
    */
    struct node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
 
    int height = 0;
 
    cout << "Number of nodes in given binary tree:  "
         << numOfNodes(root);

    return 0;
}
