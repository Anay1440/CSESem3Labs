import java.util.Scanner;

interface Sports {
    void putGrade(int a);
    int getGrade();
}

class Student {
    int num,marks;

    Student(int n, int m) {
        putNumber(n);
        putMarks(m);
    }

    void putNumber(int a) {
        num = a;
    }
    void putMarks(int a) {
        marks = a;
    }
    int getNumber() {
        return num;
    }
    int getMarks() {
        return marks;
    }
}
class Result extends Student implements Sports {
    int sportsGrade;

    Result(int n, int m, int s) {
        super(n,m);
        putGrade(s);
    }

    public void putGrade(int a) {
        sportsGrade = a;
    }
    public int getGrade() {
        return sportsGrade;
    }
    public void display() {
        System.out.println("Roll Number: "+getNumber()+"\nMarks: "+getMarks()+"\nSports Grade: "+getGrade());
    }
}


public class Q4Student {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter roll number ");
        int n = sc.nextInt();
        System.out.print("Enter marks ");
        int m = sc.nextInt();
        System.out.print("Enter sports grade ");
        int s = sc.nextInt();
        Result st = new Result(n, m, s);
        System.out.println("\nDisplaying results:");
        st.display();
    }
}
