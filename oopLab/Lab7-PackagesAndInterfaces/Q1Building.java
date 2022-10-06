import com.course.structure.Building;
import com.course.structure.Building.School;
import com.course.structure.Building.House;

import java.util.Scanner;

public class Q1Building {
    public static void main(String args[]) {
        
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Building only, 2. House, 3. School ");
        int input = sc.nextInt();
        Building b = new Building();
        if (input == 1) {
            b.assign();
            b.display();
        }
        else if (input == 2) {
            Building.House h =  b.new House();
            b.assign();
            h.assign();
            h.display();
        }
        else if (input == 3) {
            Building.School s = b.new School();
            b.assign();
            s.assign();
            s.display();
        }
        
    }
}
