import java.util.Scanner;

class Student {
    int regno;
    String fName;
    String DOJ;
    short sem;
    float gpa,cgpa;
    static int count=1;

    Student() {
        count+=1;
    }

    String calcYear(String DOJ) {
        int c=0,i=0;
        int ind=-1;
        while(c!=2) {
            if(DOJ.charAt(i) == '/') {
                c+=1;
            }
            else {
                ind=i+1;
            }
            i+=1;
        }
        return (DOJ.substring(ind+1,DOJ.length()));
    }

    Student(String name,String DateOJ,short semester,float gpavg,float cgpavg) {
        String y = calcYear(DateOJ);
        String n = Integer.toString(count);
        String regnumString = y+n;
        regno = Integer.parseInt(regnumString);
        fName = name;
        DOJ = DateOJ;
        sem=semester;
        gpa=gpavg;
        cgpa=cgpavg;
        count+=1;
    }

    void display() {
        System.out.println("\nName of student: "+fName+"\nRegistration Number: "+regno+"\nDate of joining: "+DOJ+"\nSemester: "+sem+"\nGPA: "+gpa+"\nCGPA: "+cgpa);
    }
}

class script01 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students. (Minimum 5) ");
        int n = sc.nextInt();
        sc.nextLine();
        Student stds[] = new Student[n];
        for(int i=0;i<n;i++) {
            System.out.println("\nEnter details for student number "+(i+1));
            System.out.print("Enter your name ");
            String fName = sc.nextLine();
            System.out.print("Enter date of joining in the format dd/mm/yy ");
            String DateOJ = sc.nextLine();
            System.out.print("Enter your semester ");
            short semester = sc.nextShort();
            System.out.print("Enter your gpa ");
            float gpavg = sc.nextFloat();
            System.out.print("Enter your cgpa ");
            float cgpavg = sc.nextFloat();
            sc.nextLine();

            stds[i] = new Student(fName,DateOJ,semester,gpavg,cgpavg);
        }

        System.out.println("\nDisplaying details of all students:\n");
        for(int i=0;i<n;i++) {
            System.out.println("\nDisplaying details for student number "+(i+1));
            stds[i].display();
        }
    }
}