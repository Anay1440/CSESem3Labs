import java.util.Scanner;
class Q4CommaPunctuatedNums {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number ");
        long n = sc.nextLong();
        String nStr = Long.toString(n);
        String out = "";
        int count=0;
        for(int i=nStr.length()-1;i>=0;i--) {
                if (count == 3) {
                    count = 0;
                    out = out + ',';
                    i +=1;
                }
                else {
                    count += 1;
                    out = out + nStr.charAt(i);
                }
        }

        String finalout = "";
        for (int i=0;i<out.length();i++) {
            finalout = finalout + out.charAt(out.length()-1-i);
        }

        System.out.println("The comma punctuated number is: " + finalout);
    }
}