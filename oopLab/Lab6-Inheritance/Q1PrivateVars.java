class Person {
    private String name;
    private String DOB;

    Person() {
        name = "Default";
        DOB = "xx/xx/xxxx";
    }

    void accessNameandDOB() {
        System.out.println("Name: "+name+"\nDOB: "+DOB);
    }

}

class CollegeGraduate extends Person {
    private double cgpa;
    private int year;

    CollegeGraduate() {
        super();
        cgpa = -1;
        year = -1;
    }


    void accessDetails() {
        accessNameandDOB();
        System.out.println("\nCGPA: "+cgpa+"\nYear of graduation: "+year);
    }
}



class Q1PrivateVars {
    public static void main(String args[]) {
        System.out.println("Accessing Person's details:\n");
        Person p1 = new Person();
        p1.accessNameandDOB();
        System.out.println("\nAccessing College Graduates details:\n");
        CollegeGraduate cg = new CollegeGraduate();
        cg.accessDetails();
    }
}
