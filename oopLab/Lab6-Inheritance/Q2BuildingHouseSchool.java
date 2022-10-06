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
        double sq = sc.nextDouble();
        System.out.print("Enter number of stories ");
        int s = sc.nextInt();
        sqFootage = sq;
        stories = s;
    }

    void display() {
        System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories);
    }

    class House {
        int numOfBed,numOfBath;

        House() {
            numOfBed = -1;
            numOfBath = -1;
        }

        void assign() {
            System.out.print("Enter number of bedrooms ");
            int n1 = sc.nextInt();
            System.out.print("Enter number of bathrooms ");
            int n2 = sc.nextInt();
            numOfBed = n1;
            numOfBath = n2;
        }

        void display() {
            System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories+"\nNumber of bedrooms: "+numOfBed+"\nNumber of bathrooms: "+numOfBath);
        }
    }

    class School {
        int numOfClassRooms;
        String gradeLev;

        School() {
            numOfClassRooms = -1;
            gradeLev = "Default";
        }

        void assign() {
            System.out.print("Enter number of class rooms ");
            int n = sc.nextInt();
            String dump = sc.nextLine();
            System.out.print("Enter grade level ");
            String glev = sc.next();
            numOfClassRooms = n;
            gradeLev = glev;
        }

        void display() {
            System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories+"\nNumber of classrooms: "+numOfClassRooms+"\nGrade Level: "+gradeLev);
        }
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
            Building.House h =  b.new House();
            b.assign();
            h.assign();
            h.display();
        }
        if (input == 3) {
            Building.School s = b.new School();
            b.assign();
            s.assign();
            s.display();
        }
    }
}
