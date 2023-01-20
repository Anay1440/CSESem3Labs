class SharedObject {
    private int value = 0;
    boolean available = false;

    public synchronized void get() {
        while(!available) {
            try {
                wait();
            }
            catch(InterruptedException e) {
                System.out.println("Interrupted..");
            }
        }
        System.out.println("Consumed: " + value);
        available = false;
        notify();
    }

    public synchronized void put() {
        while(available) {
            try {
                wait();
            }
            catch(InterruptedException e) {
                System.out.println("Interrupted..");
            }
        }
        value++;
        System.out.println("Produced: " + value);
        available = true;
        notify();
    }
}

class Producer implements Runnable {
    SharedObject sharedObject;
    Thread t;
    Producer (SharedObject obj) {
        sharedObject = obj;
        t = new Thread(this, "Producer");
        t.start();
    }
    public void run() {
        for (int i=0;i<7;i++) {
            sharedObject.put();
        }
    }
}

class Consumer implements Runnable {
    SharedObject sharedObject;
    Thread t;
    Consumer (SharedObject obj) {
        sharedObject = obj;
        t = new Thread(this, "Consumer");
        t.start();
    }
    public void run() {
        for (int i=0;i<20;i++) {
            sharedObject.get();
        }
    }
}

class Q3ProducerConsumer {
    public static void main(String[] args) {
        SharedObject sharedObject = new SharedObject();

        Producer producer = new Producer(sharedObject);
        Consumer consumer = new Consumer(sharedObject);

        try {
            producer.t.join();
            consumer.t.join();
            System.out.println("Producer and Consumer threads terminated.");
        }
        catch(InterruptedException e) {
            System.out.println("Interrupted..");
        }
    }
}

