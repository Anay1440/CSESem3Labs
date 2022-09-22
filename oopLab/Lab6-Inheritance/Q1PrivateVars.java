import java.util.Scanner;

class Person {
    private String name;
    private String DOB;

    Person() {
        name = "Default";
        DOB = "xx/xx/xxxx";
    }

    // Person(String nam,String date) {
    //     name = nam;
    //     DOB = date;
    // }

    void accessNameandDOB() {
        System.out.println("Name: "+name+"\nDOB: "+DOB);
    }

    class CollegeGraduate {
        private double cgpa;
        private int year;

        CollegeGraduate() {
            cgpa = -1;
            year = -1;
        }

        // CollegeGraduate(double c,int y) {
        //     cgpa = c;
        //     year = y;
        // }

        void accessDetails() {
            System.out.println("This is inside the inner class\nName: "+name+"\nDOB: "+DOB+"\nCGPA: "+cgpa+"\nYear of graduation: "+year);
        }
    }
}



class Q1PrivateVars {
    public static void main(String args[]) {
        System.out.println("Accessing Person's details:\n");
        Person p1 = new Person();
        p1.accessNameandDOB();
        System.out.println("\nAccessing College Graduates details:\n");
        Person.CollegeGraduate cg = p1.new CollegeGraduate();
        cg.accessDetails();
        System.out.println("Object of class Person cannot access cgpa and year, but object of CollegeGraduate can access name and DOB\n");
    }
}
