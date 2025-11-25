# Binary Search Tree (BST)

This folder contains implementation of **Binary Search Tree (BST)**
## Contents

| File | Description |
|--------------|-------------|
| `binary_tree.txt` | quick notes on general tree concepts (definition, properties, types) |
| `binary_search_tree.txt` | quick notes specific to Binary Search Trees (traversals, implementation using array and linked list) |
| `common_operations.md` | algorithms and functions for common BST operations (insert, delete, traversals, search, height) |
| `*.c` files | implementations of iterative and recursive versions of BST operations |

---

## Overview
A **Binary Search Tree** is a special kind of binary tree where each node follows the property:
- Left child < Parent   
- Right child > Parent   

This property makes the operations like searching, insertion, and deletion efficient - with an average time complexity of **O(log n)**

---

## Traversals
- **Inorder Traversal** - left -> root -> right
- **Preorder Traversal** - root -> left -> right
- **Postorder Traversal** - left -> right -> root

---

## Complexity
| operation | average case | worst case |
|------------|---------------|------------|
| Insertion  | O(log n) | O(n) |
| Deletion   | O(log n) | O(n) |
| Search     | O(log n) | O(n) |

---

## How to Use

Navigate and compile any `.c` implementation file:

```bash
gcc file_name.c -o file
file
```
