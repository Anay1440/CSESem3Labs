import java.util.Scanner;
class Counter {
    static int count=0;
    Counter() {
        count+=1;
    }

    static void showCount() {
        System.out.println("The counter is: "+count);
    }
}

class script04 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of objects you want to create: ");
        int n = sc.nextInt();

        Counter objs[] = new Counter[n];
        for(int i=0;i<n;i++) {
            objs[i] = new Counter();
        }

        objs[0].showCount();
    }
}