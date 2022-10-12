#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char st[20];
    int tos;
} Stack;

void push(Stack *s,char ch) {
    (s->st)[++(s->tos)] = ch; 
}

char pop(Stack *s) {
    return s->st[(s->tos)--];
}

char viewTop(Stack *s) {
    return s->st[(s->tos)];
}

int getPrec(char ch) {
    switch(ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
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
    char expr[20], ans[20],ch,pref[20];
    printf("Enter the infix expression ");
    scanf("%s",expr);
    Stack s;
    s.tos=-1;
    
    int p1=0,p2=0;

    i = strlen(expr)-1;

    do {

        if (expr[i] == ')') {
            push(&s,')');
        }
        else if (expr[i] == '(') {
            while (viewTop(&s) != ')') {
                ans[ind++] = pop(&s);
            }
            ch=pop(&s);
        }
        else if (isOp(expr[i])) {
            do {
                if (s.tos != -1) {
                    p1 = getPrec(viewTop(&s));
                    p2 = getPrec(expr[i]);
                    if (p1>=p2)
                        ans[ind++] = pop(&s);
                }
            } while(p1>p2);
            push(&s,expr[i]);
        }
        else {
            ans[ind++] = expr[i];
        }
        i--;
    } while( expr[i] != '\0' );

    while (s.tos >= 0) {
        ans[ind++] = s.st[s.tos--];
    }
    ans[ind] = '\0';
    int len = (int) strlen(ans);
    printf("Prefix expression is: ");
    for(i=len-1;i>=0;i--) {
        printf("%c",ans[i]);
    }

    //printf("Final answer: %s",pref);
}