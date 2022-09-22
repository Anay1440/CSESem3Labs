#include <stdio.h>

int Lsearch(int arr[100],int n, int x) {
	int ind=-1,i;
	for(i=0;i<n;i++) {
		if(arr[i]==x) {
			ind=i;
			break;
		}
	}
	return ind;
}

int main() {
	int n,i,arr[100],x,ind;
	printf("Enter n ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		printf("Enter element no. %d ",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter number to search for ");
	scanf("%d",&x);
	ind=Lsearch(arr,n,x);
	if(ind==-1)
		printf("The element is not in the array ");
	else
		printf("The element is at index: %d ",ind);
	return 0;
}