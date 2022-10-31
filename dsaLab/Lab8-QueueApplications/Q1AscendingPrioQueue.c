#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int q[SIZE];
    int front,rear;
} Queue;

void insertq(Queue * q,int x) {
    if (q->rear == -1) {
        q->q[++(q->rear)] = x;
        return;
    }
    if (q->q[0] > x) {
        q->q[++(q->rear)] = q->q[0];
        q->q[0] = x;
    }
    else 
        q->q[++(q->rear)] = x;
}

int deleteq(Queue * q) {
    int x = q->q[0];
    int i,j,ind=0,t;

    for(i=1;i<=q->rear;i++) 
        q->q[ind++] = q->q[i];
    q->rear = q->rear - 1;
    int min = q->q[0];
    ind = 0;
    for (i=0;i<=q->rear;i++) {
        if (q->q[i] < min) {
            min = q->q[i];
            ind = i;
        }
    }

    q->q[ind] = q->q[0];
    q->q[0] = min;

    return x;
}

int main() {
    int inp,t;
    Queue q;
    q.front = -1;
    q.rear = -1;
    printf("1. insertq, 2. deleteq, -1. Exit");
    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter number to insert ");
            scanf("%d",&t);
            insertq(&q,t);
        }
        else if (inp == 2) 
            printf("Number deleted : %d",deleteq(&q));
        else 
            inp = -1;
    } while (inp != -1);
}

