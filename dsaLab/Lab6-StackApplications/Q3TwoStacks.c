#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * st;
    int tos1,tos2,n;
} Stack;

int checkOverflow(Stack *s) {
    if (s->tos2 == (s->tos1)+1)
        return 1;
    return 0;
}

void push1(Stack *s,int x) {
    if (checkOverflow(s)) {
        printf("Error. Overflow");
        return;
    }
    (s->st)[++(s->tos1)] = x;
}

int pop1(Stack *s) {
    if (s->tos1 == -1) {
        printf("Error. Underflow");
        return -5;
    }
    return (s->st)[(s->tos1)--];
}

void push2(Stack *s,int x) {
    if (checkOverflow(s)) {
        printf("Error. Overflow");
        return;
    }
    (s->st)[--(s->tos2)] = x;
}

int pop2(Stack *s) {
    if (s->tos2 == s->n) {
        printf("Error. Underflow");
        return -5;
    }
    return (s->st)[(s->tos2)++];
}

int main() {
    int n,inp=-1,temp;
    Stack s;
    printf("Enter max stack size ");
    scanf("%d",&n);
    s.st = (int *) malloc(n*sizeof(int));
    s.tos1=-1;
    s.tos2=n;
    s.n = n;
    printf("1. Push1, 2. Push2, 3. Pop1, 4. Pop2, -1. Exit");
    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter number to push ");
            scanf("%d",&temp);
            push1(&s,temp);
        }
        else if (inp == 2) {
            printf("Enter number to push ");
            scanf("%d",&temp);
            push2(&s,temp);
        }
        else if (inp == 3) {
            printf("\nNumber popped is: %d",pop1(&s));
        }
        else if (inp == 4) {
            printf("\nNumber popped is: %d",pop2(&s));
        }
        else {
            inp = -1;
        }
    } while(inp != -1);
    return 0;
}