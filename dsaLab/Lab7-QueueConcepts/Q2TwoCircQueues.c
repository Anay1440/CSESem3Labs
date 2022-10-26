#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * items;
    int front1,rear1,front2,rear2,hSize;
} Queue;

int isFull1(Queue q) {
    if ((q.front1 == q.rear1 + 1) || (q.front1 == 0 && q.rear1 == q.hSize - 1)) 
        return 1;
    return 0;
}

int isEmpty1(Queue q) {
    if (q.front1 == -1) 
        return 1;
    return 0;
}

int isFull2(Queue q) {
    if ((q.front2 == q.rear2 + 1) || (q.front2 == q.hSize && q.rear2 == (q.hSize * 2) - 1)) 
        return 1;
    return 0;
}

int isEmpty2(Queue q) {
    if (q.front2 == q.hSize-1) 
        return 1;
    return 0;
}

void insertcq1(Queue * q,int x) {
    if(isFull1(*q)) {
        printf("Error. Queue is full");
        return;
    }
    if (q->front1 == -1)
        q->front1 = 0;
    q->rear1 = (q->rear1 + 1) % q->hSize;
    q->items[q->rear1] = x;
}

void insertcq2(Queue * q,int x) {
    if(isFull2(*q)) {
        printf("Error. Queue is full");
        return;
    }
    if (q->front2 == q->hSize-1)
        q->front2 = q->hSize;
    q->rear2 = ((q->rear2 + 1) % q->hSize)+q->hSize;
    q->items[q->rear2] = x;
}

int deletecq1(Queue * q) {
    if(isEmpty1(*q)) {
        printf("Error. Queue is empty");
        return -5;
    }
    int item = q->items[q->front1];
    if (q->front1 == q->rear1) {
        q->front1 = -1;
        q->rear1 = -1;
    }
    else 
        q->front1 = (q->front1 + 1) % q->hSize;
    return item;
}

int deletecq2(Queue * q) {
    if(isEmpty2(*q)) {
        printf("Error. Queue is empty");
        return -5;
    }
    int item = q->items[q->front2];
    if (q->front2 == q->rear2) {
        q->front2 = q->hSize-1;
        q->rear2 = q->hSize-1;
    }
    else
        q->front2 = ((q->front2 + 1) % q->hSize) + q->hSize;
    return item;
}

void displaycq(Queue q) {
    int i;
    printf("\nQueue 1: ");
    if(isEmpty1(q)) {
        printf("Empty queue");
    }
    else {

        for(i=q.front1;i!=q.rear1;i=(i+1)%q.hSize) {
            printf("%d ",q.items[i]);
        }
        printf("%d",q.items[i]);
    }
    printf("\nQueue 2: ");
    if(isEmpty2(q)) {
        printf("Empty queue");
    }
    else {

        for(i=q.front2;i!=q.rear2;i=((i+1)%(q.hSize * 2))+q.hSize) {
            printf("%d ",q.items[i]);
        }
        printf("%d",q.items[i]);
    }
}

int main() {
    int temp,inp,n;
    Queue q;
    printf("Enter n ");
    scanf("%d",&n);
    q.items = (int *) malloc(n*sizeof(int));
    q.front1 = -1;
    q.rear1 = -1;
    q.hSize = n/2;
    q.front2 = q.hSize - 1;
    q.rear2 = q.hSize - 1;
    printf("\n1. Insert1, 2. Insert2, 3. Delete1, 4. Delete2, 5. Display, -1. Exit");
    do {
        printf("\nEnter choice. ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter number to insert ");
            scanf("%d",&temp);
            insertcq1(&q,temp);
        }
        else if (inp == 2) {
            printf("Enter number to insert ");
            scanf("%d",&temp);
            insertcq2(&q,temp);
        }
        else if (inp == 3)
            printf("Element deleted is: %d",deletecq1(&q));
        else if (inp == 4)
            printf("Element deleted is: %d",deletecq2(&q));
        else if (inp == 5) 
            displaycq(q);
        else    
            inp = -1;
    } while(inp != -1);
}