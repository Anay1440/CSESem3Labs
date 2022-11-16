//Add two long positive integers represented using circular doubly linked list with header node.

#include <stdio.h>
#include <stdlib.h>
#include "ListFunctions.h"

void makeCirc(Node ** list) {
    Node * temp = (Node *) malloc (sizeof(Node));
    temp = (*list)->right;
    while (temp -> right != NULL)   
        temp = temp->right;
    temp->right = *list;
    (*list)->left = temp;
}

void displayCirc(Node **node) {
    Node * temp = (Node *) malloc (sizeof(Node));
    temp = (*node)->right;
    printf("The list is: ");
    while(temp != *node) {
        printf("%d ",temp->val);
        temp = temp->right;
    }
    printf("\n");
}

void add(Node ** list1, Node ** list2, Node ** list3) {
    printf("here");
    Node * list1Rev = (Node *) malloc (sizeof(Node));
    Node * list2Rev = (Node *) malloc (sizeof(Node));
    Node * temp = (Node *) malloc (sizeof(Node));
    temp = (*list1)->right;
    printf("here");
    while (temp->right != *list1)
        temp = temp->right;
    list1Rev = temp;
    printf("here");
    temp = (*list2)->right;
    while (temp->right != *list2)
        temp = temp->right;
    list2Rev = temp;

    int carry = 0;

    while ((list1Rev != *list1) || (list2Rev != *list2)) {
        int val1 = list1Rev->val;
        if (list1Rev == NULL)
            val1 = 0;
        int val2 = list2Rev->val;
        if (list2Rev == NULL)
            val2 = 0;

        int x = val1 + val2 + carry;
        if (x > 10) {
            carry = 1;
            x = x % 10;
        }
        else
            carry = 0;
        insertFront(list3,x);
        list1Rev = list1Rev -> left;
        list2Rev = list2Rev -> left;
    }
}

int main() {
    int n1,n2;
    printf("Enter length of first number ");
    scanf("%d",&n1);
    printf("Enter length of second number ");
    scanf("%d",&n2);

    Node * list1 = (Node *) malloc (sizeof(Node));
    Node * list2 = (Node *) malloc (sizeof(Node));
    Node * list3 = (Node *) malloc (sizeof(Node));
    list3 = NULL;
    Node * head1 = (Node *) malloc (sizeof(Node));
    Node * head2 = (Node *) malloc (sizeof(Node));


    printf("Enter first number\n");
    input(list1,n1);
    head1->right = list1;
    list1 = head1;
    makeCirc(&list1);
    displayCirc(&list1);
    printf("Enter second number\n");
    input(list2,n2);
    head2->right = list2;
    list2 = head2;
    makeCirc(&list2);
    displayCirc(&list2);

    printf("Adding both nums");
    printf("hmm");
    add(&list1,&list2,&list3);
    display(list3);

}