#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node ;

typedef struct node Node;

void insertNode(Node * prev,int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->next = prev->next;
    prev->next = new;
}

void display(Node *node) {
    while(node != NULL) {
        printf("%d ",node->val);
        node = node->next;
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
            node->next = NULL;
            continue;
        }
        insertNode(node,temp);
        node = node->next;
    }
}