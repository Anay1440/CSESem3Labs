#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int q[SIZE];
    int front,rear;
} Queue;

void insertq(Queue * q,int x) {
    if (q->rear <= SIZE-1) {
        q->q[++(q->rear)] = x;
    }
    else {
        printf("Queue is full");
    }
}

int deleteq(Queue * q) {
    int min = q->q[0];
    int i,j,ind=0,t;

    for (i=1;i<=q->rear;i++) {
        if (q->q[i] < min) {
            min = q->q[i];
            ind = i;
        }
    }

    for (i=ind;i<q->rear;i++) {
        q->q[i] = q->q[i+1];
    }

    q->rear--;

    return min;
}

int main() {
    int inp,t;
    Queue q;
    q.front = -1;
    q.rear = -1;
    printf("1. Insertq, 2. Deleteq, -1. Exit");
    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter number to insert ");
            scanf("%d",&t);
            insertq(&q,t);
        }
        else if (inp == 2) {
            if (q.rear == -1)
                printf("Queue is empty");
            else 
                printf("Number deleted : %d",deleteq(&q));
        }
        else 
            inp = -1;
    } while (inp != -1);
}

