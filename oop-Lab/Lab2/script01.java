import java.util.Scanner;
class script01 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements in array ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++) {
            System.out.print("Enter element no. "+i+" ");
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter 1 for ascending, and 2 for descending ");
        int choice = sc.nextInt();
        if (choice == 1) {
            for(int i=0;i<n-1;i++) {
                for(int j=i;j<n;j++) {
                    if(arr[i]>arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        else if (choice == 2) {
            for(int i=0;i<n-1;i++) {
                for(int j=i;j<n;j++) {
                    if(arr[i]<arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        else {
            System.out.println("Invalid choice");
        }
        System.out.println("The sorted array is:\n");
        for(int i=0;i<n;i++) {
            System.out.print(arr[i]+" ");
        }
    }
}