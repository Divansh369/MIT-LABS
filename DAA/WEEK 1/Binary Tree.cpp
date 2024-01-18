#include <iostream>
 
struct Node {
  int data;
  Node* left;
  Node* right;
 
  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};
 
class BinaryTree {
 public:
  Node* root;
 
  BinaryTree() {
    root = nullptr;
  }
 
  void addNode(int data) {
    Node* newNode = new Node(data);
 
    if (root == nullptr) {
      root = newNode;
    } else {
      Node* focusNode = root;
      Node* parent;
 
      while (true) {
        parent = focusNode;
 
        if (data < focusNode->data) {
          focusNode = focusNode->left;
          if (focusNode == nullptr) {
            parent->left = newNode;
            return;
          }
        } else {
          focusNode = focusNode->right;
          if (focusNode == nullptr) {
            parent->right = newNode;
            return;
          }
        }
      }
    }
  }
  struct Node* search(int data){
   struct Node *current = root;
   printf("Visiting elements: ");
   while(current->data != data){
      if(current != NULL) {
         printf("%d ",current->data);
         if(current->data > data){
            current = current->left;
         }
         else {                
            current = current->right;
         }
         if(current == NULL){
            return NULL;
         }
      }			
   }
   return current;
}
  void preOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
      std::cout << focusNode->data << " ";
      preOrderTraversal(focusNode->left);
      preOrderTraversal(focusNode->right);
    }
  }
   void postOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
      postOrderTraversal(focusNode->left);
      postOrderTraversal(focusNode->right);
      std::cout << focusNode->data << " ";
    }
  }
   void inOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
      inOrderTraversal(focusNode->left);
      std::cout << focusNode->data << " ";
      inOrderTraversal(focusNode->right);
    }
  }
};

int main() {
	int choice, val,before;
	BinaryTree tree;
    printf("Binary Search Tree created! \n");
	do {
    printf("\n\n1. Insert into Tree\n");
    printf("2. Search by value\n");
    printf("3. Display Preorder\n");
    printf("4. Display Inorder\n");
    printf("5. Display Postorder\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
    case 1: 
	printf("Enter the value to be inserted: ");
    scanf("%d", &val);
    tree.addNode(val);
    break;
    case 2:printf("Enter the value to be searched: ");
    scanf("%d", &val); 
    
    if (tree.search(val))
    	printf("Element Found.");
    else
    printf("Element Not Found.");
    break;
    case 3: printf("PreOrder: ");tree.preOrderTraversal(tree.root);
    break;
    case 5: printf("PostOrder: ");tree.postOrderTraversal(tree.root);
    break;
    case 4: printf("InOrder: ");tree.inOrderTraversal(tree.root);
    break;
    case 6: printf("Program Terminated! ");
    break;
    default :printf("Invalid choice ");
    break;
			}                             
    }while(choice != 6);
    return 0;
}
