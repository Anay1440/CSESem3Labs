#include <stdio.h>
#include <stdlib.h>
#include "TreeFuncs.h"

Node * copy(Node * node) {
    if (node == NULL)
        return NULL;
    Node * new = createNode(node->val);
    new->left = copy(node->left);
    new->right = copy(node->right);

    return new;
}

int eqCheck(Node * node1, Node * node2) {
    if (node1 == NULL && node2 == NULL) 
        return 1;
    if (node1 == NULL || node2 == NULL) 
        return 0;
    if (node1->val != node2->val) 
        return 0;
    return eqCheck(node1->left, node2->left) && eqCheck(node1->right, node2->right);
}


int main() {
    Node * tree = (Node *) malloc(sizeof(Node));
    Node * treeCopy = (Node *) malloc(sizeof(Node));
    createBT(&tree);
    printf("Inorder : ");
    inOrder(tree);
    treeCopy = copy(tree);
    printf("\nInorder of copy: ");
    inOrder(treeCopy);
    int check = eqCheck(tree,treeCopy);
    if (check)
        printf("\nBinary trees are equal");
    else
        printf("\nBinary trees are not equal");
}