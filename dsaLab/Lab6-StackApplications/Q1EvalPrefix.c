#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int st[20];
    int tos;
} Stack;

void push(Stack *s,int ch) {
    (s->st)[++(s->tos)] = ch; 
}

int pop(Stack *s) {
    return s->st[(s->tos)--];
}

int isOp(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return 1;
        default: return 0;
    }
}

int operate(int op1,int op2,char operator) {
    switch (operator) {
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '^': return (op1^op2);
        default: return 0;
    }
}

int main() {
    int i,temp;
    char expr[100];
    printf("Enter the prefix expression ");
    scanf("%s",expr);
    Stack s;
    s.tos=-1;
    
    int op1,op2;

    i = strlen(expr)-1;

    do {
        if (isOp(expr[i])) {
            op1 = pop(&s);
            op2 = pop(&s);
            temp = operate(op2,op1,expr[i]);
            push(&s,temp);
        }

        else {
            temp = expr[i] - '0';
            push(&s,temp);
        }
        i--;
    } while( expr[i] != '\0' );

    printf("Final answer: %d",s.st[0]);
}