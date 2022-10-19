import java.util.Scanner;
class StackExceptions extends Exception {
    private String errorCode;
    StackExceptions(String err) {
        errorCode = err;
    }

    String getCode() {
        return errorCode;
    }
}

class Stack {
    int arr[];
    int tos;

    Scanner sc = new Scanner(System.in);

    StackExceptions stackFull = new StackExceptions("Stack Overflow");
    StackExceptions stackEmpty = new StackExceptions("Stack underflow");

    void initialiseTOS() {
        tos=-1;
        System.out.print("Enter max length of stack ");
        int n = sc.nextInt();
        arr = new int[n];
    }

    void push() throws StackExceptions {
        try {
            if (tos == arr.length - 1)
                throw stackFull;
            System.out.print("Enter integer to push ");
            arr[++tos] = sc.nextInt();
        } 
        catch(StackExceptions e) {
            System.out.println("Error. "+e.getCode());
            tos-=1;
        }
    }

    int pop() throws StackExceptions {
        try {
            if (tos == -1)
                throw stackEmpty;
            return arr[(tos--)];
        } 
        catch(StackExceptions e) {
            System.out.println("Error. "+e.getCode());
            tos+=1;
            return -1;
        }
    }
}

class Q1Stack {
    public static void main(String args[]) throws StackExceptions {
        Scanner sc = new Scanner(System.in);
        Stack s = new Stack();
        s.initialiseTOS();
        int input = 1;
        int flag = 1;
        while ((input != -1) | (flag != 0)) {
            System.out.print("Enter 1 for push, 2 for pop and -1 to exit ");
            input = sc.nextInt();
            if (input == 1) {
                s.push();
            }
            else if (input == 2) {
                System.out.println("Integer popped is: "+s.pop());
            }
            else {
                System.out.println("Exiting");
                flag = 0;
            }
        }
    }
}