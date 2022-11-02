#include <stdio.h>
#include <stdlib.h>
#include "ListFunctions.h"

void inputCirc(Node *node,int n) {
    int i,temp;
    Node * head = (Node *) malloc(sizeof(Node));
    head = node;
    for (i=0;i<n;i++) {
        printf("Enter value to add ");
        scanf("%d",&temp);
        if (i == 0) {
            node->val = temp;
            node->next = node;
        }
        else {
            insertNode(node,temp);
            node = node->next;
        }
    }
}

void displayCirc(Node *node) {
    Node * head = (Node *) malloc(sizeof(Node));
    head = node;
    while(node->next != head) {
        printf("%d ",node->val);
        node = node->next;
    }
    printf("%d ",node->val);
    printf("\n");
}

int isTraversed(Node * node, Node * head) {
    if (node == head)
        return 1;
    return 0;
}

void merge(Node * list1, Node * list2, Node * mergedList) {
    Node * list1Head = (Node *) malloc(sizeof(Node));
    Node * list2Head = (Node *) malloc(sizeof(Node));
    Node * mergedListHead = (Node *) malloc(sizeof(Node));
    list1Head = list1;
    list2Head = list2;
    int list1Trav=0,list2Trav=0;
    mergedListHead = mergedList;
    int i=0;
    while(!(list1Trav && list2Trav)) {
        if (list1Trav && !list2Trav) {
            insertNode(mergedList,list2->val);
            mergedList = mergedList->next;
            list2 = list2->next;
            if (isTraversed(list2,list2Head))
                list2Trav=1;
        }
        else if (list2Trav && !list1Trav) {
            insertNode(mergedList,list1->val);
            mergedList = mergedList->next;
            list1 = list1->next;
            if (isTraversed(list1,list1Head))
                list1Trav=1;
        }
        else {
            if (list1->val < list2->val) {
                if (i==0) {
                    mergedList->val = list1->val;
                    mergedList->next = mergedList;
                }
                else {
                    insertNode(mergedList,list1->val);
                    mergedList = mergedList->next;
                }
                list1 = list1->next;
                if (isTraversed(list1,list1Head))
                    list1Trav=1;
            }
            else if (list1->val == list2 ->val) {
                if (i == 0) {
                    mergedList->val = list1->val;
                    mergedList->next = mergedList;
                }
                else {
                    insertNode(mergedList,list1->val);
                    mergedList = mergedList->next;
                }
                list1 = list1->next;
                list2 = list2->next;
                if (isTraversed(list1,list1Head))
                    list1Trav=1;
                if (isTraversed(list2,list2Head))
                    list2Trav=1;
            }
            else {
                if (i == 0) {
                    mergedList->val = list2->val;
                    mergedList->next = mergedList;
                }
                else {
                    insertNode(mergedList,list2->val);
                    mergedList = mergedList->next;
                }
                list2 = list2->next;
                if (isTraversed(list2,list2Head))
                    list2Trav=1;
            }
        }
        i+=1;
    }
}

int main() {
    int n1,n2;
    printf("Enter number of elements in list 1: ");
    scanf("%d",&n1);
    printf("Enter number of elements in list 2: ");
    scanf("%d",&n2);
    Node * list1 = (Node *) malloc(sizeof(Node));
    Node * list2 = (Node *) malloc(sizeof(Node));
    Node * mergedList = (Node *) malloc(sizeof(Node));
    printf("Enter elements for list1:\n");
    inputCirc(list1,n1);
    printf("The list is: ");
    displayCirc(list1);
    printf("Enter elements for list2:\n");
    inputCirc(list2,n2);
    printf("The list is: ");
    displayCirc(list2);
    printf("The merged list is: ");
    merge(list1,list2,mergedList);
    displayCirc(mergedList);
}