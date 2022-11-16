//Reverse a doubly linked list containing words in the data field

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char word[30];
    struct node *right;
    struct node *left;
} node ;

typedef struct node Node;

void insertNode(Node * prev,char w[30]) {
    Node * new = (Node *) malloc(sizeof(Node));
    strcpy(new->word,w);
    new->right = prev->right;
    new->left = prev;
    prev->right = new;
}

void input(Node *node,int n) {
    int i;
    char w[30];
    for (i=0;i<n;i++) {
        printf("Enter value to add ");
        scanf("%s",w);
        if (i == 0) {
            strcpy(node->word,w);
            node->right = NULL;
            node->left = NULL;
        }
        else {
            insertNode(node,w);
            node = node->right;
        }
    }
}

void display(Node *node) {
    printf("The list is: ");
    while(node != NULL) {
        printf("%s ",node->word);
        node = node->right;
    }
    printf("\n");
}

void rev(Node **list) {
    Node * curr = (Node *) malloc(sizeof(Node));
    Node * next = (Node *) malloc(sizeof(Node));

    curr = *list;

    while (curr != NULL) {
        next = curr->left;
        curr->left = curr->right;
        curr->right = next;
        curr = curr->left;
    }
    *list = next->left;
}

int main() {
    int n;
    Node * list = (Node *) malloc(sizeof(Node));

    printf("Enter length of list ");
    scanf("%d",&n);
    printf("Enter the list elements\n");
    input(list,n);
    display(list);
    printf("The list after reversing is:\n");
    rev(&list);
    display(list);
}