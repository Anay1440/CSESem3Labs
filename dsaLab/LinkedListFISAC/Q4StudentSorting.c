#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int rno,marks;
} Student;

struct node {
    Student s;
    struct node *next;
};

typedef struct node Node;

void insertNode(Node * prev,Student st) {
    Node * new = (Node *) malloc(sizeof(Node));
    new->s = st;
    new->next = prev->next;
    prev->next = new;
}

void displayStud(Student s) {
    printf("{%s,%d,%d} ",s.name,s.rno,s.marks);
}

void display(Node *node) {
    while(node != NULL) {
        displayStud(node->s);
        node = node->next;
    }
    printf("\n");
}

void input(Node *node,int n) {
    int i;
    Student st;
    for (i=0;i<n;i++) {
        printf("Enter name ");
        scanf("%s",st.name);
        fflush(stdin);
        printf("Enter roll number ");
        scanf("%d",&st.rno);
        fflush(stdin);
        printf("Enter marks ");
        scanf("%d",&st.marks);
        fflush(stdin);
        if (i == 0) {
            node->s = st;
            node->next = NULL;
            continue;
        }
        insertNode(node,st);
        node = node->next;
    }
}

Node * findMax(Node * node, int * usedHighest) {
    Node * max = (Node *) malloc(sizeof(Node));
    Node * listCopy = (Node *) malloc(sizeof(Node));
    listCopy = node;
    max->s.marks = 0;
    while (node != NULL) {
        if ( (node->s.marks >= max->s.marks) && (node->s.marks < * usedHighest)) {
            max = node;
        }
        node = node->next;
    }
    *usedHighest = max->s.marks;
    return max;
}

void sort(Node * node,Node * sorted) {
    Node * nodeCopy = (Node *) malloc(sizeof(Node));
    Node * max = (Node *) malloc(sizeof(Node));
    int usedHighest = 100;
    nodeCopy = node;
    int n=0,i;
    while (nodeCopy != NULL) {
        n+=1;
        nodeCopy=nodeCopy->next;
    }
    for(i=0;i<n;i++) {
        max = findMax(node,&usedHighest);
        if (i==0) {
            sorted->s = max->s;
            sorted->next = NULL;
            continue;
        }
        insertNode(sorted,max->s);
        sorted = sorted->next;
    }
}

int main() {
    int n;
    printf("Enter length of list ");
    scanf("%d",&n);
    Node * node = (Node *) malloc(sizeof(Node));    
    printf("Enter input for list\n");
    input(node,n);
    printf("The list is: ");
    display(node);
    printf("List after sorting is: ");
    Node * sorted = (Node *) malloc(sizeof(Node));    
    sort(node,sorted);
    display(sorted);
    Node * secondHighest = (Node *) malloc(sizeof(Node));    
    secondHighest = sorted->next;
    printf("Second highest: ");
    displayStud(secondHighest->s);
}   
