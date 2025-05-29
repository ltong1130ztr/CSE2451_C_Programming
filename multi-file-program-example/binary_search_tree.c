#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

/*

modified from source:
https://www.geeksforgeeks.org/binary-search-tree-data-structure/
https://www.geeksforgeeks.org/deletion-in-binary-search-tree/

*/

Node * search(Node * root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

// insert a new node to BST
Node * insert(Node * root, int key) {
    if (root == NULL)
        return create_node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    // if key == root->key, no insertion
    return root;
}


// utility function not visible outside binary_search_tree.c
Node * minValueNode(Node * node) {
    Node * current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node * remove_node(Node * root, int key) {
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = remove_node(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = remove_node(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node * temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        Node * temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = remove_node(root->right, temp->key);
    }
    return root;
}
