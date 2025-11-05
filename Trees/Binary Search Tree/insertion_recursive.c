#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create new node
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// recursive BST insertion
struct Node* recursiveInsert(struct Node* root, int value) 
{
    struct Node* newNode = createNode(value);
    if (root == NULL) 
        return newNode; 

    if (value < root->data)
        root->left = recursiveInsert(root->left, value); // to left subtree
    else if (value > root->data)
        root->right = recursiveInsert(root->right, value); // to right subtree
    
    // if value == root->data, do nothing (no allowing duplicates)

    return root;
}

// inorder traversal (for us to test)
void inorder(struct Node* root) 
{
    if (root == NULL) 
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// main
int main() 
{
    struct Node* root = NULL;

    root = recursiveInsert(root, 20);
    root = recursiveInsert(root, 10);
    root = recursiveInsert(root, 30);
    root = recursiveInsert(root, 5);
    root = recursiveInsert(root, 15);

    printf("inorder traversal: ");
    inorder(root);
    printf("\n");
    // 5, 10, 15, 20, 30 [inorder is ascending order of data]

    return 0;
}
