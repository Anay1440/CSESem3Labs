import java.util.Scanner;

class NewThread implements Runnable {
    String name;
    Thread t;
    int row[];
    int sum,completed;

    NewThread(String s,int r[]) {
        name=s;
        row=r;
        completed=-1;
        t = new Thread(this,name);
        t.start();
    }

    public void run() {
        sum=0;
        for(int i=0;i<row.length;i++) {
            sum+=row[i];
        }
        System.out.println("Sum of "+name+" = "+sum);
        completed=1;
    }

    int getSum() {
        return sum;
    }
    int getCompleted() {
        return completed;
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
        // try{
        //     System.out.println("Sleeping for 1 second");
        //     Thread.sleep(1000);
        // }
        // catch(InterruptedException e) {
        //     System.out.println("Interrupted..");
        // }
        
        //to check if the threads have all ended
        while (true) {
            int flag=-1;
            for (int i=0;i<r;i++) {
                flag=1;
                if (rows[i].getCompleted() == -1)
                    flag=-1;
            }
            if (flag == 1)
                break;
        }    

        for (int i=0;i<r;i++) {
            sum+=rows[i].getSum();
        }
        
        System.out.println("Total Sum: "+sum);
    }
}
