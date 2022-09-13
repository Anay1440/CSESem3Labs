import java.util.Scanner;    
class script02 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a ");
        int a = sc.nextInt();
        System.out.print("Enter b ");
        int b = sc.nextInt();
        System.out.print("Enter c ");
        int c = sc.nextInt();
        double d = (b*b - 4*a*c);
        switch(d>=0?1:0) {
            case 1:
            double r1 = (-b/(2*a)) + (Math.sqrt(d)/(2*a));
            double r2 = (-b/(2*a)) - (Math.sqrt(d)/(2*a));
            System.out.print("The roots are: "+r1+" and "+r2);
            break;
            default:
            d=-d;
            double rReal = (-b/(2*a));
            double rImag = Math.sqrt(d)/(2*a);
            System.out.print("The roots are: "+rReal+"+"+rImag+"i"+" and "+rReal+"-"+rImag+"i");
        }
    }
}