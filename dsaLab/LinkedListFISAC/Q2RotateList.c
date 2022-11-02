#include <stdio.h>
#include <stdlib.h>
#include "ListFunctionsHeader.h"

void insertLast(Node *prev,int x) {
    Node *new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->next = NULL;
    prev->next = new;
}

Node * insertFirst(Node *head,int x) {
    Node *new = (Node *) malloc(sizeof(Node));
    if (head == NULL) {
        new->val = x;
        new->next = NULL;
        return new;
    }
    new->val = x;
    new->next = head;
    return new;
}

void copy(Node * copy, Node * source) {
    while (source != NULL) {
        copy->val = source->val;
        copy->next = source->next;
        copy = copy->next;
        source = source->next;
    }
}

void rotateLeft(Node * upd, Node * source) {
    Node * head = (Node *) malloc(sizeof(Node));
    head->val = source->val;
    int i=-1;
    while (source->next != NULL) {
        i+=1;
        source = source->next;
        if (i == 0) {
            upd->val = source->val;
            upd->next = NULL;
            continue;
        }
        insertNode(upd,source->val);
        upd = upd->next;
    }
    insertLast(upd,head->val);
}

Node * rotateRight(Node * upd, Node * source) {
    Node * tail = (Node *) malloc(sizeof(Node));
    Node * updCopy = (Node *) malloc(sizeof(Node));
    copy(tail,source);
    while (tail->next != NULL) {
        tail = tail->next;
    }
    upd = insertFirst(upd,tail->val);
    updCopy = upd;
    while (source->next != NULL) {
        insertNode(upd,source->val);
        upd = upd->next;
        source = source->next;
    }
    upd = NULL;
    return updCopy;
}

int main() {
    int n,i,k,temp;
    printf("Enter length of list ");
    scanf("%d",&n);
    Node * list = (Node *) malloc(sizeof(Node));
    Node * listCopy = (Node *) malloc(sizeof(Node));
    
    printf("Enter input for list\n");
    input(list,n);
    printf("The list is: ");
    display(list);
    printf("Enter k ");
    scanf("%d",&k);
    listCopy = (Node *) malloc(sizeof(Node));
    printf("Copied list: ");
    copy(listCopy,list);
    display(listCopy);
    Node * leftRotateList = (Node *) malloc(sizeof(Node));
    copy(leftRotateList,list);
    Node * lrlHead = (Node *) malloc(sizeof(Node));
    printf("Left rotate: ");
    for(i=0;i<k;i++) {
        Node * prev = (Node *) malloc(sizeof(Node));
        if (i == 0)
            prev = list;
        else 
            prev = lrlHead;
        rotateLeft(lrlHead,prev);
    }
    display(lrlHead);
    printf("Right rotate: ");
    Node * rrlHead = (Node *) malloc(sizeof(Node));
    rrlHead = NULL;
    Node * rightRotateList = (Node *) malloc(sizeof(Node));
    rightRotateList = NULL;
    for(i=0;i<k;i++) {
        Node * prev = (Node *) malloc(sizeof(Node));
        if (i == 0)
            prev = listCopy;
        else 
            prev = rrlHead;
        rrlHead = rotateRight(rightRotateList,prev);
    }
    display(rrlHead);
}
