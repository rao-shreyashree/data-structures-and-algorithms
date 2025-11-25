# Algorithms and functions for common BST operations

## 1. insertion:
```psuedo

insert(root, key) 
{
    if (root == NULL)
        create a new node with data = key
        return new node
        
    // to insert in left sub tree
    if key < root->data:
        root->left = insert(root->left, key)
        
    // to insert in right sub tree
    else if key > root->data:
        root->right = insert(root->right, key)
        
    return root
}

```

## 2. deletion: 
```pesudo

delete(root, key) 
{
    if (root == NULL)
        return root
        
    // searching for the node
    if (key < root->data)
        root->left = delete(root->left, key)
    else if (key > root->data)
        root->right = delete(root->right, key)
        
    else {
        // node found ==> key == root->data
            
        // Case 1: no children (leaf node)
        if (root->left == NULL and root->right == NULL)
            free(root)
            return NULL
            
        // Case 2: one child
        else if (root->left == NULL) // has right child
            temp = root->right
            free(root)
            return temp
        else if (root->right == NULL) // has left child
            temp = root->left
            free(root)
            return temp
            
        // Case 3: two children
        else {
            // find inorder successor (smallest in right subtree) 
            // inorder predecessor (largest in left subtree) can also be used
            temp = findMin(root->right)
            root->data = temp->data
            root->right = delete(root->right, temp->data)
        }
    }
        
    return root
}

```

## 3. searching for smallest element in BST
```pseudo

int minimum(struct Node *t)
{
  while(t->left != NULL)
    t=t->left;
  return(t->data);
}

```

## 4. searching for largest element in BST
```pseudo

int maximum(struct Node *t)
{
  while(t->right != NULL)
    t=t->right;
  return(t->data);
}

```

## 5. height of tree
```pseudo

int height(struct Node *t)
{
  if (t == NULL) // no nodes so we return -1
    return -1;
  if( (t->left==NULL) && (t->right==NULL) ) // no child nodes
    return 0;
  return (1 + max( height(r->left), height(r->right) ));
}

```

## 6. calculating number of leaf nodes
```pseudo

int leafCount(struct Node *t)
{
  if(t == NULL) // root is null so no leaves
    return 0;

  if( (t->left == NULL) && (t->right==NULL) ) // root has no children, so root = leaf
    return 1;

  // recursive calls to find leaves in left and right subtrees
  int l = leafCount(t->left); 
  int r = leafCount(t->right);

  return l+r;
}

```

