import java.util.Scanner;
class script03 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements in array ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++) {
            System.out.print("Enter element no. "+i+" ");
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter the number to search for ");
        int x = sc.nextInt();
        int ind=-1;
        for(int i=0;i<n;i++) {
            if (arr[i] == x) {
                ind=i;
            }
        }
        if (ind == -1) {
            System.out.println("The element does not exist in array");
        }
        else {
            System.out.println("The element is at position "+(ind+1));
        }
    }
}