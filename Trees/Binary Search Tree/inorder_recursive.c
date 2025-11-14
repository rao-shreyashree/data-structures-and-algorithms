#include <stdio.h>
#include <stdlib.h>

// structure for tree node
struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// recursive inorder traversal
void inorderRecursive(struct Node* root) 
{
    if (root == NULL) // Base case
        return;   

    inorderRecursive(root->left); // visit left subtree
    printf("%d ", root->data); // visit node
    inorderRecursive(root->right); // visit right subtree
}

/* 
given tree:

     1
    / \
   2   3
  / \
 4   5

*/

int main() 
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder Traversal (Recursive): ");
    inorderRecursive(root);
    printf("\n");

    return 0;
}
