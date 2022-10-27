import java.util.Scanner;
class Q1ArrayExchange {
    
    static <T> void exchange(T arr[],int a,int b) {
        T temp;
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    static <T> void display(T arr[]) {
        for(int i=0;i<arr.length;i++) 
            System.out.print(arr[i]+" ");
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Integer array, 2. String array, 3. Double array ");
        int inp = sc.nextInt();
        System.out.print("Enter length of array ");
        int n = sc.nextInt();
        System.out.print("Enter index 1 ");
        int a = sc.nextInt();
        System.out.print("Enter index 2 ");
        int b = sc.nextInt();
        if (inp == 1) {
            Integer arr[] = new Integer[n];
            for(int i=0;i<n;i++) {
                System.out.print("Enter data ");
                arr[i]=sc.nextInt();
            }
            exchange(arr,a,b);
            display(arr);
        }
        else if (inp == 2) {
            String arr[] = new String[n];
            for(int i=0;i<n;i++) {
                System.out.print("Enter data ");
                arr[i]=sc.next();
            }
            exchange(arr,a,b);
            display(arr);
        }
        else if (inp == 3) {
            Double arr[] = new Double[n];
            for(int i=0;i<n;i++) {
                System.out.print("Enter data ");
                arr[i]=sc.nextDouble();
            }
            exchange(arr,a,b);
            display(arr);
        }
        else 
            System.out.println("Invalid input");
        sc.close();
    }
}
