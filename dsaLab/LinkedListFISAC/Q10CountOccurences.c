#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char name[20];
    int occ;
    struct node *next;
};

typedef struct node Node;

void insertNode(Node * prev,char * nam) {
    Node * new = (Node *) malloc(sizeof(Node));
    strcpy(new->name,nam);
    new->occ=0;
    new->next = prev->next;
    prev->next = new;
}

void display(Node *node) {
    while(node != NULL) {
        printf("%s (%d) ",node->name,node->occ);
        node = node->next;
    }
    printf("\n");
}

Node * Create() {
    int i,n;
    Node * list1 = (Node *) malloc(sizeof(Node));
    Node * node2 = (Node *) malloc(sizeof(Node));
    printf("Enter length of list ");
    scanf("%d",&n);
    char nam[20];
    for (i=0;i<n;i++) {
        printf("Enter name ");
        scanf("%s",nam);
        fflush(stdin);
        if (i == 0) {
            strcpy(list1->name,nam);
            list1->next = NULL;
            node2 = list1;
            continue;
        }
        insertNode(list1,nam);
        list1 = list1->next;
    }
    return node2;
}

void deleteNode(Node ** list, Node * tbd) {
    if (*list == tbd) {
        *list = (*list)->next;
        return;
    }
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *list;
    while (1) {
        if (temp->next == tbd) {
            temp->next = tbd->next;
            break;
        }
        temp = temp->next;
    }
}

void Search(Node **list) {
    Node * temp = (Node *) malloc(sizeof(Node));
    Node * iter = (Node *) malloc(sizeof(Node));
    Node * uniq = (Node *) malloc(sizeof(Node));
    temp = *list;

    while (temp != NULL) {

        uniq = temp;
        iter = temp->next;
        uniq->occ = 1;

        while (iter != NULL) {

            if (strcmp(iter->name,uniq->name) == 0) {
                uniq->occ += 1;
                deleteNode(list,iter);
            }

            iter = iter->next;
        }

        temp = temp->next;
    }

}

int main() {
    int n,i,k,temp;
    Node * list1 = (Node *) malloc(sizeof(Node));
    
    printf("Enter Create for list\n");
    list1 = Create();
    printf("List : ");
    Search(&list1);
    display(list1);
}