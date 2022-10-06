import java.util.Scanner;

interface Sports {
    void putGrade(int a);
    int getGrade();
}

class Student {
    int num,marks;
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

    class Result implements Sports {
        int sportsGrade;
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
}

public class Q4Student {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        Student s = new Student();
        Student.Result ssp = s.new Result();

        System.out.print("Enter roll number ");
        s.putNumber(sc.nextInt());
        System.out.print("Enter marks ");
        s.putMarks(sc.nextInt());
        System.out.print("Enter sports grade ");
        ssp.putGrade(sc.nextInt());
        System.out.println("\nDisplaying results:");
        ssp.display();
    }
}
