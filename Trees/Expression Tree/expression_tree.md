# Expression Tree Implementation

## Algorithm 
- Each character in expression is read one by one
- Create new node, char is info and left and right are NULL
- If char = operand: 
	- Push into stack 
- If char = operator: 
	- Pop from stack, right child
	- Pop from stack, left child
	- Address of operator is pushed into stack
Finally, stack has address of root of tree

## Example: ab+cd/*

### char 1 = a
a = operand: 
- push to stack
- stack: [a]
  
### char 2 = b
b = operand: 
- push to stack
- stack: [a, b]

### char 3 = +
+ = operator: 
- pop b -> right child
- pop a -> left child

```pseudo
    +
   / \
  a   b
```
- push + to stack
- stack: [+]

### char 4 = c
c = operand: 
- push to stack
- stack: [+, c]
  
### char 5 = d
d = operand: 
- push to stack
- stack: [+, c, d]

### char 6 = /
/ = operator: 
- pop d -> right child
- pop c -> left child

```pseudo
    /
   / \
  c   d
```
- push / to stack
- stack: [+, /]

### char 7 = *
* = operator: 
- pop / -> right child
- pop + -> left child

```pseudo
     *
    / \
   +   /
  / \ / \
 a  b c  d
```
- push * to stack
- stack: [*]

### we have our final expression tree
