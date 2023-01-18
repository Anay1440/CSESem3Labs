#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeFuncs.h"

double eval(char op,double x,double y) {
    if (op == '+')  return x+y;
    if (op == '-')  return x-y;
    if (op == '*')  return x*y;
    if (op == '/')  return x/y;
}

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

double evaluate(Node * node) {
    if (node == NULL)
        return 0;
    if (node->right == NULL && node->left == NULL)
        return (double) (node->val -'0');

    double x = evaluate(node->left);
    double y = evaluate(node->right);

    return eval(node->val,x,y);
}

int main() {
    Stack nodeStack;
    nodeStack.tos = -1;
    char postfix[100];
    printf("Enter postfix expression : ");
    scanf("%s",postfix);
    int i;
    for (i=0;i<strlen(postfix);i++) {
        if (!isOperator(postfix[i]))
            push(&nodeStack,createNode(postfix[i]));
        else {
            Node * root = createNode(postfix[i]);
            root->right = pop(&nodeStack);
            root->left = pop(&nodeStack);
            push(&nodeStack,root);
        }
    }

    Node * root = pop(&nodeStack);
    printf("Ans :  %lf",evaluate(root));
}