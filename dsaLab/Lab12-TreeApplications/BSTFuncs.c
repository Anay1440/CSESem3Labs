#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node ;

typedef struct node Node;

Node * createNode(int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inOrder(Node *tree) {
    if (tree != NULL) {
        inOrder(tree->left);
        printf("%d ",tree->val);
        inOrder(tree->right);
    }
}

void postOrder(Node *tree) {
    if (tree != NULL) {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ",tree->val);
    }
}

void preOrder(Node *tree) {
    if (tree != NULL) {
        printf("%d ",tree->val);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void insertBST(Node **tree,int x) {
    Node * iter = (Node *) malloc(sizeof(Node));
    Node * prev = (Node *) malloc(sizeof(Node));
    Node * root = (Node *) malloc(sizeof(Node));
    Node * temp = (Node *) malloc(sizeof(Node));
    
    temp = createNode(x);
    prev = NULL;
    root = *tree;
    iter = root;
    while (iter != NULL) {
        prev = iter;
        if (iter->val > x)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if (prev == NULL) 
        *tree = temp;
    else if (x < prev->val) 
        if (prev->left != NULL) {
            temp->left = prev->left;
            prev->left = temp;
        }
        else 
            prev->left = temp;
    else {
        if (prev->right != NULL) {
            temp->right = prev->right;
            prev->right = temp;
        }
        else 
            prev->right = temp;

    }
}