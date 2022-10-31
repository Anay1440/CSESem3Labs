#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *q;
    int front,rear;
} Queue;

char dequeue(Queue * q) {
    char x = q->q[0];
    int i,ind=0;

    for(i=1;i<=q->rear;i++) 
        q->q[ind++] = q->q[i];
    q->rear--;
    return x;
}

int main() {
    Queue q;
    char str[100];
    printf("Enter word ");
    scanf("%s",str);
    q.rear = strlen(str) - 1;
    q.q = (char *) malloc(strlen(str) * sizeof(char));
    strcpy(q.q,str);
    char * rev = (char *) malloc(strlen(str) * sizeof(char));
    rev[0] = '\0';
    int i;
    char sTemp[2];
    char * temp= (char *) malloc(20 * sizeof(char));
    for(i=0;i<strlen(str);i++) {
        sTemp[0] = dequeue(&q);
        sTemp[1] = '\0';
        strcpy(temp,sTemp);
        strcat(temp,rev);
        strcpy(rev,temp);
    }
    if (strcmp(str,rev) == 0)
        printf("Word is palindrome");
    else
        printf("Word is not palindrome");
}