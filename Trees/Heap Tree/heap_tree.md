# More about Heap Tree

## Properties of heap

1. the complete binary tree with n nodes has height equal to log2(n)
2. root of heap is always the largest element
3. can be constructed in top-down or bottom-up
4. there can be 2i nodes at i level

## Examples

1. Heap tree:
```

      10
     /   \
    5     7
   / \   /
  4   2 1

```

2. Not heap tree: 
- does not satisfy shape requirement
- 5 does not have left node
```

      10
     /   \
    5     7
     \   /
      2 1

```

3. Not heap tree: 
- does not satisfy parental dominance requirement
- parent 5 < child 6
```

      10
     /   \
    5     7
   / \   /
  6   2 1

```

## Construction of heap tree

### 1. bottom-up approach
1. start from the last non-leaf node (index = n/2 - 1)
2. for each node from last non-leaf down to root:
- compare node with its children (NOT parent)
- if any child > node (for max-heap): swap with largest child
- recursively heapify the affected subtree
- continue until node >= both children or reaches leaf position

### 2. top-down approach
1. empty heap
2. for every new element, make node: 
- if no node exists in tree, then new node is root
- attach new node after last leaf node
- compare with parent
- node > parent: swap key with parent (to maintain parental dominance)
- compare key with new parent 
- swapping continues until key < new parent or it reaches root
