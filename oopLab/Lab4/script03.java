import java.util.Scanner;

class BankAccount {
    String name;
    int accno;
    String type;
    int bal;
    static int rate;

    BankAccount() {
        name="";
        accno=0;
        type="";
        bal=0;
        rate=0;
    }

    BankAccount(String nam,int accnum, String acctype,int balance,int roi) {
        name=nam;
        accno=accnum;
        type=acctype;
        bal=balance;
        rate=roi;
    }

    void deposit(int val) {
        bal += val;
        System.out.println(val+" was deposited into your account. The current balance is: "+bal);
    }

    void withdraw(int val) {
        if (bal-val < 0) {
            System.out.println("Error. The amount asked to be withdrawn is more than available balance. The current balance is: "+bal);
        }
        else {
            bal-=val;
            System.out.println(val+" was withdrawn from your account. The current balance is: "+bal);
        }
    }

    void display() {
        System.out.println("Name of account holder: "+name+"\nAccount number: "+accno+"\nType of account: "+type+"\nBalance: "+bal);
    }

    static void roiDisplay() {
        System.out.println("The rate of interest is: "+rate);
    }
}

class script03 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        BankAccount acc2 = new BankAccount();
        System.out.println("The default constructor has been called. The details of the account are: ");
        acc2.display();

        System.out.print("Enter your name ");
        String nam = sc.next();
        System.out.print("Enter account number ");
        int accnum = sc.nextInt();
        System.out.print("Enter bank account type ");
        String acctype = sc.next();
        System.out.print("Current balance in the account ");
        int balance = sc.nextInt();
        System.out.print("Enter the ROI offered by the bank ");
        int roi = sc.nextInt();

        BankAccount acc = new BankAccount(nam,accnum,acctype,balance,roi);
        int input = 0;
        int temp;
        do {
            System.out.println("1. Deposit, 2. Withdraw, 3.Display account details, 4. Display ROI, -1. Exit");
            input=sc.nextInt();
            if(input == 1) {
                System.out.print("Enter the amount of money you want to deposit ");
                temp = sc.nextInt();
                acc.deposit(temp);
            }
            else if(input == 2) {
                System.out.print("Enter the amount of money you want to withdraw ");
                temp = sc.nextInt();
                acc.withdraw(temp);
            }
            else if(input == 3) {
                acc.display();
            }
            else if(input == 4) {
                acc.roiDisplay();
            }
            else {
                input=-1;
            }
        } while(input != -1);

    }
}