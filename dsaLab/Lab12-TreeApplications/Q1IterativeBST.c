#include <stdio.h>
#include <stdlib.h>
#include "BSTFuncs.h"

void delAndReplace(Node ** tree, int x) {
    Node * iter = (Node *) malloc(sizeof(Node));
    Node * iter2 = (Node *) malloc(sizeof(Node));
    Node * root = (Node *) malloc(sizeof(Node));

    root = *tree;
    iter = root;
    while (iter->val != x) {
        if (iter->val > x)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if ((iter->left != NULL) && (iter->right != NULL)) {
        iter2 = iter->left;
        while (iter2->right != NULL)
            iter2 = iter2->right;
        iter->val = iter2->val;
    }
}

int main() {
    int n,i,x;
    Node * tree = (Node *) malloc(sizeof(Node));
    tree = NULL;
    printf("Enter number of elements ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for (i=0;i<n;i++) {
        printf("Enter element ");
        scanf("%d",&x);
        insertBST(&tree,x);
    }
    printf("Inorder traversal: ");
    inOrder(tree);
    printf("\nEnter element to delete ");
    scanf("%d",&x);
    delAndReplace(&tree,x);
    printf("Inorder traversal of new tree: ");
    inOrder(tree);
}