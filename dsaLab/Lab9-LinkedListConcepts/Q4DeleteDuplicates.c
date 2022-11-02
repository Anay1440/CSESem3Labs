#include <stdio.h>
#include <stdlib.h>
#include "ListFunctions.h"

void deleteDuplicates(Node **list) {
    Node * iter1 = (Node *) malloc(sizeof(Node));
    Node * iter2 = (Node *) malloc(sizeof(Node));
    iter1 = *list;
    iter2 = *list;
    while (iter1->next != NULL) {
        int x = iter1->val;
        iter2 = iter1->next;
        while (iter2 != NULL) {
            if (iter2->val != x) 
                break;
            else 
                iter2 = iter2 -> next;
        }
        if (iter2 == NULL) {
            iter1->next = NULL;
            break;
        }
        else if (iter2 != iter1->next) {
            iter1->next = iter2;
        }
        iter1 = iter1->next;
    }
}

int main() {
    int n,x;
    Node * list = (Node *) malloc(sizeof(Node));
    printf("Enter length of list ");
    scanf("%d",&n);
    printf("Enter input for list:\n");
    input(list,n);
    printf("After removing duplicates: ");
    deleteDuplicates(&list);
    display(list);
}