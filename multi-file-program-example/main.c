#include <stdio.h>
#include "binary_tree.h"
#include "binary_search_tree.h"

/*
modified from source:
https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
*/

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node * root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    print_inorder(root);

    printf("\nDelete 20\n");
    root = remove_node(root, 20);
    printf("Inorder traversal of the modified tree (removing 20) \n");
    print_inorder(root);

    printf("\nDelete 30\n");
    root = remove_node(root, 30);
    printf("Inorder traversal of the modified tree (removing 30) \n");
    print_inorder(root);

    printf("\nDelete 50\n");
    root = remove_node(root, 50);
    printf("Inorder traversal of the modified tree (removing 50) \n");
    print_inorder(root);
    printf("\n");

    delete_tree(root);

    return 0;
}
