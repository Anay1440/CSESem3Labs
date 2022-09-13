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
        System.out.print("Enter integer to push ");
        int t = sc.nextInt();
        if ((tos+1) < (arr.length-1)) {
            arr[(tos+1)] = t;
            tos+=1;
        }
        else {
            System.out.println("Error. Stack Overflow");
        }
    }

    void pop() {
        if(tos==-1) {
            System.out.println("Error. Stack Underflow");
        }
        else {
            arr[tos] = -1;
            tos-=1;
        }
    }

    void display() {
        System.out.println();
        for(int i=0;i<=tos;i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}

class script04 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Stack s = new Stack();
        s.initialiseTOS();
        int input = 1;
        int flag = 1;
        while ((input != -1) | (flag != 0)) {
            System.out.print("Enter 1 for push, 2 for pop, 3 for display, and -1 to exit ");
            input = sc.nextInt();
            if (input == 1) {
                s.push();
            }
            else if (input == 2) {
                s.pop();
            }
            else if (input == 3) {
                s.display();
            }
            else {
                System.out.println("Exiting");
                flag = 0;
            }
        }
    }
}