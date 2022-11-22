//program to perform the following operations on singly circular linked list with header node subtract, multiply and display the result.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val,coeff;
    struct node *next;
} node ;

typedef struct node Node;

void insertNode(Node * prev,int x, int z) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->val = x;
    new->coeff = z;
    new->next = prev->next;
    prev->next = new;
}

void inputCirc(Node **list,int n) {
    int i,temp1,temp2;
    Node * temp = (Node *) malloc(sizeof(Node));
    (*list) -> next = temp;
    for (i=0;i<n;i++) {
        printf("Enter value and coefficient ");
        scanf("%d %d",&temp1,&temp2);
        if (i == 0) {
            temp->val = temp1;
            temp->coeff = temp2;
            temp->next = *list;
        }
        else {
            insertNode(temp,temp1,temp2);
            temp = temp->next;
        }
    }
}

void displayCirc(Node **list) {
    printf("The expression is: ");
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = (*list)->next;
    while(temp != *list) {
        printf("(%dx^%d) + ",temp->val,temp->coeff);
        temp = temp->next;
    }
    printf("\n");
}

int getCoeff(Node *list, int exp) {
    //find coefficient of x power exp
    Node * head = list;
    list = list->next;
    while (list != head) {
        if (list->coeff == exp)
            return list->val;
        list = list->next;
    }
    return 0;
}

void sub(Node **list1, Node **list2, Node **list3) {
    //list 1 minus list 2
    Node * iter1 = (Node *) malloc(sizeof(Node));
    iter1 = (*list1)->next;
    Node * iter2 = (Node *) malloc(sizeof(Node));
    iter2 = (*list2)->next;
    Node * head3 = (Node *) malloc(sizeof(Node));
    *list3 = head3;
    head3->next = head3;

    while (iter1 != *list1 ) {    
        int x = getCoeff(*list2,iter1->coeff);
        if (x == 0) {
            Node * new = (Node *) malloc(sizeof(Node));
            new->next = head3->next;
            head3->next = new;
            new->val = iter1->val;
            new->coeff = iter1->coeff;
        }
        else {
            Node * new = (Node *) malloc(sizeof(Node));
            new->next = head3->next;
            head3->next = new;
            new->val = iter1->val - x;
            new->coeff = iter1->coeff;
        }
        iter1 = iter1->next;
        head3 = head3->next;
    }
    while (iter2 != *list2) {
        int x = getCoeff(*list3,iter2->coeff);
        if (x == 0) {
            Node * new = (Node *) malloc(sizeof(Node));
            new->next = head3->next;
            head3->next = new;
            new->val = - iter2->val;
            new->coeff = iter2->coeff;
        }
        iter2 = iter2->next;
        head3 = head3->next;
    }
}

void mult(Node **list1, Node **list2, Node **list4) {
    Node * iter1 = (Node *) malloc(sizeof(Node));
    iter1 = (*list1)->next;
    Node * iter2 = (Node *) malloc(sizeof(Node));
    iter2 = (*list2)->next;
    Node * head4 = (Node *) malloc(sizeof(Node));
    *list4 = head4;
    head4->next = head4;

    while (iter1 != *list1) {
        iter2 = (*list2) -> next;
        while (iter2 != *list2) {
            Node * new = (Node *) malloc(sizeof(Node));
            new->next = head4->next;
            head4->next = new;
            new->val = iter1->val *  iter2->val;
            new->coeff = iter1->coeff + iter2->coeff;

            iter2 = iter2->next;
        }
        iter1 = iter1->next;
    }
}

int main() {
    int n1,n2;
    Node * list1 = (Node *) malloc(sizeof(Node));
    Node * list2 = (Node *) malloc(sizeof(Node));
    Node * list3 = (Node *) malloc(sizeof(Node));
    Node * list4 = (Node *) malloc(sizeof(Node));


    printf("Enter length of first polynomial expression ");
    scanf("%d",&n1);
    inputCirc(&list1,n1);
    displayCirc(&list1);
    printf("Enter length of first polynomial expression ");
    scanf("%d",&n2);
    inputCirc(&list2,n2);
    displayCirc(&list2);
    printf("Expression after subtraction: ");
    sub(&list1,&list2,&list3);
    displayCirc(&list3);
    printf("Expression after multiplication: ");
    mult(&list1,&list2,&list4);
    displayCirc(&list4);
}