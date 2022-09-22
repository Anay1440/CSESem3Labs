#include <stdio.h>
#include <stdlib.h>
#include "../HeaderFiles/maths.h"

int main() {
/*
	int a,b,sum,diff,prod,quot,sq;
	printf("Enter a ");
	scanf("%d",&a);
	printf("Enter b ");
	scanf("%d",&b);
	sum=add(a,b);
	printf(" %d\n",sum);
	diff=sub(a,b);
	printf("%d\n",diff);
	prod=mult(a,b);
	printf("The multiplication results in: %d\n",prod);
	quot=div(a,b);
	printf("The quotient is: %d\n",quot);
	sq=square(a);
	printf("The square of a is: %d\n",sq);
	return 0; 
*/

	int i,n,*arr,input,tos=-1,x;
	printf("Enter max stack size ");
	scanf("%d",&n);
	
	arr = (int *) calloc(n,sizeof(int));
	
	do {
	
		printf("\nEnter 1 to push, 2 to pop, 3 to display, anything else to quit ");
		scanf("%d",&input);
		
		if (input == 1) {
			printf("Enter the number you want to push ");		
			scanf("%d",&x);
			tos=push(arr,n,tos,x);
			if (tos == -1) 
				printf("Stack limit exceeded. No changes were made");
		}

		else if(input == 2) {
			tos=pop(arr,tos);
			if (tos == -5) 
				printf("There is no element to pop. No changes were made");
		}

		else if (input == 3) {
			printf("\n");
			display(arr,tos);
		}

		else {
			input = -1;
			printf("Exiting");
		}

	} while(input != -1);

	return 0;

}
