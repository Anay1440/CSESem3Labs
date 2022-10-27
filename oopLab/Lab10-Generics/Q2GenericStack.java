import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
class stack<T> {
    List<T> st;
    int tos,max;

    stack(int n) {
        tos=-1;
        st = new ArrayList<>(n);
        max = n;
    }

    void push(T data) {
        if (tos+1 == max) {
            System.out.println("Error. Stack overflow");
            return;
        }
        tos+=1;
        st.add(tos,data);
    }

    T pop() {
        T data;
        data = st.remove(tos);
        tos-=1;
        return data;
    }
    
}

class Student {
    String name;
    int rollno;
    Student(String n, int r) {
        name = n;
        rollno = r;
    }
}

class Employee {
    String name;
    int id;
    Employee(String n, int i) {
        name = n;
        id = i;
    }
}

public class Q2GenericStack {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter max stack size ");
        int n = sc.nextInt();
        stack<Student> studentStack = new stack<>(n);
        stack<Employee> employeeStack = new stack<>(n);
        System.out.println("1. Push Student, 2. Pop Student, 3. Push Employee, 4. Pop Employee, -1. Exit");
        int inp;
        Student temp1;
        Employee temp2;
        do {
            System.out.print("Enter choice ");
            inp = sc.nextInt();
            if (inp == 1) {
                System.out.print("Enter student's name ");
                String t = sc.next();
                System.out.print("Enter student's roll number ");
                temp1 = new Student(t, sc.nextInt());
                studentStack.push(temp1);
            }
            else if (inp == 2) {
                temp1 = studentStack.pop();
                System.out.println("Popped: Name: "+temp1.name+"\tRoll No: "+temp1.rollno);
            }
            else if (inp == 3) {
                System.out.print("Enter employee's name ");
                String t = sc.next();
                System.out.print("Enter employee's id ");
                temp2 = new Employee(t, sc.nextInt());
                employeeStack.push(temp2);
            }
            else if (inp == 4) {
                temp2 = employeeStack.pop();
                System.out.println("Popped: Name: "+temp2.name+"\tRoll No: "+temp2.id);
            }
            else
                inp = -1;
        } while(inp != -1);
        sc.close();
    }
}
