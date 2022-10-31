#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *q;
    int front,rear;
} Queue;

typedef struct {
    int st[10];
    int tos;
} Stack;

void push(Stack *s,int x) {
    (s->st)[++(s->tos)] = x; 
}

int pop(Stack *s) {
    return s->st[(s->tos)--];
}

void enqueue(Queue * q,int x) {
    if (q->rear == -1) 
        q->front = 0;
    q->q[++(q->rear)] = x;
}

int empty(Queue *q) {
    if ((q->front == -1) || (q->front > q->rear))
        return 1;
    return 0;
}

int dequeue(Queue * q) {
    return (q->q[(q->front)++]);
}

int main() {
    int n,i,t;
    printf("Enter size of queue ");
    scanf("%d",&n);
    Queue q;
    q.rear = -1;
    q.front = -1;

    Stack s;
    s.tos = -1;
    q.q = (int *) malloc(n * sizeof(int));
    for(i=0;i<n;i++) {
        printf("Enter number to insert ");
        scanf("%d",&t);
        enqueue(&q,t);
    }

    while (! empty(&q)) 
        push(&s,dequeue(&q));

    q.rear = -1;
    q.front = -1;

    while (s.tos != -1) 
        enqueue(&q,pop(&s));

    printf("Reversed queue is: ");
    for(i=0;i<n;i++) 
        printf("%d ",q.q[i]);
}