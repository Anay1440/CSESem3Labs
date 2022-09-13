import java.util.Scanner;
class script02 {
    static Scanner sc = new Scanner(System.in);
    public static void insert(int arr[],int n) {
        System.out.print("Enter the number you want to insert ");
        int num = sc.nextInt();
        System.out.print("Enter the position where you want to insert the number ");
        int ind = sc.nextInt();
        ind=ind-1;
        for(int i=n;i>=ind;i--) {
            arr[i] = arr[i-1];
        }
        arr[ind] = num;
        System.out.println("The new array is:\n");
        for(int i=0;i<n+1;i++) {
            System.out.print(arr[i]+" ");
        }
    }
    public static void delete(int arr[],int n) {
        System.out.print("Enter the position where you want to delete the number ");
        int ind = sc.nextInt();
        ind=ind-1;
        for(int i=ind;i<n;i++) {
            arr[i] = arr[i+1];
        }
        System.out.println("The new array is:\n");
        for(int i=0;i<n-1;i++) {
            System.out.print(arr[i]+" ");
        }
    }
    public static void main(String args[]) {
        System.out.print("Enter number of elements in array ");
        int n = sc.nextInt();
        int arr[] = new int[n+1];
        for(int i=0;i<n;i++) {
            System.out.print("Enter element no. "+i+" ");
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter 1 for inserting, and 2 for deleting ");
        int choice = sc.nextInt();
        if (choice == 1) {
            insert(arr,n);
        }
        else if (choice == 2) {
            delete(arr,n);
        }
        else {
            System.out.println("Invalid input");
        }
    }
}