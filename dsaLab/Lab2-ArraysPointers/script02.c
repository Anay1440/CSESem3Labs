#include <stdio.h>
#include <stdlib.h>

int smallest(int *arr,int n) {
	int i,*i1,smal=*arr;
	for(i=0;i<n;i++) {
		i1=arr+i;
		if(*i1<smal) {
			smal=*i1;
		}
	}
	return smal;
}

int main() {
	int i,n,smal;
	printf("Enter n ");
	scanf("%d",&n);
	int *arr;
	arr = (int*) calloc(n, sizeof(int));
	for(i=0;i<n;i++) {
		printf("Enter element no %d ",i);
		scanf("%d",&arr[i]);
	}
	smal=smallest(arr,n);
	printf("The smallest element of the array is: %d ",smal);
}