#include <stdio.h>
#include <string.h>

#define size 7

typedef struct {
    char str[10];
} String;

typedef struct {
    String s[size];
    int front,rear;
} Queue;

int isFull(Queue q) {
    if ((q.front == q.rear + 1) || (q.front == 0 && q.rear == size - 1)) 
        return 1;
    return 0;
}

int isEmpty(Queue q) {
    if (q.front == -1) 
        return 1;
    return 0;
}

void insertcq(Queue * q,char string[10]) {
    if(isFull(*q)) {
        printf("Error. Queue is full");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % size;
    strcpy((q->s[q->rear]).str,string);
}

void deletecq(Queue * q) {
    if(isEmpty(*q)) {
        printf("Error. Queue is empty");
        return;
    }
    char string[10];
    strcpy(string,(q->s[q->front]).str);
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else 
        q->front = (q->front + 1) % size;
    printf("Deleted string: %s",string);
}

void displaycq(Queue q) {
    int i;
    if(isEmpty(q)) {
        printf("Empty queue");
        return;
    }
    for(i=q.front;i!=q.rear;i=(i+1)%size)
        printf("%s ",q.s[i].str);
    printf("%s",q.s[i].str);
}

int main() {
    int inp;
    char temp[10];
    Queue q;
    q.front = -1;
    q.rear = -1;
    printf("\n1. Insert, 2. Delete, 3. Display, -1. Exit");
    do {
        printf("\nEnter choice. ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter string to insert ");
            scanf("%s",temp);
            insertcq(&q,temp);
        }
        else if (inp == 2) 
            deletecq(&q);
        else if (inp == 3) 
            displaycq(q);
        else    
            inp = -1;
    } while(inp != -1);
}

