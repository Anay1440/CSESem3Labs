#include <stdio.h>
#include <stdlib.h>

void mult(int **mat1,int **mat2,int **mat3,int r1,int r2,int c1,int c2) {
	int i,j,k,*i1,*j1,*k1,sum;

	for(i=0;i<r1;i++) {
		for(j=0;j<c2;j++) {
			for(k=0;k<r2;k++) {
				//mat3[i][j] += mat1[i][k]*mat2[k][j];
                *(*(mat3+i)+j) += (*(*(mat1+i)+k) * *(*(mat2+k)+j));
			}

		}
	}
}

int main() {

	int i,j,r1,r2,c1,c2;
	printf("Enter number of rows for mat1 ");
	scanf("%d",&r1);
	printf("Enter number of columns for mat1 ");
	scanf("%d",&c1);
	printf("Enter number of rows for mat2 ");
	scanf("%d",&r2);
	printf("Enter number of columns for mat2 ");
	scanf("%d",&c2);

    int** mat1 = (int**) malloc((r1 * sizeof(int*)));
    for(i=0;i<r1;i++) {
		mat1[i] = (int*) calloc(c1, sizeof(int));
	}

    int** mat2 = (int**) malloc((r2 * sizeof(int*)));
    for(i=0;i<r1;i++) {
		mat2[i] = (int*) calloc(c2, sizeof(int));
	}

    int** mat3 = (int**) malloc((r1 * sizeof(int*)));
    for(i=0;i<r1;i++) {
		mat3[i] = (int*) calloc(c2, sizeof(int));
	}

	if(c1 != r2) {
		printf("These matrices cannot be multiplied");
	}

	else {

		for(i=0;i<r1;i++) {
			for(j=0;j<c1;j++) {
				printf("Enter element at index (%d,%d) ",i,j);
				scanf("%d",&mat1[i][j]);
			}
		}
		for(i=0;i<r2;i++) {
			for(j=0;j<c2;j++) {
				printf("Enter element at index (%d,%d) ",i,j);
				scanf("%d",&mat2[i][j]);
			}
		}

		for(i=0;i<r1;i++) {
			for(j=0;j<c2;j++) {
				mat3[i][j]=0;
			}
		}

		int *i1;
		i1=*mat1+2;
		printf("%d",*i1);

		mult(mat1,mat2,mat3,r1,r2,c1,c2);

		printf("The multiplication result is\n");
		for(i=0;i<r1;i++) {
			for(j=0;j<c2;j++) {
				printf("%d  ",mat3[i][j]);
			}
			printf("\n");
		}
	}
	
}
