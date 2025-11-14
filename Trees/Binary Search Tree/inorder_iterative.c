#include <stdio.h>
#include <stdlib.h>

// structure for tree node
struct Node {
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

// stack implementation for storing tree nodes
struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

struct Stack* createStack(int capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node) 
{
    stack->array[++(stack->top)] = node;
}

struct Node* pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
        return NULL;
    return stack->array[stack->top--];
}

/*
Iterative Inorder Traversal

         4
        / \
       2   5
      / \
     1   3

stack->top = -1
current = root = 4

first iteration:
    push 4
    stack = [4]
    stack->top = 0
    current = left = 2

second iteration:
    push 2
    stack = [2][4]
    stack->top = 1
    current = left = 1

third iteration:
    push 1
    stack = [1][2][4]
    stack->top = 2
    current = left = NULL

    current is NULL, so comes out of inner while
    current = POP = 1 ==> 1
    stack = [2][4]

    visiting right subtree
    current = right = NULL

    current is NULL, so doesnt go to inner while
    current = POP = 2 ==> 1 2
    stack = [4]

    visiting right subtree
    current = right = 3

fourth iteration:
    push 3
    stack = [3][4]
    stack->top = 1
    current = left = NULL

    current is NULL, so comes out of inner while
    current = POP = 3 ==> 1 2 3
    stack = [4]

    visiting right subtree
    current = right = NULL

    current is NULL, so doesnt go to inner while
    current = POP = 4 ==> 1 2 3 4
    stack = []

    visiting right subtree
    current = right = 5

fifth iteration:
    push 5
    stack = [5]
    stack->top = 0
    current = left = NULL

    current is NULL, so comes out of inner while
    current = POP = 5 ==> 1 2 3 4 5
    stack = []

    visiting right subtree
    current = right = NULL

    now current is NULL and stack is []
    so exits outer while

*/
void inorderIterative(struct Node* root) 
{
    struct Stack* stack = createStack(100); 
    struct Node* current = root;

    while (current != NULL || !isEmpty(stack)) 
    {
        // reach the leftmost node of the current node
        while (current != NULL)     
        {
            push(stack, current);
            current = current->left;
        }

        // current must be NULL at this point
        current = pop(stack);
        printf("%d ", current->data);

        // visit the right subtree
        current = current->right;
    }
}

// main
int main() {
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

    printf("inorder traversal (iterative): ");
    inorderIterative(root);

    return 0;
}
