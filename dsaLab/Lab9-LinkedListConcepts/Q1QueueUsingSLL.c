//Queue using singly linked list without header node
#include <stdio.h>
#include <stdlib.h>
#include "ListFunctions.h"

int isEmpty(Node * list) {
    if (list == NULL)
        return 1;
    return 0;
}

void enqueue(Node ** list, int x) {
    Node * new = (Node *) malloc(sizeof(Node));
    if (isEmpty(*list)) {
        *list = new;
        (*list)->val = x;
        (*list)->next = NULL;
    }
    else {
        new = *list;
        while (new->next != NULL) 
            new = new->next;
        insertNode(new,x);
    }
}

int dequeue(Node **list) {
    if (isEmpty(*list)) {
        printf("Error. Empty queue");
        return -5;
    }
    else {
        int x = (*list)->val;
        deleteNode(list,*list);
        return x;
    }
}


int main() {
    int x,inp;
    Node * list = (Node *) malloc(sizeof(Node));
    list = NULL;
    printf("1. Enqueue, 2. Dequeue, -1. Exit");
    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter number to enqueue ");
            scanf("%d",&x);
            enqueue(&list,x);
        }
        else if (inp == 2) 
            printf("Dequeued: %d",dequeue(&list));
        else
            inp = -1;
    } while (inp != -1);
}