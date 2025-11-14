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

// stack Node
struct StackNode {
    struct Node* treeNode;
    struct StackNode* next;
};

void push(struct StackNode** top, struct Node* node) 
{
    struct StackNode* newStackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newStackNode->treeNode = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

struct Node* pop(struct StackNode** top) 
{
    if (*top == NULL) 
        return NULL;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct Node* node = temp->treeNode;
    free(temp);
    return node;
}

// iterative preorder
void preorderIterative(struct Node* root) 
{
    if (root == NULL) 
        return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (stack != NULL) 
    {
        struct Node* curr = pop(&stack); // initially curr is root
        printf("%d ", curr->data); // root->data is printed

        // pushing right first so left is processed first
        if (curr->right) 
            push(&stack, curr->right);
        if (curr->left) 
            push(&stack, curr->left);
    }
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
    
    printf("Preorder Iterative: ");
    preorderIterative(root);
    printf("\n");

    return 0;
}
