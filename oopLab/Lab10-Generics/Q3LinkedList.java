import java.util.Scanner;
class node<T> {
    T data;
    node<T> next;

    node(T inpData) {
        data = inpData;
        next = null;
    }
}

class list<T> {
    node<T> head;
    list() {
        head=null;
    }

    void insertNode(T inpData) {
        node<T> node1 = new node<T>(inpData);

        if (head == null)
            head = node1;
        else {
            node <T> list = head;
            while (list.next != null) 
                list = list.next;
            list.next = node1;
        }
    }

    void display() {
        node<T> node1 = head;
        while(node1 != null) {
            System.out.print(node1.data+" ");
            node1 = node1.next;
        }
    }
}

public class Q3LinkedList {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Integer list, 2. String list ");
        int inp = sc.nextInt();
        System.out.print("Enter length of list ");
        int n = sc.nextInt();
        if (inp == 1) {
            list<Integer> list1 = new list<>();
            for(int i=0;i<n;i++) {
                System.out.print("Enter node data ");
                list1.insertNode(sc.nextInt());
            }
            System.out.print("\nThe list is: ");
            list1.display();
        }
        else if (inp == 2) {
            list<String> list1 = new list<>();
            for(int i=0;i<n;i++) {
                System.out.print("Enter node data ");
                list1.insertNode(sc.next());
            }
            System.out.print("\nThe list is: ");
            list1.display();
        }
        else
            System.out.println("Invalid input");
        sc.close();
    }
}
