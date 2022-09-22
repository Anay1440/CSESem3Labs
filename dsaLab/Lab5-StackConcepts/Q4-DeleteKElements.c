#include <stdio.h> 
#include <stdlib.h>

typedef struct {
    int *st;
    int tos;
} Stack;

Stack push(Stack s,int x) {
    s.tos +=1;
    s.st[s.tos] = x;
    return s;
}

Stack del(Stack s,int ind) {
    int i;
    for (i=ind;i<s.tos;i++) {
        s.st[i] = s.st[i+1];
    }
    s.tos-=1;
    return s;
}

int main() {

    Stack s;

    int n,i,j,k,count=0;
    
    printf("Enter number of elements ");
    scanf("%d",&n);

    s.st = (int *) malloc (n * sizeof(int));

    for(i=0;i<n;i++) {
        printf("Enter element no. %d ",(i+1));
        scanf("%d",&s.st[i]);
    }
    s.tos = n-1;

    printf("Enter the number of elements that must be deleted ");
    scanf("%d",&k);


    //one approach
    //compares each element with its successor, and returns to the start of the array everytime an element is deleted
    // while (k > 0) {
    //     for (i=0;i<=s.tos-1;i++) {
    //         if (s.st[i] < s.st[i+1]) {
    //             s = del(s,i);
    //             k-=1;
    //             break;
    //         }
    //     }
    // }


    //another approach 
    //compares the element to the k ones in front of it
    for(i=0;i<=s.tos-k;i++) {
        if (count == k) 
            break;
        for(j=i+1;j<=(i+1)+k;j++) {
            if (s.st[i] < s.st[j]) {
                s = del(s,0);
                count+=1;
            }
        }
    }


    printf("The final array is:\n");
    for(i = 0;i <= s.tos; i++) {
        printf("%d ",s.st[i]);
    }

    return 0;
}