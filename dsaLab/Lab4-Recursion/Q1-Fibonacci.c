#include <stdio.h>

int fib(int i,int a,int b,int n) {
    
    if (i == n)
        return 0;

    printf("%d ",(a+b));
    return fib((i+1),b,(a+b),n);
}

int main() {
    
    int n,a=0,b=1;
    printf("Enter n ");
    scanf("%d",&n);


    // 0 1 1 2 3 5 8 13 ...

    printf("0 1 ");

    fib(2,a,b,n);
    
    return 0;
}