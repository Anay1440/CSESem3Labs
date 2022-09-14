#include <stdio.h>
#include <string.h>

int rev(char st[100],int i,int n) {
    if (i>(n/2))
        return 0;
    if (st[i] != st[n-i])
        return 1;
    return 0 + rev(st,(i+1),n);
}

int main() {

    char st[100];
    int flag;
    printf("Enter a word ");
    scanf("%s",st);

    flag = rev(st,0,(strlen(st)-1));

    if (flag == 1)
        printf("The word is not palindrome");
    else
        printf("The word is palindrome");

    return 0;
}