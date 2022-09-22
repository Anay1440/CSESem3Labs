import java.util.Scanner;

abstract class figure {
    int a,b;
    abstract int area();
}

class Rectangle extends figure {
    Rectangle(int x,int y) {
        a=x;
        b=y;
    }
    int area() {
        return (a*b);
    }
}

class Square extends figure {
    Square(int x) {
        a=x;
    }
    int area() {
        return (a*a);
    }
}

class Triangle extends figure {
    Triangle(int x,int y) {
        a=x;
        b=y;
    }
    int area() {
        return ( (int) a*b/2);
    }
}

public class Q3AbstractClassFigure {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("1.Rectangle, 2.Square, 3.Triangle ");
        int input = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter the first dimension ");
        int a = sc.nextInt();
        System.out.print("Enter the second dimension ");
        int b = sc.nextInt();
        int area=0;
        if (input == 1) {
            Rectangle rect= new Rectangle(a,b);
            area = rect.area();
        }
        else if (input == 2) {
            Square sq = new Square(a);
            area = sq.area();
        }
        else if(input == 3) {
            Triangle t = new Triangle(a,b);
            area = t.area();
        }
        else {
            System.out.println("Invalid Input");
        }
        System.out.println("The area is: "+area);
    }
}
