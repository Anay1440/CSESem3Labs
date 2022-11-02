#include <stdio.h>
#include <stdlib.h>
#include "ListFunctionsHeader.h"

void deleteNode(Node ** list, Node * rd) {
    if (*list == rd) {
        *list = (*list)->next;
        free(rd);
        return;
    }
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *list;
    while (1) {
        if (temp->next == rd) {
            temp->next = rd->next;
            break;
        }
        temp = temp->next;
    }
    free(rd);
}

void delOccurences(Node **list, int key) {
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *list;

    while(temp != NULL) {
        if (temp->val == key*key) {
            deleteNode(list,temp);
            temp = *list;
            continue;
        }
        temp = temp->next;
    }
}

int main() {
    int n,k;
    printf("Enter length of list ");
    scanf("%d",&n);
    Node * list = (Node *) malloc(sizeof(Node));
    
    printf("Enter input for list\n");
    input(list,n);
    printf("The list before deletion is: ");
    display(list);
    printf("Enter k ");
    scanf("%d",&k);
    printf("List after deletion : ");
    delOccurences(&list,k);
    display(list);
}
