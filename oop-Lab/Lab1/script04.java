import java.util.Scanner;    
class script04 {

    public static boolean isPrime(int n) {
        int count=0;

        if (n <= 1) {
            return false;
        }

        for(int i=2;i<=n/2;i++) {
            if (n%i==0) {
                count+=1;
            }
        }
        if (count > 0) {
            return false;
        }
        else {
            return true;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n ");
        int n = sc.nextInt();
        for(int i=1;i<=n;i++) {
            if (isPrime(i)) {
                System.out.print(i+" ");
            }
        }
    }
}