#include "maths.h"
#include <stdio.h>

int push(int *arr, int n, int tos,int x) {
	if ( (tos+1) > (n-1)) {
		return -1;	
	}
	else {
		tos += 1;
		arr[tos] = x;
		return tos;
	}
}

int pop(int *arr, int tos) {
	if (tos == -1) {
		return -5;	
	}
	else {
		arr[tos] = -2;
		tos -= 1;
		return tos;	
	}
}

void display(int *arr, int tos) {
	int i;
	for (i = 0; i <= tos; i++) {
		printf("%d ",arr[i]);	
	}
}
