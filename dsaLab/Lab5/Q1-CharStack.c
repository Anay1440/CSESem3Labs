#include <stdio.h>

typedef struct {
    char st[100];
    int tos;
} Stack;

int isFull(Stack s) {
    if ((s.tos+1) > 99)
        return 1;
    return 0; 
}

int isEmpty(Stack s) {
    if (s.tos == -1)
        return 1;
    return 0;
}


void push(Stack s,int x) {
    if (isFull(s))
        printf("Error. Overlow ");
    else {
        s.tos +=1;
        s.st[s.tos] = x;
    }
}

void pop(Stack s) {
    if (isEmpty(s))
        printf("Error. Underflow ");
    else {
        s.st[s.tos] = -5;
        s.tos-=1;
    }
}

void display(Stack s) {
    int i;
    for (i=0;i<=s.tos;i++) {
        printf("%d ",s.st[i]);
    }
}

int main() {

    Stack s;
    int input;

    do {
        printf("\nEnter 1 to push, 2 to pop, 3 to display, and -1 to exit ");
        scanf("%d",&input);
    } while (input != -1);
    return 0;
}