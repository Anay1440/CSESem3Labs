#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char str[20];
    struct node *next;
};

typedef struct node Node;

void insertNode(Node * prev,char st[20]) {
    Node *new = (Node *) malloc(sizeof(Node));
    strcpy(new->str,st);
    new->next = prev->next;
    prev->next = new;
}

void display(Node *node) {
    while(node != NULL) {
        printf("%s ",node->str);
        node = node->next;
    }
    printf("\n");
}

void input(Node *node,int n) {
    int i;
    char temp[20];
    for (i=0;i<n;i++) {
        printf("Enter string to add ");
        scanf("%s",temp);
        if (i == 0) {
            strcpy(node->str,temp);
            node->next = NULL;
            continue;
        }
        insertNode(node,temp);
        node = node->next;
    }
}

int palinCheck(char str[20]) {
    int i,n = strlen(str);
    for(i=0;i<n/2;i++) {
        if (str[i] != str[n-i-1]) 
            return 0;
    }
    return 1;
}

void split(Node * list, Node * psList, Node * npsList) {
    int i1=0,i2=0;
    while (list != NULL) {
        
        if (palinCheck(list->str)) {
            if (i1 == 0) {
                strcpy(psList->str,list->str);
                psList->next = NULL;
                i1++;
                list = list->next; 
                continue;
            }
            insertNode(psList,list->str);
            psList = psList->next;
        }
        else {
            if (i2 == 0) {
                strcpy(npsList->str,list->str);
                npsList->next = NULL;
                i2++;
                list = list->next; 
                continue;
            }
            insertNode(npsList,list->str);
            npsList = npsList->next;
        }
        list = list->next;  
    }
}

int main() {
    int n;
    printf("Enter length of list ");
    scanf("%d",&n);
    Node * list = (Node *) malloc(sizeof(Node));
    Node * psList = (Node *) malloc(sizeof(Node));
    Node * npsList = (Node *) malloc(sizeof(Node));
    
    printf("Enter input for list\n");
    input(list,n);
    printf("The list is: ");
    display(list);
    split(list,psList,npsList);
    printf("psList: ");
    display(psList);
    printf("NpsList: ");
    display(npsList);
}
