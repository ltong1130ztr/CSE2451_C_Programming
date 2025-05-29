#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct node {
    int key;
    struct node * left;
    struct node * right;
};

typedef struct node Node;

Node * create_node(int key);
void delete_tree(Node * root);
void print_inorder(Node * root);
void print_preorder(Node * root);
void print_postorder(Node * root);

#endif
