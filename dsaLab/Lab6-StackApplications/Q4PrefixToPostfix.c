#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char st[20][20];
    int tos;
} Stack;

void push(Stack *s,char *ch) {
    strcpy(s->st[++(s->tos)],ch);
}

char * pop(Stack *s) {
    int i=0;
    char * ch = (char *) malloc (20*sizeof(char));
    strcpy(ch,s->st[(s->tos)--]);
    int len = (int) strlen(ch);
    return ch;
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

int main() {
    int i,ind=0;
    char expr[20],ch,*temp;
    printf("Enter the prefix expression ");
    scanf("%s",expr);
    
    Stack s;
    s.tos=-1;
    
    char op1[20],op2[20];

    i = strlen(expr)-1;

    do {

        if (expr[i] == ')') {
            continue;
        }
        else if (expr[i] == '(') {
            continue;
        }
        else if (isOp(expr[i])) {
            
            strcpy(op1,pop(&s));
            strcpy(op2,pop(&s));
            int i2,i3=0,ind2=0;
            int len = strlen(op1) + strlen(op2) + 1;
            temp = (char *) calloc (len,sizeof(char));
            strcat(temp,op1);
            strcat(temp,op2);
            temp[len-1] = expr[i];
            push(&s,temp);
        }
        else {
            temp = (char *) malloc (2*sizeof(char));
            temp[0] = expr[i];
            temp[1] = '\0';
            push(&s,temp);
        }
        i--;
    } while( i >= 0 );

    printf("Postfix expression is: ");
    printf("%s",s.st[0]);

}