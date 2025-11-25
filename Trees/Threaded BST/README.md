# Threaded BST

This folder contains implementation of **Threaded BST** in C.

## Contents

| File | Description |
|--------------|-------------|
| `threaded_tree.md` | quick notes (algorithm, example, structure) |
| `*.c` files | implementations of iterative and recursive versions of BST operations |

---

## Overview

A Threaded BST is a binary tree where:
- NULL pointers are replaced with threads (pointers to other nodes)
- The threads are represented using dashed lines  
- We use them to prevent the use of stack for inorder iterative traversal 

Types of threaded trees: 
- Right-in threaded Binary tree: right pointer of to point to inorder successor 
- Left-in threaded Binary tree: left pointer of to point to inorder predecessor 
- In Threaded Binary tree: when both pointers are used


---

## How to Use
Navigate and compile any `.c` implementation file:
```bash
gcc file_name.c -o file
file
```
