#include <stdio.h>
#include <stdlib.h>
#include "BSTFuncs.h"

int findSuccessor(Node **tree,int x) {
    Node * iter = (Node *) malloc(sizeof(Node));
    Node * prev = (Node *) malloc(sizeof(Node));
    Node * root = (Node *) malloc(sizeof(Node));
    Node * temp = (Node *) malloc(sizeof(Node));
    root = *tree;
    iter = root;
    prev = NULL;
    while (iter->val != x) {
        if (iter->val < x)
            iter = iter->right;
        else 
            iter = iter->left;
    }
    if (iter->right != NULL)
        return iter->right->val;
    else
        return root->right->val;
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
    printf("\nEnter element to find successor of ");
    scanf("%d",&x);
    int a = findSuccessor(&tree,x);
    printf("The sucessor is: %d",a);
}