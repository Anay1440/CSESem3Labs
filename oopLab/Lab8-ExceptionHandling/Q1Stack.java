import java.util.Scanner;
class Stack {
    int arr[];
    int tos;

    Scanner sc = new Scanner(System.in);

    void initialiseTOS() {
        tos=-1;
        System.out.print("Enter max length of stack ");
        int n = sc.nextInt();
        arr = new int[n];
    }

    void push() {
        try {
            System.out.print("Enter integer to push ");
            arr[++tos] = sc.nextInt();
        } 
        catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Error. Stack Overflow");
            tos-=1;
        }
    }

    int pop() {
        try {
            return arr[(tos--)];
        } 
        catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Error. Stack Underflow");
            tos+=1;
            return -1;
        }
    }
}

class Q1Stack {
    public static void main(String args[]) {
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