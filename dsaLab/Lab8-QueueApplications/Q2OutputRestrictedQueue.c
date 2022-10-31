#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[20];
} String;

typedef struct {
    String * q;
    int front,rear;
} Queue;

void enqueue(Queue *q, String s) {
    if (q->rear == -1) 
        q->front = 0;
    strcpy((q->q[++(q->rear)]).str,s.str);
}

void prioEnqueue(Queue *q, String s) {
    int i;
    for(i=q->rear;i>=q->front;i--) 
        q->q[i+1] = q->q[i];
    q->rear++;
    strcpy((q->q[q->front]).str,s.str);
}

String dequeue(Queue *q) {
    String s;
    strcpy(s.str,(q->q[0]).str);
    int i,ind=0;
    for(i=1;i<=q->rear;i++) 
        q->q[ind++] = q->q[i];
    q->rear--;
    return s;
}

int main() {
    int inp,n;
    String t;
    Queue q;
    q.front = -1;
    q.rear = -1;
    printf("Enter max size of queue ");
    scanf("%d",&n);
    q.q = (String *) malloc(n * sizeof(String));
    printf("1. Enqueue, 2. Priority Enqueue, 3. Dequeue, -1. Exit");
    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);

        if (inp == 1) {
            printf("Enter word to enqueue ");
            scanf("%s",t.str);
            enqueue(&q,t);
        }
        else if (inp == 2) {
            printf("Enter word to enqueue ");
            scanf("%s",t.str);
            prioEnqueue(&q,t);
        }
        else if (inp == 3) 
            printf("Word dequeued is : %s",dequeue(&q).str);
        else
            inp = -1;
    } while(inp != -1);
}