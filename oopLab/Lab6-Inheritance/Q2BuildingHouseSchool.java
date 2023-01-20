import java.util.Scanner;

class Building {
    Scanner sc = new Scanner(System.in);

    double sqFootage;
    int stories;

    Building() {
        sqFootage = -1;
        stories = -1;
    }

    void assign() {
        System.out.print("Enter the square footage ");
        sqFootage = sc.nextDouble();
        System.out.print("Enter number of stories ");
        stories = sc.nextInt();
    }

    void display() {
        System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories);
    }
}

class House extends Building {
    int numOfBed,numOfBath;
    Scanner sc = new Scanner(System.in);

    House() {
        super();
        numOfBed = -1;
        numOfBath = -1;
    }

    void assign() {
        super.assign();
        System.out.print("Enter number of bedrooms ");
        numOfBed = sc.nextInt();
        System.out.print("Enter number of bathrooms ");
        numOfBath = sc.nextInt();
    }

    void display() {
        super.display();
        System.out.println("Number of bedrooms: "+numOfBed+"\nNumber of bathrooms: "+numOfBath);
    }
}

class School extends Building {
    int numOfClassRooms;
    String gradeLev;

    School() {
        numOfClassRooms = -1;
        gradeLev = "Default";
    }

    void assign() {
        super.assign();
        System.out.print("Enter number of class rooms ");
        numOfClassRooms = sc.nextInt();
        String dump = sc.nextLine();
        System.out.print("Enter grade level ");
        gradeLev = sc.next();
    }

    void display() {
        super.display();
        System.out.println("Number of classrooms: "+numOfClassRooms+"\nGrade Level: "+gradeLev);
    }
}

public class Q2BuildingHouseSchool {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Building only, 2. House, 3. School ");
        int input = sc.nextInt();
        Building b = new Building();
        if (input == 1) {
            b.assign();;
            b.display();
        }
        if (input == 2) {
            House h =  new House();
            h.assign();
            h.display();
        }
        if (input == 3) {
            School s = new School();
            s.assign();
            s.display();
        }
    }
}
