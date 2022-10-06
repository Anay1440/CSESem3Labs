package test;

class firstClass {
    int a;
    firstClass() {
        a = 10;
    }
    int getA() {
        return a;
    }
}

public class test extends firstClass {
    int b;
    public test() {
        b = 20;
    }

    int getSum() {
        int sum =0;
        sum = getA() + b;
        return sum;
    }
}
