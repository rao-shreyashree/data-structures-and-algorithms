#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct TreeNode 
{
    char data[50]; 
    struct TreeNode* left;
    struct TreeNode* right;
} TREENODE;

// stack for tree nodes
TREENODE* stack[100];
int top = -1;

void push(TREENODE* node) 
{
    stack[++top] = node;
}

TREENODE* pop() 
{
    return stack[top--];
}

// creating new node
TREENODE* createNode(char* data) 
{
    TREENODE* newNode = (TREENODE*)malloc(sizeof(TREENODE));
    strcpy(newNode->data, data); // strcpy because the data can be operator or operand (number or variable)
    newNode->left = newNode->right = NULL;
    return newNode;
}

// checking if token is operator
int isOperator(char* str) 
{
    return (strlen(str) == 1 && 
           (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'));
}

// expression tree from postfix
TREENODE* buildTree(char* postfix) 
{
    // we make tokens when we encounter a space in expression
    char* token = strtok(postfix, " ");
    
    while (token != NULL) 
    {
        TREENODE* newNode = createNode(token);
        
        if (isOperator(token)) 
        {
            // operator: pop two operands, make them children
            newNode->right = pop();
            newNode->left = pop();
        }
        
        // push operator back into stack
        push(newNode);
        token = strtok(NULL, " ");
    }
    return pop(); // root of the tree
}

// evaluating expression tree
float evaluate(TREENODE* root) 
{
    if (root == NULL)
        return 0;
    
    if (!isOperator(root->data)) // operand node
        return atof(root->data); // converting char to double 
    
    else 
    {
        // operator node - evaluate left and right subtrees recursively
        float leftVal = evaluate(root->left);
        float rightVal = evaluate(root->right);
        
        switch (root->data[0]) 
        {
            case '+': 
                return leftVal + rightVal;
            case '-': 
                return leftVal - rightVal;
            case '*': 
                return leftVal * rightVal;
            case '/': 
                return leftVal / rightVal;
            default: 
                return 0;
        }
    }
}

// main
int main() 
{
    char postfix[] = "3 4 + 2 * 5 /";  
    // expression: ((3 + 4) * 2) / 5
    
    TREENODE* root = buildTree(postfix);
    
    float result = evaluate(root);
    printf("Result: %.2f\n", result);
    
    return 0;
}
