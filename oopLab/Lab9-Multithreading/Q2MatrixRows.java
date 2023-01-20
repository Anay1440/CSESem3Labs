import java.util.Scanner;

class NewThread implements Runnable {
    String name;
    Thread t;
    int row[];
    int sum;

    NewThread(String s,int r[]) {
        name=s;
        row=r;
        t = new Thread(this,name);
        t.start();
    }

    public void run() {
        sum=0;
        for(int i=0;i<row.length;i++) {
            sum+=row[i];
        }
        System.out.println("Sum of "+name+" = "+sum);
    }

    int getSum() {
        return sum;
    }
}

class Q2MatrixRows {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter rows: ");
        int r = sc.nextInt();
        System.out.print("Enter columns: ");
        int c = sc.nextInt();
        int mat[][] = new int[r][c];
        int sum=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                System.out.printf("Enter element at (%d,%d) ",i,j);
                mat[i][j] = sc.nextInt();
            }
        }

        NewThread rows[] = new NewThread[r];
        for (int i=0;i<r;i++) {
            String t = "Row "+i;
            rows[i] = new NewThread(t, mat[i]);
        }
        
        try {
            for (int i=0;i<r;i++) {
                rows[i].t.join();
                sum+=rows[i].getSum();
            }
        }
        catch(InterruptedException e) {
            System.out.println("Interrupted..");
        }
        
        System.out.println("Total Sum: "+sum);
    }
}
