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

// stack node
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
    struct StackNode* temp = *top; // temp = top
    *top = (*top)->next; // move top down
    struct Node* poppedNode = temp->treeNode; // node = temp node value
    free(temp); // free temp, so its gone
    return poppedNode;
}

struct Node* peek(struct StackNode* top) 
{
    if (top == NULL) 
        return NULL;
    return top->treeNode;
}

int isEmpty(struct StackNode* top) 
{
    return top == NULL;
}

// iterative postorder
void postorderIterative(struct Node* root) 
{
    if (root == NULL) 
        return;

    struct StackNode* stack = NULL;
    struct Node* current = root;
    struct Node* lastVisited = NULL;

    while (!isEmpty(stack) || current != NULL) 
    {
        if (current != NULL) 
        {
            push(&stack, current);
            current = current->left;
        } 
        else 
        {
            struct Node* topNode = peek(stack);
            if (topNode->right != NULL && lastVisited != topNode->right) 
            {
                current = topNode->right;
            } 
            else 
            {
                printf("%d ", topNode->data);
                lastVisited = pop(&stack);
            }
        }
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

    printf("postorder iterative: ");
    postorderIterative(root);
    printf("\n");

    return 0;
}
