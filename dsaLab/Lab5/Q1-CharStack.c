#include <stdio.h>

typedef struct {
    char st[10];
    int tos;
} Stack;

int isFull(Stack s) {
    if ((s.tos+1) > 9)
        return 1;
    return 0; 
}

int isEmpty(Stack s) {
    if (s.tos == -1)
        return 1;
    return 0;
}


Stack push(Stack s) {
    char x;
    if (isFull(s))
        printf("Error. Overlow ");
    else {
        printf("Enter character to push onto stack ");
        scanf(" %c",&x);
        s.tos = s.tos + 1;
        s.st[s.tos] = x;
    }
    return s;
}

Stack pop(Stack s) {
    if (isEmpty(s))
        printf("Error. Underflow ");
    else {
        printf("The popped element is: %c",s.st[s.tos]);
        s.st[s.tos] = -5;
        s.tos-=1;
    }
    return s;
}

void display(Stack s) {
    int i;
    for (i=0;i<=s.tos;i++) {
        printf("%c ",s.st[i]);
    }
}

int main() {

    Stack s;
    s.tos = -1;
    int input;
    do {
        printf("\nEnter 1 to push, 2 to pop, 3 to display, and -1 to exit ");
        scanf("%d",&input);

        if (input == 1) {
            s = push(s);
        }

        else if (input == 2) {
            s = pop(s);
        }

        else if(input == 3) {
            display(s);
        }

        else {
            input = -1;
        }

    } while (input != -1);
    return 0;
}