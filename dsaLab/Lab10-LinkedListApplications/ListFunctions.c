//list functions for DLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *right;
    struct node *left;
} node ;

typedef struct node Node;

void insertNode(Node * prev,int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->right = prev->right;
    new->left = prev;
    prev->right = new;
}

void insertEnd(Node ** list, int x) {
    Node * temp = (Node *) malloc(sizeof(Node));
    Node * new = (Node *) malloc(sizeof(Node));
    temp = *list;
    while (temp->right != NULL) 
        temp = temp->right;
    new->val = x;
    new->left = temp;
    temp->right = new;
    new->right = NULL;
}

void insertFront(Node ** list, int x) {
    Node * temp = (Node *) malloc(sizeof(Node));
    temp->val = x;
    temp->left = NULL;
    if (*list != NULL) {
        temp->right = *list;
        (*list)->left = temp;
    }
    *list = temp;
}

void display(Node *node) {
    printf("The list is: ");
    while(node != NULL) {
        printf("%d ",node->val);
        node = node->right;
    }
    printf("\n");
}

void input(Node *node,int n) {
    int i,temp;
    for (i=0;i<n;i++) {
        printf("Enter value to add ");
        scanf("%d",&temp);
        if (i == 0) {
            node->val = temp;
            node->right = NULL;
            node->left = NULL;
            continue;
        }
        insertNode(node,temp);
        node = node->right;
    }
}

void deleteNode(Node ** list, Node * tbd) {
    if (*list == tbd) {
        *list = (*list)->right;
        (*list)->left = NULL;
    }
    else {
        Node * temp = (Node *) malloc(sizeof(Node));
        temp = *list;
        while (temp->right != NULL) {
            if (temp->right == tbd) {
                temp->right = tbd->right;
                tbd->left = temp;
                break;
            }
            temp = temp->right;
        }
    }
    printf("Value deleted: %d",tbd->val);
    free(tbd);
}
