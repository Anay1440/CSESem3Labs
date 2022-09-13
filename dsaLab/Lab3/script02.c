#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int rno;
    double cgpa;
} Student;

Student read() {
    Student std;
    printf("Enter student firstname ");
    scanf("%s",std.name);
    printf("Enter roll number ");
    scanf("%d",&(std.rno));
    printf("Enter CGPA ");
    scanf("%lf",&(std.cgpa));
    return std;
}

void display(Student std) {
    printf("\nName of student: %s\nRoll Number : %d\nCGPA : %lf\n",std.name,std.rno,std.cgpa);
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

    Student *st = (Student *) malloc (n*sizeof(Student *));
    st[0] = read();

    printf("\nThe details of the first student are: ");
    display(st[0]);

    for (i=1;i<n;i++) {
        st[i] = read();
    }

    sort(st,n);

    printf("\nDetails of students sorted in ascending order:\n");

    for(i=0;i<n;i++) {
        printf("\nStudent number %d ",(i+1));
        display(st[i]);
    }

    return 0;
}