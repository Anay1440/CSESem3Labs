#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int day;
    char *month;
    int year;
} DOB;

typedef struct {
    int reg_no;
    char *name;
    char address[100];
} STU_INFO;

typedef struct {
    char * college_name;
    char university_name[50];
} COLLEGE;

typedef struct {
    DOB *d;
    STU_INFO info;
    COLLEGE clg;
} STUDENT;

void read(STUDENT *stds,int n) {
    int i;
    char temp[100];
    for (i=0;i<n;i++) {
        printf("\nEnter details for student number %d ",(i+1));
        printf("Enter the day of DOB ");
        scanf("%d",&((stds+i)->d->day));
        printf("Enter the month of DOB ");
        scanf("%s[^\n]",temp);
        ((stds+i)->d->month) = (char *) malloc (strlen(temp) * sizeof(char));
        strcpy(((stds+i)->d->month),temp);
        fflush(stdin);
        printf("Enter the year of DOB ");
        scanf("%d",&((stds+i)->d->year));
        fflush(stdin);
        printf("Enter the registration number ");
        scanf("%d",&((stds+i)->info.reg_no));
        printf("Enter your name ");
        scanf("%s",temp);
        (stds+i)->info.name = (char *) malloc (strlen(temp) * sizeof(char));
        strcpy((stds+i)->info.name,temp);
        printf("Enter address ");
        gets((stds+i)->info.address);
        printf("Enter college name ");
        gets(temp);
        (stds+i)->clg.college_name = (char *) malloc (strlen(temp) * sizeof(char));
        printf("Enter university name ");
        gets((stds+i)->clg.university_name);
    }
}

void display(STUDENT *stds,int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("\nDetails for student number %d ",(i+1));
        printf("The name is : %s\nThe registration number is: %d\nCollege Name: %s\nUniversity Name: %s\nThe DOB is: %d/%d/%d\nAddress: %s",(stds+i)->info.name,(stds+i)->info.reg_no,(stds+i)->clg.college_name,(stds+i)->clg.university_name,(stds+i)->d->day,(stds+i)->d->month,(stds+i)->d->year,(stds+i)->info.address);
    }
}

int main() {
    
    int n;
    printf("Enter the number of students ");
    scanf("%d",&n);
    STUDENT *stds;
    stds = (STUDENT *) malloc (n*sizeof(STUDENT *));

    read(stds,n);
    display(stds,n);

    return 0;
}