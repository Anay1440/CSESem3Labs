#include <stdio.h>

void towStep(int n,int a,int b,int c) {

    if (n == 0)
        return ;

    towStep((n-1),a,c,b);
    printf("\nDisk %d is moved from Rod %d to Rod %d",n,a,b);
    towStep((n-1),c,b,a);
}

int main() {

    int n;
    printf("Enter n ");
    scanf("%d",&n);
    towStep(n,1,2,3);

    return 0;
}