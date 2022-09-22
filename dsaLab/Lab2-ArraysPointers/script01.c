#include <stdio.h>
#include <stdlib.h>

void rev(int *arr,int n) {
	int i,temp,*i1,*i2;
	for(i=0;i<n/2;i++) {
		i1=arr+i;
		i2=arr+n-i-1;
		temp=*i2;
		*i2=*i1;
		*i1=temp;

	}
}

int main() {
	int i,n;
	printf("Enter n ");
	scanf("%d",&n);
	int *arr;
	arr = (int*) calloc(n, sizeof(int));
	for(i=0;i<n;i++) {
		printf("Enter element no %d ",i);
		scanf("%d",&arr[i]);
	}
	rev(arr,n);
	printf("The reversed array is:\n");
	for(i=0;i<n;i++) {
		printf("%d ",arr[i]);
	}
}