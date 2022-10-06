import myPackages.p1.Maximum;
import java.util.Scanner;

public class Q2Maximum {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Maximum obj = new Maximum();

        System.out.print("Find max in: 1. 3 ints, 2. 3 floats, 3. Array, 4. Matrix ");
        int inp = sc.nextInt();

        switch(inp) {
            case 1: System.out.print("Enter first integer ");
            int a1 = sc.nextInt();
            System.out.print("Enter second integer ");
            int b1 = sc.nextInt();
            System.out.print("Enter third integer ");
            int c1 = sc.nextInt();
            int ans1 = obj.max(a1,b1,c1);
            System.out.println("MAX is: "+ans1);
            break;

            case 2:System.out.print("Enter first float ");
            float a2 = sc.nextFloat();
            System.out.print("Enter second float ");
            float b2 = sc.nextFloat();
            System.out.print("Enter third float ");
            float c2 = sc.nextFloat();
            float ans2 = obj.max(a2,b2,c2);
            System.out.println("MAX is: "+ans2);
            break;

            case 3:System.out.print("Enter n ");
            int n = sc.nextInt();
            int arr[] = new int[n];
            for (int i =0; i<n;i++) {
                System.out.print("Enter element no. "+(i+1)+" ");
                arr[i] = sc.nextInt();
            }
            int ans3 = obj.max(arr);
            System.out.println("MAX is: "+ans3);
            break;

            case 4:System.out.print("Enter r ");
            int r = sc.nextInt();
            System.out.print("Enter c ");
            int c = sc.nextInt();
            int mat[][] = new int[r][c];
            for(int i=0;i<r;i++) {
                for(int j = 0;j<c;j++) {
                    System.out.print("Enter element at ("+i+","+j+") ");
                    mat[i][j] = sc.nextInt();
                }
            }
            int ans4 = obj.max(mat);
            System.out.println("MAX is: "+ans4);
            break;

            default:System.out.println("INVALID INPUT");
        }
    }
}
