package ThreadTry;

public class ThreadTest01 {
    public static void main(String[] args) throws InterruptedException {
        Thread t0 = new Thread(new MyRun());
        Thread t1 = new Thread(new MyRun());

        for (int i = 0; i < 100; i++) {
            System.out.println(Thread.currentThread().getName() + "\t\t" + i);

            if (i == 7){
                t1.start();
                t0.start();
              //  Thread.yield();
                Thread.sleep(1);

            }

        }

    }

    private static class MyRun implements Runnable{
        @Override
        public void run() {
            for (int i = 0; i < 10; i++) {
                System.out.println(Thread.currentThread().getName() + "\t" + i);
            }
        }
    }

}
