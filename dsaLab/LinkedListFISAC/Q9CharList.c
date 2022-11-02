#include <stdio.h>
#include <stdlib.h>

struct node {
    char ch;
    struct node *next;
};

typedef struct node Node;

void insertNode(Node * prev,char c) {
    Node *new;
    new = (Node *) malloc(sizeof(Node));
    new->ch = c;
    new->next = prev->next;
    prev->next = new;
}

void display(Node *node) {
    while(node != NULL) {
        printf("%c ",node->ch);
        node = node->next;
    }
    printf("\n");
}

void input(Node *node,int n) {
    int i,temp;
    for (i=0;i<n;i++) {
        printf("Enter ch to add ");
        scanf("%d",&temp);
        if (i == 0) {
            node->ch = temp;
            node->next = NULL;
            continue;
        }
        insertNode(node,temp);
        node = node->next;
    }
}

void deleteNode(Node ** list, Node * tbd) {
    if (*list == tbd) {
        *list = (*list)->next;
        free(tbd);
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
    free(tbd);
}

int isVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return 1;
    return 0; 
}

void allVowels(Node **list) {
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *list;
    while (temp != NULL) {
        if (isVowel(temp->ch)) {
            deleteNode(list,temp);
            temp = *list;
            continue;
        }
        temp = temp->next;
    }
}

Node * create(char name[20]) {
    Node * list1 = (Node *) malloc(sizeof(Node));
    Node * listHead = (Node *) malloc(sizeof(Node));

    int i=0,ind=0;
    while (name[ind] != '\0') {
        if (i==0) {
            i++;
            list1->ch = name[ind++];
            list1->next = NULL;
            listHead=list1;
            continue;
        }
        insertNode(list1,name[ind++]);
        list1 = list1->next;
    }
    return listHead;
}


int main() {
    int n1,n2,n,i,temp;
    char name[20];
    Node * list1 = (Node *) malloc(sizeof(Node));
    
    printf("Enter your name ");
    scanf("%s",name);
    list1 = create(name);
    printf("The list is: ");
    display(list1);
    printf("The list after removing vowels is: ");
    allVowels(&list1);
    display(list1);
}
