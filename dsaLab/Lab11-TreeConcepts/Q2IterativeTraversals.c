#include <stdio.h>
#include <stdlib.h>
#include "TreeFuncs.h"

typedef struct {
    Node ** nodesList;
    int front,rear;
} Queue;

void insertQ(Queue *q, Node * node) {
    if (q->front == -1)
        q->front = 0;
    q->nodesList[++(q->rear)] = node;
}

Node * deleteQ(Queue *q) {
    Node * item = (Node *) malloc(sizeof(Node));
    item = q->nodesList[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else 
        q->front++;
    return item;
}

void iterPreOrder(Node ** tree) {
    Node * temp = (Node *) malloc(sizeof(Node));
    Stack s;
    s.tos = -1;
    push(&s,*tree);
    while (s.tos != -1) {
        temp = pop(&s);
        printf("%d ",temp->val);
        if (temp->right != NULL)
            push(&s,temp->right);
        if (temp->left != NULL)
            push(&s,temp->left);
    }
}

void iterPostOrder(Node **tree) {
    Stack s;
    s.tos = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    Node * temp2 = (Node *) malloc(sizeof(Node));
    temp = *tree;
    do {
        while (temp != NULL) {
            if (temp->right != NULL)
                push(&s,temp->right);
            push(&s,temp);
            temp = temp->left;
        }

        temp = pop(&s);
        if ((temp->right != NULL) && (s.nodes[s.tos] == (temp->right))) {
            temp2 = pop(&s);
            push(&s,temp);
            temp = temp2;
        }   
        else {
            printf("%d ", temp->val);
            temp = NULL;
        }
    } while(s.tos != -1);
}

void iterInOrder(Node **tree) {
    Stack s;
    s.tos = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *tree;
    do {
        if (temp != NULL) {
            push(&s,temp);
            temp = temp->left;
        }
        else {
            if (s.tos != -1) {
                temp = pop(&s);
                printf("%d ",temp->val);
                temp = temp->right;
            }
            else 
                break;
        }
    } while(1);
}

void iterLevelOrder(Node **tree) {
    Queue q;
    q.nodesList = (Node **) malloc(20 * sizeof(Node *));
    q.front = -1;
    q.rear = -1;
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *tree;
    while (temp != NULL) {
        printf("%d ",temp->val);
        if (temp->left != NULL)
            insertQ(&q,temp->left);
        if (temp->right != NULL)
            insertQ(&q,temp->right);
        if (q.front == -1)
            temp = NULL;
        else
            temp = deleteQ(&q);
    }
}

int main() {
    Node * tree = (Node *) malloc(sizeof(Node));
    createBT(&tree);
    printf("Pre Order : ");
    iterPreOrder(&tree);
    printf("\nPost Order : ");
    iterPostOrder(&tree);
    printf("\nInOrder : ");
    iterInOrder(&tree);
    printf("\nLevel Order : ");
    iterLevelOrder(&tree);
}
