import java.util.Scanner;

class Complex {
    double real;
    double imag;

    void assign(double r, double i) {
        real=r;
        imag=i;
    }

    void display() {
        System.out.println(real+" + "+imag+"i");
    }

    Complex add(Complex c1) {
        Complex cAns = new Complex();
        cAns.real = c1.real + real;
        cAns.imag = c1.imag + imag;
        return cAns;
    }

    void subtract(Complex c1, Complex c2) {
        if (c2.real > c1.real) {
            real = c2.real - c1.real;
            imag = c2.imag - c1.imag;
        }
        else {
            real = c1.real - c2.real;
            imag = c1.imag - c2.imag;
        }
    }
}

class script01 {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        Complex c1 = new Complex();
        Complex c2 = new Complex();
        Complex c3 = new Complex();

        System.out.print("Enter the real part of complex number 1 ");
        double r1 = sc.nextDouble();
        System.out.print("Enter the complex part of complex number 1 ");
        double i1 = sc.nextDouble();
        System.out.print("Enter the real part of complex number 2 ");
        double r2 = sc.nextDouble();
        System.out.print("Enter the complex part of complex number 2 ");
        double i2 = sc.nextDouble();
        
        c1.assign(r1,i1);
        c2.assign(r2,i2);

        System.out.println("The first complex number is:");
        c1.display();

        System.out.println("The second complex number is:");
        c2.display();

        c3=c1.add(c2);

        System.out.println("The complex number after addition is:");
        c3.display();

        c3.subtract(c1,c2);

        System.out.println("The complex number after subtraction is:");
        c3.display();
    }
}