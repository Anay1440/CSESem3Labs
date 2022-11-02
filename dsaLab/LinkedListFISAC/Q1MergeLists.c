#include <stdio.h>
#include <stdlib.h>
#include "ListFunctionsHeader.h"

Node * merge(Node *list1, Node *list2) {
    Node *mergedList = (Node *) malloc(sizeof(Node));
    Node *mergedListHead = (Node *) malloc(sizeof(Node));
    int i=0;
    while(list1 != NULL || list2 != NULL) {
        if (list1 == NULL && list2 != NULL) {
            insertNode(mergedList,list2->val);
            mergedList = mergedList->next;
            list2 = list2->next;
            continue;
        }
        else if (list2 == NULL && list1 != NULL) {
            insertNode(mergedList,list1->val);
            mergedList = mergedList->next;
            list1 = list1->next;
            continue;
        }
        if (i==0) {
            if (list1->val < list2->val) {
                mergedList->val = list1->val;
                list1 = list1->next;
            }
            else if (list1->val == list2->val) {
                insertNode(mergedList,list1->val);
                mergedList = mergedList->next;
                list1 = list1->next;
                list2 = list2->next;
            }
            else {
                mergedList->val = list2->val;
                list2 = list2->next;
            }
            mergedList->next = NULL;
            mergedListHead=mergedList;
        }
        else {
            if (list1->val < list2->val) {                
                insertNode(mergedList,list1->val);
                mergedList = mergedList->next;
                list1 = list1->next;
            }
            else if (list1->val == list2->val) {
                insertNode(mergedList,list1->val);
                mergedList = mergedList->next;
                list1 = list1->next;
                list2 = list2->next;
            }
            else {
                insertNode(mergedList,list2->val);
                mergedList = mergedList->next;
                list2 = list2->next;
            }
        }
        i+=1;
    }
    return mergedListHead;
}

int main() {
    int n1,n2,n,i,temp;
    printf("Enter length of first list ");
    scanf("%d",&n1);
    printf("Enter length of second list ");
    scanf("%d",&n2);
    Node * list1 = (Node *) malloc(sizeof(Node));
    Node * list2 = (Node *) malloc(sizeof(Node));
    Node * mergedList = (Node *) malloc(sizeof(Node));
    
    printf("Enter input for first list\n");
    input(list1,n1);
    printf("Enter input for second list\n");
    input(list2,n2);
    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);
    printf("List after merging: ");
    mergedList = merge(list1,list2);
    display(mergedList);
}
