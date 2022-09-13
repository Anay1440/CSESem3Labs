#include <stdio.h> 
#include <stdlib.h>

typedef struct {
    int a;
} num ; 

int main() {

    num *nums;

    nums = (num *) malloc (3*sizeof(num *));
    
    printf("Enter num 1 ");
    scanf("%d",&(nums-> a));
    printf("Enter num 2 ");
    scanf("%d",&((nums+1)-> a));

    printf("\nNum 1 is %d, Num 2 is %d",(nums->a),((nums+1)->a));

    return 0;
}