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

// iterative deletion
struct Node* deleteIterative(struct Node* root, int value) 
{
    struct Node* parent = NULL;
    struct Node* current = root;

    // finding node to delete
    while (current != NULL && current->data != value) 
    {
        parent = current;
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    // node not found
    if (current == NULL) 
        return root; 

    // node with two children
    if (current->left && current->right) 
    {
        struct Node* successorParent = current;
        struct Node* successor = current->right;

        // inorder successor (smallest in right subtree)
        while (successor->left != NULL) 
        {
            successorParent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        current = successor;
        parent = successorParent;
    }

    // node with 0 or 1 child
    struct Node* child = (current->left) ? current->left : current->right;

    if (parent == NULL) 
    {
        // deleting root node
        free(current);
        return child;
    }

    if (parent->left == current)
        parent->left = child;
    else
        parent->right = child;

    free(current);
    return root;
}

// inorder traversal (for us to test)
void inorder(struct Node* root) 
{
    if (!root) 
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// main
int main() 
{
    struct Node* root = NULL;
    root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);

    printf("original BST (inorder): ");
    inorder(root);
    printf("\n");
    /*
         20 -> root
        /  \
      10    30
     / \    / \
    5  15  25  35

    */

    root = deleteIterative(root, 25);
    printf("After deleting 25: ");
    inorder(root);
    printf("\n");
    /*
    deleting leaf node - 25

         20
        /  \
      10    30
     / \      \
    5  15      35
 
    */

    root = deleteIterative(root, 30);
    printf("After deleting 30: ");
    inorder(root);
    printf("\n");
    /*
    deleting node with one child - 30

         20
        /  \
      10    35
     / \      
    5  15     
 
    */

    root = deleteIterative(root, 10);
    printf("After deleting 10: ");
    inorder(root);
    printf("\n");
    /*
    deleting node with two children - 10

         20
        /  \
      15    35
     /      
    5     

    */

    return 0;
}
