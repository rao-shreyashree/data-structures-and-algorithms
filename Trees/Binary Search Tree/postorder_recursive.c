#include <stdio.h>
#include <stdlib.h>

// tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// recursive postorder
void postorderRecursive(struct Node* root) 
{
    if (root == NULL) 
        return;
    postorderRecursive(root->left); // visit left
    postorderRecursive(root->right); // visit right
    printf("%d ", root->data); // visit root
}

// main
int main() 
{
    /* 
             4
            / \
           2   5
          / \
         1   3
    */
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    printf("Postorder Recursive: ");
    postorderRecursive(root);
    printf("\n");

    return 0;
}
