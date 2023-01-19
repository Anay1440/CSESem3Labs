#include <stdio.h>
#include <stdlib.h>
#include "BSTFuncs.h"

int findSuccessor(Node **tree,int x) {
    Stack nodeStack;
    nodeStack.tos = -1;
    Node * iter = (Node *) malloc(sizeof(Node));
    Node * succ = (Node *) malloc(sizeof(Node));
    iter = *tree;
    push(&nodeStack,iter);

    while (iter != NULL) {
        if (iter->val > x) {
            succ = iter;
            iter = iter->left;
        }
        else if (iter->val < x) {
            iter = iter->right;
        }
        else {
            if (iter->right != NULL) {
                succ = iter->right;
                while (succ->left != NULL) {
                    succ = succ->left;
                }
            }
            break;
        }
    }
    if (succ == NULL) {
        return -1;
    } else {
        return succ->val;
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
    printf("\nEnter element to find successor of ");
    scanf("%d",&x);
    int a = findSuccessor(&tree,x);
    printf("The sucessor is: %d",a);
}