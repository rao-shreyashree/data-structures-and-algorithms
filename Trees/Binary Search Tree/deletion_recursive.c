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
struct Node* insertRecursive(struct Node* root, int key) 
{
    if (root == NULL) return newNode(key);

    if (key < root->data)
        root->left = insertRecursive(root->left, key);
    else if (key > root->data)
        root->right =  insertRecursive(root->right, key);
    // duplicates ignored

    return root;
}

// finding inorder successor - smallest in right subtree
struct Node* inorderSuccessor(struct Node* node) 
{
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// recursive BST deletion
struct Node* deleteRecursive(struct Node* root, int key) 
{
    if (root == NULL) 
        return NULL;

    if (key < root->data)
        root->left = deleteRecursive(root->left, key);
    else if (key > root->data)
        root->right = deleteRecursive(root->right, key);
    else 
    {
        // node found: key = root->data

        // Case 1: no child
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            return NULL;
        }

        // Case 2: one child
        if (root->left == NULL) 
        {
            struct Node* temp = root;
            root = root->right;
            free(temp);
            return root;
        } 
        if (root->right == NULL) 
        {
            struct Node* temp = root;
            root = root->left;
            free(temp);
            return root;
        }

        // Case 3: two children
        struct Node* temp = inorderSuccessor(root->right); // inorder successor
        root->data = temp->data;
        root->right = deleteRecursive(root->right, temp->data);
    }

    return root;
}

// inorder traversal (for testing)
void inorder(struct Node* root) 
{
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// main
int main() 
{
    struct Node* root = NULL;

    root = insertRecursive(root, 20);
    root = insertRecursive(root, 10);
    root = insertRecursive(root, 30);
    root = insertRecursive(root, 5);
    root = insertRecursive(root, 15);
    root = insertRecursive(root, 25);
    root = insertRecursive(root, 35);

    printf("Original BST (Inorder): ");
    inorder(root);
    printf("\n");

    // delete leaf node
    root = deleteRecursive(root, 5);
    printf("After deleting 5: ");
    inorder(root);
    printf("\n");

    // delete node with one child
    root = deleteRecursive(root, 30);
    printf("After deleting 30: ");
    inorder(root);
    printf("\n");

    // delete node with two children
    root = deleteRecursive(root, 10);
    printf("After deleting 10: ");
    inorder(root);
    printf("\n");

    return 0;
}
