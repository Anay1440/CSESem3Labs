import com.course.structure.Building;
import com.course.structure.School;
import com.course.structure.House;

import java.util.Scanner;

public class Q1Building {
    public static void main(String args[]) {
        
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Building only, 2. House, 3. School ");
        int input = sc.nextInt();
        if (input == 1) {
            Building b = new Building();
            b.assign();
            b.display();
        }
        else if (input == 2) {
            House h =  new House();
            h.assign();
            h.display();
        }
        else if (input == 3) {
            School s = new School();
            s.assign();
            s.display();
        }
        
    }
}
