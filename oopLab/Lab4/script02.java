import java.util.Scanner;

class Time {
    int hrs, mins, sec, day;

    Time() {
        hrs=0;
        mins=0;
        sec=0;
        day=0;
    }

    Time(int h, int m, int s) {
        hrs = h;
        mins = m;
        sec = s;
    }

    void display() {
        System.out.println(hrs+":"+mins+":"+sec);
    }

    Time add(Time t1,Time t2) {
        Time tAns = new Time();
        int val1 = calcValue(t1);
        int val2 = calcValue(t2);
        int val3 = val1 + val2;
        tAns = convert(val3);
        return tAns;
    }

    int calcValue(Time t1) {
        return ((t1.hrs * 3600) + (t1.mins * 60) + t1.sec);
    }

    int compare(Time t1, Time t2) {
        int val1 = calcValue(t1);
        int val2 = calcValue(t2);
        if (val1 > val2) {
            return 1;
        }
        else if (val2 > val1) {
            return 2;
        }
        return 3;
    }

    Time convert(int val) {
        Time tAns = new Time();
        double temp = (double) val/3600;
        int hrs = (int) temp;
        temp=temp-hrs;
        temp = temp*60;
        int mins = (int) temp;
        temp = temp-mins;
        temp = temp * 60;
        int sec = (int) temp;
        if (hrs >= 24) {
            tAns.day=1;
            hrs=24-hrs;
        }
        tAns.hrs=hrs;
        tAns.mins=mins;
        tAns.sec=sec;
        return tAns;
    }

    Time subtract(Time t1) {
        int val1 = calcValue(t1);
        int val2 = (hrs * 3600) + (mins * 60) + sec;
        int val3;
        Time tAns = new Time();
        if (val1 > val2) {
            val3 = val1 - val2;
            tAns = convert(val3);
        }
        else {
            val3 = val2 - val1;
            tAns = convert(val3);
        }
        
        return tAns;
    }
}

class script02 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);


        Time t3 = new Time();
        System.out.println("The default constructor has been called. The values are: ");
        t3.display();

        System.out.print("Enter hrs for time 1 ");
        int hrs1 = sc.nextInt();
        System.out.print("Enter mins for time 1 ");
        int mins1 = sc.nextInt();
        System.out.print("Enter seconds for time 1 ");
        int sec1 = sc.nextInt();
        System.out.print("Enter hrs for time 2 ");
        int hrs2 = sc.nextInt();
        System.out.print("Enter mins for time 2 ");
        int mins2 = sc.nextInt();
        System.out.print("Enter seconds for time 2 ");
        int sec2 = sc.nextInt();

        Time t1 = new Time(hrs1,mins1,sec1);
        Time t2 = new Time(hrs2,mins2,sec2);

        System.out.println("Time 1 is:");
        t1.display();
        System.out.println("Time 2 is:");
        t2.display();

        t3=t1.add(t1,t2);
        System.out.println("The result time after addition is:");
        if (t3.day == 1) {
            System.out.println("The result time is on the next day");
        }
        t3.display();

        t3=t1.subtract(t2);
        System.out.println("The result time after subtraction is:");
        t3.display();

        System.out.println("The comparison of both times results in");
        int b=t3.compare(t1,t2);
        if (b == 1) {
            System.out.println("The first time is more than the second");
        }
        else if (b == 2) {
            System.out.println("The second time is more than the first");
        }
        else {
            System.out.println("Both times are equal");
        }
    }
}