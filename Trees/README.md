# Tree Data Structures

This folder contains implementations of various **Tree Data Structures** in C.  

---

## Overview
- Trees are non-linear data structures that represent hierarchical relationships between the elements.
- It is made up of **nodes** connected by **edges**, with the topmost node known as the **root**.  
- Each node can have child nodes. 
- A node which does not have any child node is called leaf node.

---

## Types of trees
- **Binary Tree** - each node has at most two children
  - **Binary Search Tree (BST)** - special case of binary tree
  - **Expression Tree** - used in implementing mathematical expressions
- **Balanced trees**
  - **AVL Tree** - self-balancing BST
  - **Splay Tree** - self-adjusting BST
  - **Heap Tree** - complete binary tree
- **Trie Tree** - nodes can have many children

---

## Common tree operations
- **Insertion** – adding new nodes to the tree
- **Deletion** – removing nodes while maintaining the overall structure  
- **Search** – to locate for an element  
- **Traversal** – visiting nodes in a specific order:
  - Inorder (Left → Root → Right)
  - Preorder (Root → Left → Right)
  - Postorder (Left → Right → Root)

---

## Time complexities
| operation | average case | worst case |
| --------- | ------------ | ---------- |
| insertion | O(log n)     | O(n)       |
| deletion  | O(log n)     | O(n)       |
| search    | O(log n)     | O(n)       |
| traversal | O(n)         | O(n)       |
