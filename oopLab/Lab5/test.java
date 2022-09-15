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
        String name = sc.nextLine();
        int flag=0;
        String temp="";
        char initial=' ';
        String out ="";

        for(int i=0;i<name.length();i++) {
            if ( Character.isUpperCase(name.charAt(i))) {
                flag=1;
                initial=name.charAt(i);
            }
            if (flag == 1) {
                temp = temp + name.charAt(i);
            }
            if ( name.charAt(i) == ' ') {
                flag = 0;
                out = out + initial + ". ";
                temp="";
            }
            if (i == name.length()-1) {
                out = out + temp;
            }
        }

        System.out.println("Modified string: "+out);
    }
}