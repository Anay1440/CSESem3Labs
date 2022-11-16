//doubly linked list without header node to insert into and delete from both the sides.

#include <stdio.h>
#include <stdlib.h>
#include "ListFunctions.h"

int main() {
    int inp,x;
    Node * list = (Node *) malloc (sizeof(Node));
    list = NULL;
    printf("1. Insert front, 2. Insert end, 3. Delete front, 4. Delete end, 5. Display, -1. Exit ");
    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);

        if (inp == 1) {
            printf("Enter element to insert ");
            scanf("%d",&x);
            insertFront(&list,x);
        }
        else if (inp == 2) {
            printf("Enter element to insert ");
            scanf("%d",&x);
            insertEnd(&list,x);
        }
        else if (inp == 3) 
            deleteNode(&list,list);
        else if (inp == 4) {
            Node * temp = (Node *) malloc(sizeof(Node));
            temp = list;
            while (temp -> right != NULL)
                temp = temp->right;
            deleteNode(&list,temp);
        }
        else if (inp == 5) 
            display(list);
        else
            inp = -1;
    } while (inp != -1);
}
