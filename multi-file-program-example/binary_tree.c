#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_tree.h"


Node * create_node(int key) {
  Node * node = malloc(sizeof * node);
  assert(node != NULL);
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void delete_tree(Node * root) {
  if (root == NULL)
    return;
  delete_tree(root->left);
  delete_tree(root->right);
  free(root);
}

void print_inorder(Node * root) {
    if (root == NULL)
        return;

    print_inorder(root->left);
    printf("%d ", root->key);
    print_inorder(root->right);
}

void print_preorder(Node * root) {
    if (root == NULL)
        return;

    printf("%d ", root->key);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(Node * root) {
    if (root == NULL)
        return;

    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->key);
}
