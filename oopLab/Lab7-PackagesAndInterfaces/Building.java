package com.course.structure;
import java.util.Scanner;


public class Building {
    Scanner sc = new Scanner(System.in);

    double sqFootage;
    int stories;

    public Building() {
        sqFootage = -1;
        stories = -1;
    }

    public void assign() {
        System.out.print("Enter the square footage ");
        double sq = sc.nextDouble();
        System.out.print("Enter number of stories ");
        int s = sc.nextInt();
        sqFootage = sq;
        stories = s;
    }

    public void display() {
        System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories);
    }

    public class House {
        int numOfBed,numOfBath;

        public House() {
            numOfBed = -1;
            numOfBath = -1;
        }

        public void assign() {
            System.out.print("Enter number of bedrooms ");
            int n1 = sc.nextInt();
            System.out.print("Enter number of bathrooms ");
            int n2 = sc.nextInt();
            numOfBed = n1;
            numOfBath = n2;
        }

        public void display() {
            System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories+"\nNumber of bedrooms: "+numOfBed+"\nNumber of bathrooms: "+numOfBath);
        }
    }

    public class School {
        int numOfClassRooms;
        String gradeLev;

        public School() {
            numOfClassRooms = -1;
            gradeLev = "Default";
        }

        public void assign() {
            System.out.print("Enter number of class rooms ");
            int n = sc.nextInt();
            sc.nextLine();
            System.out.print("Enter grade level ");
            String glev = sc.next();
            numOfClassRooms = n;
            gradeLev = glev;
        }

        public void display() {
            System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories+"\nNumber of classrooms: "+numOfClassRooms+"\nGrade Level: "+gradeLev);
        }
    }
}
