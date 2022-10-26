#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * items;
    int front,rear,size;
} Queue;

int isFull(Queue q) {
    if (q.rear == q.size - 1) 
        return 1;
    return 0;
}

int isEmpty(Queue q) {
    if (q.front == -1) 
        return 1;
    return 0;
}

void insert(Queue * q,int x) {
    if(isFull(*q)) {
        printf("Error. Queue is full");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = q->rear + 1;
    q->items[q->rear] = x;
}

int delete(Queue * q) {
    if(isEmpty(*q)) {
        printf("Error. Queue is empty");
        return -5;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = q->front + 1;
    }
    return item;
}

void display(Queue q) {
    int i;
    if(isEmpty(q)) {
        printf("Empty queue");
        return;
    }
    for(i=q.front;i<=q.rear;i++) {
        printf("%d ",q.items[i]);
    }
    printf("%d",q.items[i]);
}

int search(Queue *q,int x) {
    Queue temp;
    int n = sizeof((q->items));
    int i,t;
    temp.items = (int *) malloc(n*sizeof(int));
    temp.front = -1;
    temp.rear = -1;
    temp.size = n;

    for(i=0;i<n;i++) {
        if(isEmpty(*q)) 
            return -1;
        t = delete(q);
        insert(&temp,t);
        if (t == x) {
            q->front = -1;
            q->rear = -1;
            while (!isEmpty(temp)) 
                insert(q,delete(&temp));
            return i;
        }
    }
    return -1;
}

int main() {
    int i,temp,n,x;
    Queue q;
    printf("Enter n ");
    scanf("%d",&n);
    q.items = (int *) malloc(n*sizeof(int));
    q.front = -1;
    q.rear = -1;
    q.size = n;
    printf("\nEnter elements of queue\n");
    for(i=0;i<n;i++) {
        printf("Enter number to insert ");
        scanf("%d",&temp);
        insert(&q,temp);
    }
    printf("Enter number to search for ");
    scanf("%d",&x);
    int ind = search(&q,x);
    if (ind == -1)
        printf("Element not in queue");
    else
        printf("Element is at index: %d",ind);
    printf("\nThe queue is: ");
    display(q);
}

