import java.util.Scanner;
import java.util.GregorianCalendar;

class Student {
    int regno;
    String fName;
    // String DOJ;
    GregorianCalendar DOJ;
    short sem;
    float gpa,cgpa;
    static int count=1;

    Student() {
        count+=1;
    }

    // String calcYear(String DOJ) {
    //     int c=0,i=0;
    //     int ind=-1;
    //     while(c!=2) {
    //         if(DOJ.charAt(i) == '/') {
    //             c+=1;
    //         }
    //         else {
    //             ind=i+1;
    //         }
    //         i+=1;
    //     }
    //     return (DOJ.substring(ind+1,DOJ.length()));
    // }

    String manipulateName(String name) {
        int flag=0;
        String temp="";
        char initial=' ';
        String out ="";
        for(int i=0;i<name.length();i++) {
            if ( Character.isUpperCase(name.charAt(i))) {
                flag=1;
                initial=name.charAt(i);
            }
            if (flag == 1) {
                temp = temp + name.charAt(i);
            }
            if ( name.charAt(i) == ' ') {
                flag = 0;
                out = out + initial + ". ";
                temp="";
            }
            if (i == name.length()-1) {
                out = out + temp;
            }
        }
        return out;
    }

    Student(String name,int d,int m, int y,short semester,float gpavg,float cgpavg) {
        GregorianCalendar gcal = new GregorianCalendar(y,m,d);
        // String y = calcYear(DateOJ);
        String st = Integer.toString(gcal.get(1));
        String yst = st.substring(2,4);
        String n = Integer.toString(count);
        String regnumString = yst+n;
        regno = Integer.parseInt(regnumString);
        name = manipulateName(name);
        fName = name;
        DOJ = gcal;
        sem=semester;
        gpa=gpavg;
        cgpa=cgpavg;
        count+=1;
    }

    void sortBySem(Student stds[],int n) {
        Student temp = new Student();
        for(int i = 0; i < n-1; i++) {
            for(int j= i; j < n; j++) {
                if ( stds[i].sem < stds[j].sem) {
                    temp = stds[i];
                    stds[i] = stds[j];
                    stds[j] = temp;
                }
                else if (stds[i].sem == stds[j].sem) {
                    if (stds[i].cgpa < stds[j].cgpa) {
                        temp = stds[i];
                        stds[i] = stds[j];
                        stds[j] = temp;
                    }
                }
            }
        }
    }

    void sortByName(Student stds[],int n) {
        Student temp = new Student();
        for(int i=0;i<n-1;i++) {
            for(int j=i;j<n;j++) {
                if (((stds[i].fName).compareTo((stds[j].fName))) > 0) {
                    temp = stds[i];
                    stds[i] = stds[j];
                    stds[j] = temp;
                }
            }
        }
    }

    void display() {
        System.out.println("\nName of student: "+fName+"\nRegistration Number: "+regno+"\nDate of joining: "+DOJ.get(5)+"/"+DOJ.get(2)+"/"+DOJ.get(1)+"\nSemester: "+sem+"\nGPA: "+gpa+"\tCGPA: "+cgpa);
        // System.out.println("\nName of student: "+fName+"\nRegistration Number: "+regno+"\nDate of joining: "+DOJ+"\nSemester: "+sem+"\nGPA: "+gpa+"\nCGPA: "+cgpa);
    }
}

class Q1Q2Q3Merged {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students ");
        int n = sc.nextInt();
        sc.nextLine();
        Student stds[] = new Student[n];
        for(int i=0;i<n;i++) {
            System.out.println("\nEnter details for student "+(i+1));
            System.out.print("Enter your name ");
            String fName = sc.nextLine();
            // System.out.print("Enter date of joining in the format dd/mm/yy ");
            // String DateOJ = sc.nextLine();
            System.out.print("Enter day of DOJ "); //2 digit int
            int d = sc.nextInt();
            System.out.print("Enter month of DOJ "); //2 digit int
            int m = sc.nextInt();
            System.out.print("Enter year of DOJ "); //4 digit int
            int y = sc.nextInt();
            System.out.print("Enter your semester ");
            short semester = sc.nextShort();
            System.out.print("Enter your gpa ");
            float gpavg = sc.nextFloat();
            System.out.print("Enter your cgpa ");
            float cgpavg = sc.nextFloat();
            sc.nextLine();

            stds[i] = new Student(fName,d,m,y,semester,gpavg,cgpavg);
        }

        System.out.println("\nDisplaying details of all students:\n");
        for(int i=0;i<n;i++) {
            System.out.println("\nDisplaying details for student "+(i+1));
            stds[i].display();
        }

        System.out.print("1. Sort by Sem and CGPA 2. Sort by name -1. Exit ");
        int input = sc.nextInt();

        if (input == 1) {
            stds[0].sortBySem(stds, n);
            System.out.println("Details of students sorted by sem and cgpa:\n");
            for(int i=0;i<n;i++) {
                stds[i].display();
            }
            
        }

        else if(input == 2) {
            stds[0].sortByName(stds, n);
            System.out.println("Details of students sorted by name:\n");
            for(int i=0;i<n;i++) {
                stds[i].display();
            }
        }

        else {
            System.out.println("Invalid Input");
        }


        System.out.print("Enter a character ");
        char ch = sc.next().charAt(0);
        System.out.println("The students with their name starting with same character are: ");
        for(int i=0;i<n;i++) {
            if ( stds[i].fName.charAt(0) == ch) {
                stds[i].display();
            }
        }
    }
}