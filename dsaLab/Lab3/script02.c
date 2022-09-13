#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int rno;
    double cgpa;
} Student;

void read(Student *stds,int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("Enter student firstname ");
        scanf("%s",(stds+i)->name);
        printf("Enter roll number ");
        scanf("%d",&((stds+i)->rno));
        printf("Enter CGPA ");
        scanf("%lf",&((stds+i)->cgpa));
    }
}

void display(Student *stds,int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("\nName of student: %s\nRoll Number : %d\nCGPA : %lf\n",(stds+i)->name,(stds+i)->rno,(stds+i)->cgpa);
    }
}

void sort(Student *st,int n) {
    Student temp;
    int i,j;
    for(i=0;i<n-1;i++) {
        for(j=i;j<n;j++) {
            if (st[i].rno > st[j].rno) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
}

int main() {
    int n,i;

    printf("Enter the number of students ");
    scanf("%d",&n);

    Student *st ;
    st = (Student *) malloc (n*sizeof(Student *));

    read(st,n);

    printf("%d",st->rno);

    printf("\nThe details of the first student are: ");
    printf("\nName of student: %s\nRoll Number : %d\nCGPA : %lf\n",st[0].name,st[0].rno,st[0].cgpa);

    sort(st,n);

    printf("\nDetails of students sorted in ascending order:\n");

    display(st,n);

    return 0;
}