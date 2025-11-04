#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create new node
struct Node* createNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// iterative BST insertion
struct Node* iterativeInsert(struct Node* root, int key) 
{
    struct Node* newNode = createNode(key);
    if (root == NULL) 
        return newNode; 

    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL) 
    {
        parent = current;
        if (key < current->data)
            current = current->left; // to left subtree
        else if (key > current->data)
            current = current->right; // to right subtree
    }

    if (key < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// inorder traversal (for us to check)
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

    root = iterativeInsert(root, 20); 
    // newNode = root = 20
    root = iterativeInsert(root, 10); 
    // 10 <- 20
    root = iterativeInsert(root, 30);
    // 10 <- 20 -> 30
    root = iterativeInsert(root, 5);
    // [5 <- 10] <- 20 -> [NULL <- 30 -> NULL] 
    root = iterativeInsert(root, 15);
    // [5 <- 10 -> 15 ] <- 20 -> [NULL <- 30 -> NULL] 

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    // 5, 10, 15, 20, 30 [inorder is ascending order of data]

    return 0;
}
