#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *q;
    int front,rear;
} Queue;

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
    int x = q->q[q->front];
    int i,ind=q->front;

    for(i=q->front+1;i<=q->rear;i++) 
        q->q[ind++] = q->q[i];
    q->rear--;
    return x;
}

int main() {
    int n,i,j,t;
    printf("Enter size of queue ");
    scanf("%d",&n);
    Queue q;
    q.rear = -1;
    q.front = -1;

    q.q = (int *) malloc(n * sizeof(int));
    for(i=0;i<n;i++) {
        printf("Enter number to insert ");
        scanf("%d",&t);
        enqueue(&q,t);
    }

    for(i=0;i<n-1;i++) {
        for(j=0;j<n-1-i;j++) {
            t = dequeue(&q);
            enqueue(&q,t);
        }
        q.front=i+1;
    }

    printf("Reversed queue is: ");
    for(i=0;i<n;i++) 
        printf("%d ",q.q[i]);
}