#include <stdio.h>
#include <string.h>

void copy(char st[100],char stcpy[100],int i,int n) {
    if (i != (n)) {
        stcpy[i]=st[i];
        copy(st,stcpy,(i+1),n);
    }     
}

int main() {

    char st[100],stcpy[100];

    printf("Enter a string ");
    scanf("%[^\n]%*c",st);
    copy(st,stcpy,0,strlen(st));
    printf("Copied string is: %s ",stcpy);

    return 0;
}