import java.util.Scanner;
class test {
    public static void main(String args[]) {
        // String a="1/12/22";
        // int c=0,i=0;
        // int ind=-1;
        // while(c!=2) {
        //     if(a.charAt(i) == '/') {
        //         c+=1;
        //     }
        //     else {
        //         ind=i+1;
        //     }
        //     i+=1;
        // }
        // int year = Integer.parseInt(a.substring(ind+1,a.length()));
        // System.out.println(year);
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your name ");
        String fName = sc.nextLine();
        System.out.print("Enter date of joining in the format dd/mm/yy ");
        String DateOJ = sc.nextLine();
        System.out.println(DateOJ);
    }
}