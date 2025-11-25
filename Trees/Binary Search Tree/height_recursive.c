#include <stdio.h>
#include <stdlib.h>

// binary tree node
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

/*
function to calculate height

root = 4

root->left = 2, root->right = 5
leftHeight = height(root->left) 
           = height(2)
           = height(1)
           = height(NULL) = 2
rightHeight = height(root->right) 
           = height(5)
           = height(NULL) = 1

leftHeight > rightHeight ? leftHeight : rightHeight
2 > 1 ? 2 : 1 ==> 2

so 1 + 2 = 3

height = 3

*/

int height(struct Node* root) 
{
    if (root == NULL)
        return -1; 

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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

    printf("Height of the tree: %d\n", height(root));

    return 0;
}
