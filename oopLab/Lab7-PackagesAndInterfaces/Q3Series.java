import java.util.Scanner;

interface Series {
    int getNext();
    void reset();
    void setStart(int a);
}

class ByTwos implements Series {
    int a;
    public int getNext() {
        a+=2;
        return (a);
    }
    public void setStart(int x) {
        a = x;
    }
    public void reset() {
        a = 0;
    }
}

public class Q3Series {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Default start is set as 0");
        ByTwos obj = new ByTwos();
        obj.setStart(0);
        int inp=-1;
        System.out.print("1.Get Next, 2.Reset, 3.Set Start");
        do {
            System.out.print("\nEnter choice ");
            inp = sc.nextInt();
            if (inp == 1) 
                System.out.print(obj.getNext());
            else if(inp == 2) {
                obj.reset();
                System.out.println("Series was reset");
            }
            else if(inp == 3) {
                System.out.print("Enter start ");
                obj.setStart(sc.nextInt());
            }
            else {
                inp = -1;
            }
        } while(inp != -1);
    }
}
