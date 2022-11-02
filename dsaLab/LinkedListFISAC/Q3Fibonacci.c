#include <stdio.h>
#include <stdlib.h>
#include "ListFunctionsHeader.h"

void fib(Node * node) {
    Node * new = (Node *) malloc(sizeof(Node));
    int penUlt; //penultimate
    while (1) {
        if (node->next->next == NULL) {
            penUlt = node->val;
            node = node->next;
            break;
        }
        node = node->next;
    }
    insertNode(node,(penUlt + node->val));
}

int main() {
    int n,i,k,temp;
    Node * node = (Node *) malloc(sizeof(Node));    
    printf("Enter n ");
    scanf("%d",&n);
    node->val = 0;
    node->next = NULL;
    insertNode(node,1);
    for(i=0;i<n-2;i++)
        fib(node);
    
    printf("Fibonacci series: ");
    display(node);
}
