#include <stdio.h>
double add(double arr[100],int n) {
	double sum=0.00;
	int i;
	for(i=0;i<n;i++) {
		sum+=arr[i];
	}
	return sum;
}
int main() {
	int n,i;
	printf("Enter n ");
	scanf("%d",&n);
	double arr[100],sum;
	for(i=0;i<n;i++) {
		printf("Enter element no. %d ",i);
		scanf("%lf",&arr[i]);
	}

	sum=add(arr,n);
	printf("The sum is: %lf",sum);

}