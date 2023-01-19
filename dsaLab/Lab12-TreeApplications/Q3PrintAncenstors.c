#include <stdio.h>
#include <stdlib.h>
#include "../Lab11-TreeConcepts/TreeFuncs.h"

int findAcenstors(Node *tree, int x) {
    
    if (tree == NULL)
        return 0;
    if (tree->val == x)
        return 1;
    if (findAcenstors(tree->left,x) || findAcenstors(tree->right,x)) {
        printf("%d ",tree->val);
        return 1;
    }
    return 0;
}

int main() {
    int x;
    Node * tree = (Node *) malloc(sizeof(Node));
    createBT(&tree);
    printf("\nEnter element to find ancestors of ");
    scanf("%d",&x);
    findAcenstors(tree,x);
}