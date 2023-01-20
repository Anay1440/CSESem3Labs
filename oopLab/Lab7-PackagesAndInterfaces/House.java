package com.course.structure;
import java.util.Scanner;

public class House extends Building {
    int numOfBed,numOfBath;
    Scanner sc = new Scanner(System.in);

    public House() {
        super();
        numOfBed = -1;
        numOfBath = -1;
    }

    public void assign() {
        super.assign();
        System.out.print("Enter number of bedrooms ");
        numOfBed = sc.nextInt();
        System.out.print("Enter number of bathrooms ");
        numOfBath = sc.nextInt();
    }

    public void display() {
        super.display();
        System.out.println("Number of bedrooms: "+numOfBed+"\nNumber of bathrooms: "+numOfBath);
    }
}
