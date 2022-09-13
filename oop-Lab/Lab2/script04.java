import java.util.Scanner;
class script04 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of rows for matrices ");
        int r1 = sc.nextInt();
        System.out.print("Enter number of columns for matrices ");
        int c1 = sc.nextInt();

        int mat1[][] = new int[r1][c1];
        int mat2[][] = new int[r1][c1];
        int mat3[][] = new int[r1][c1];

        System.out.println("Enter elements for mat1");
        for(int i=0;i<r1;i++) {
            for(int j=0;j<c1;j++) {
                System.out.print("Enter element at index ("+i+","+j+") ");
                mat1[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter elements for mat2");
        for(int i=0;i<r1;i++) {
            for(int j=0;j<c1;j++) {
                System.out.print("Enter element at index ("+i+","+j+") ");
                mat2[i][j] = sc.nextInt();
            }
        }
        for(int i=0;i<r1;i++) {
            for(int j=0;j<c1;j++) {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        System.out.println("The final matrix is:\n");
        for(int i=0;i<r1;i++) {
            for(int j=0;j<c1;j++) {
                System.out.print(mat3[i][j]+" ");
            }
            System.out.println();
        }
    }
}