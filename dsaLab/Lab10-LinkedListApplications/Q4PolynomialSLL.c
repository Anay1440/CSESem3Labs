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
    head3->next = NULL;

    while (iter1 != NULL) {

        int x = getCoeff(*list2,iter1->coeff);
        if (x == 0) {
            Node * new = (Node *) malloc(sizeof(Node));
            head3->next = new;
            new->val = iter1->val;
            
        }

        iter1 = iter1->next;
    }

}

int main() {
    int n1,n2;
    Node * list1 = (Node *) malloc(sizeof(Node));
    Node * list2 = (Node *) malloc(sizeof(Node));
    Node * list3 = (Node *) malloc(sizeof(Node));

    printf("Enter length of first polynomial expression ");
    scanf("%d",&n1);
    inputCirc(&list1,n1);
    displayCirc(&list1);
}