#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int st[SIZE];
    int tos;
} Stack;

void push(Stack *s,int x) {
    (s->st)[++(s->tos)] = x; 
}

int pop(Stack *s) {
    return s->st[(s->tos)--];
}

int main() {
    Stack s1;
    Stack s2;
    s1.tos = -1;
    s2.tos = -1;
    int inp,t;
    printf("\n1. Enqueue, 2. Dequeue, -1. Exit\n");
    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter number to enqueue ");
            scanf("%d",&t);
            if (s1.tos < SIZE)
                push(&s1,t);
            else
                printf("\nQueue is full");
        }
        else if (inp == 2) {
            if (s2.tos == -1) {
                while (s1.tos != -1) {
                    push(&s2,pop(&s1));
                }
            }
            if (s2.tos != -1)
                printf("Number dequeued: %d",pop(&s2));
            else
                printf("Queue is empty");
        }
        else 
            inp = -1;
    } while (inp != -1);
}