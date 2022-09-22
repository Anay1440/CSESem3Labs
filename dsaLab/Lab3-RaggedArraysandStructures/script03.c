#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int houseNo;
    int zipCode;
    char state[50];
} Address;

typedef struct {
    char name[50];
    Date d;
    Address addr;
} Employee;


void read(Employee *e,int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("\nEnter firstname ");
        scanf("%s",(e+i)->name);
        printf("Enter Day of DOB ");
        scanf("%d",&((e+i)->d.day));
        printf("Enter Month of DOB ");
        scanf("%d",&((e+i)->d.month));
        printf("Enter year for DOB ");
        scanf("%d",&((e+i)->d.year));
        printf("Enter House number ");
        scanf("%d",&((e+i)->addr.houseNo));
        printf("Enter zip code ");
        scanf("%d",&((e+i)->addr.zipCode));
        printf("Enter the state ");
        scanf("%s",(e+i)->addr.state);
    }
}


void display(Employee *e,int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("\nDetails of employee number %d ",(i+1));
        printf("\nName of employee : %s\nDOB: %d : %d : %d\nAddress: House No. %d, Zip Code : %d, State : %s",(e+i)->name,(e+i)->d.day,(e+i)->d.month,(e+i)->d.year,(e+i)->addr.houseNo,(e+i)->addr.zipCode,(e+i)->addr.state);
    }
}

int main() {
    
    int n;
    printf("Enter number of employees ");
    scanf("%d",&n);
    Employee * emps;
    emps = (Employee *) malloc(n*sizeof(Employee *));

    read(emps,n);
    display(emps,n);

    return 0;
}