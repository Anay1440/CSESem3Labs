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
        sqFootage = sc.nextDouble();
        System.out.print("Enter number of stories ");
        stories = sc.nextInt();
    }

    public void display() {
        System.out.println("Square Footage: "+sqFootage+"\nStories: "+stories);
    }
}