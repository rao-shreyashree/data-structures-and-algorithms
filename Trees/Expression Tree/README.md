# Expression Tree

This folder contains implementation of **Expression tree** in C.

## Contents

| File | Description |
|--------------|-------------|
| `expression_tree.txt` | quick notes (algorithm, example, implementation using stack and linked list) |
| `*.c` files | implementations of iterative and recursive versions of BST operations |

---

## Overview

An **expression tree** is a binary tree used to represent mathematical expressions.
- Built to translate the code as data and then evaluate it
- Stack data structure is used to store nodes' addresses 
- Tree is immutable: to change the expression, another tree has to be constructed 
- Normally postfix expression is used

Tree structure: 
- leaf nodes: Store Operands (numbers or variables: a, b, 3, -19)
- internal nodes: Store Operators (+, -, *, /, ^)
- evaluation: operator is applied to results from its left and right subtrees

---

## How to Use
Navigate and compile any `.c` implementation file:
```bash
gcc file_name.c -o file
file
```
