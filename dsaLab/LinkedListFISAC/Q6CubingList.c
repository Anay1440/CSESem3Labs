#include <stdio.h>
#include <stdlib.h>
#include "ListFunctionsHeader.h"

int cub(int x) {
    return x*x*x;
}

void cube(Node *list, Node *oddList, Node *evenList) {
    int i1=0,i2=0;
    while(list != NULL) {
        if ((list->val)%2==0) {
            //even number
            if (i1 == 0) {
                evenList->val = cub(list->val);
                evenList->next = NULL;
                i1++;
                list = list->next;
                continue;
            }
            insertNode(evenList,cub(list->val));
            evenList = evenList->next;
        }
        else {
            //odd number
            if (i2 == 0) {
                oddList->val = cub(list->val);
                oddList->next = NULL;
                i2++;
                list = list->next;
                continue;
            }
            insertNode(oddList,cub(list->val));
            oddList = oddList->next;
        }
        list = list->next;
    }
}


int main() {
    int n;
    printf("Enter length of list ");
    scanf("%d",&n);
    Node * list = (Node *) malloc(sizeof(Node));
    Node * evenList = (Node *) malloc(sizeof(Node));
    Node * oddList = (Node *) malloc(sizeof(Node));
    
    printf("Enter input for list\n");
    input(list,n);
    printf("The list is: ");
    display(list);
    cube(list,evenList,oddList);
    printf("List 1: ");
    display(oddList);
    printf("List 2: ");
    display(evenList);
}
