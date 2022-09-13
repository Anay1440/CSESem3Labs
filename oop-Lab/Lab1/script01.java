import java.util.Scanner;
class script01 {

    public static int largest(int a,int b,int c) {
        if(a>b && a>c) {
            return a;
        }
        else if(b>a && b>c) {
            return b;
        }
        else {
            return c;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an integer ");
        int a = sc.nextInt();
        System.out.print("Enter an integer ");
        int b = sc.nextInt();
        System.out.print("Enter an integer ");
        int c = sc.nextInt();
        int max = largest(a,b,c);
        System.out.println("The largest of the three numbers is:"+max);
    }
}