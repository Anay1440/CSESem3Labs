#include <stdio.h>
#include <stdlib.h>
#include "ListFunctionsHeader.h"

void split(Node *list, Node *oddList, Node *evenList) {
    int i=0,i1=0,i2=0;
    while(list != NULL) {
        i++;
        if (i%2==0) {
            //even positions
            if (i1 == 0) {
                evenList->val = list->val;
                evenList->next = NULL;
                i1++;
                list = list->next;
                continue;
            }
            insertNode(evenList,list->val);
            evenList = evenList->next;
        }
        else {
            //odd positions
            if (i2 == 0) {
                oddList->val = list->val;
                oddList->next = NULL;
                i2++;
                list = list->next;
                continue;
            }
            insertNode(oddList,list->val);
            oddList = oddList->next;
        }
        list = list->next;
    }
}


int main() {
    int n1,n2,n,i,temp;
    printf("Enter length of list ");
    scanf("%d",&n1);
    Node * list1 = (Node *) malloc(sizeof(Node));
    Node * oddList = (Node *) malloc(sizeof(Node));
    Node * evenList = (Node *) malloc(sizeof(Node));
    
    printf("Enter input for first list\n");
    input(list1,n1);
    printf("The list is: ");
    display(list1);
    split(list1,oddList,evenList);
    printf("Odd positions list: ");
    display(oddList);
    printf("Even positions list: ");
    display(evenList);
}
