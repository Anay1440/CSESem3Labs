import java.util.Scanner;
class MyExceptions extends Exception {
    private String errorCode;
    MyExceptions(String err) {
        errorCode = err;
    }

    String getCode() {
        return errorCode;
    }
}
class CurrentDate {
    int day,month,year;

    void createDate() {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter day ");
        day = s.nextInt();
        System.out.print("Enter month ");
        month = s.nextInt();
        System.out.print("Enter year ");
        year = s.nextInt();
    }

}

class Q2Date {
    public static void main(String args[]) throws MyExceptions {
        MyExceptions invalMonth = new MyExceptions("InvalidMonthException");
        MyExceptions invalDay = new MyExceptions("InvalidDayException");
        try {
            CurrentDate cd = new CurrentDate();
            cd.createDate();

            if (cd.month > 12 || cd.month < 1) 
                throw invalMonth;
            
            else if (cd.month == 1 || cd.month == 3 || cd.month == 5 || cd.month == 7 || cd.month == 8 || cd.month == 10 || cd.month == 12) {
                if (cd.day > 31 || cd.day < 1) 
                    throw invalDay;
            }

            else if (cd.month == 2) {
                if (cd.year % 4 == 0) {
                    if (cd.day > 29 || cd.day < 1)
                        throw invalDay;
                }
                else {
                    if (cd.day > 28 || cd.day < 1)
                        throw invalDay;
                }
            }

            else {
                if (cd.day > 30 || cd.day < 1)
                    throw invalDay;
            }
        }
        catch(MyExceptions e) {
            System.out.println("Exception thrown: "+e.getCode());
        }
    }
}