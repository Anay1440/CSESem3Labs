import java.util.Scanner;

class Student {
    String name;
    int id;

    Student() {
        name = "Default";
        id = -1;
    }
}
class Sports extends Student{
    int s_grade;

    Sports() {
        super();
        s_grade = -1;
    }
}


class Exam extends Student {
    int e_grade;

    Exam() {
        super();
        e_grade = -1;
    }
}



class Result extends Student {
    String res="";
    Student s1 = new Student();
    Sports ss1 = new Sports();
    Exam se1 = new Exam();
    Result() {
        res=name+"\n"+"ID: "+id+"\nSports grade: "+ss1.s_grade+"\nExam grade: "+se1.e_grade;
    }
    void display() {
        System.out.println(res);
    }
}

class Q4InheritanceStudent {
    public static void main(String args[]) {
        Result obj = new Result();
        obj.display();
    }
}