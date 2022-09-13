import java.util.Scanner;    
class script03 {

    public static int fact(int n) {
        if (n==1) {
            return 1;
        }
        else {
            return n*fact(n-1);
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n ");
        int n = sc.nextInt();
        System.out.print("Enter r ");
        int r = sc.nextInt();
        int nFact = fact(n);
        int rFact = fact(r);
        int nrFact = fact(n-r);
        double ans = nFact/(rFact*nrFact);
        System.out.println("The NCR is: "+ans);
    }
}