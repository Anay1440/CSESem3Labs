#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    char q[SIZE];
    int front,rear;
} Queue;

void enqueue(Queue * q, char ch) {
    if (q->rear < SIZE) {
        q->q[++(q->rear)] = ch;
    }
    else {
        printf("Queue is full");
    }
}

char dequeue(Queue * q) {
    return q->q[++(q->front)];
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    char str[100];
    printf("Enter word ");
    scanf("%s",str);
    int i;
    for(i=0;i<strlen(str);i++) {
        enqueue(&q,str[i]);
    }
    char * rev = (char *) malloc(strlen(str) * sizeof(char));
    rev[0] = '\0';
    int ind=0,j;
    char ch;
    char * temp= (char *) malloc(strlen(str) * sizeof(char));
    for(i=0;i<strlen(str);i++) {
        ch = dequeue(&q);
        for(j=ind;j>=1;j--) {
            temp[j] = temp[j-1];
        }
        temp[0] = ch;
        ind++;
    }
    temp[ind] = '\0';
    if (strcmp(str,temp) == 0)
        printf("Word is palindrome");
    else
        printf("Word is not palindrome");
}