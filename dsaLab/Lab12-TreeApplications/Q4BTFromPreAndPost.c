#include <stdio.h>
#include <stdlib.h>
#include "../Lab11-TreeConcepts/TreeFuncs.h"

Node * createTree(int pre[100], int post[100], int n, int * preIndex) {
    if (n <= 0)
        return NULL;
    Node * tree = createNode(pre[(*preIndex)++]);
    if (n == 1)
        return tree;
    int i;
    for (i = 0; i < n; i++)
        if (pre[*preIndex] == post[i])
            break;
    if (i < n) {
        tree->left = createTree(pre, post, i + 1, preIndex);
        tree->right = createTree(pre, post + i + 1, n - i - 1, preIndex);
    }
    return tree;
}

int main() {
    int i, n, preInd = 0, pre[100], post[100];

    printf("Enter number of nodes ");
    scanf("%d",&n);

    printf("Enter preorder traversal: ");
    for(i = 0;i < n; i++)
        scanf("%d",&pre[i]);

    printf("Enter postorder traversal: ");
    for(i = 0;i < n;i++)
        scanf("%d",&post[i]);

    Node * tree = createTree(pre, post, n, &preInd);
    
    printf("Inorder traversal: ");
    inOrder(tree); 
}