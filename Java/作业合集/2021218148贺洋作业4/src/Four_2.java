import java.math.BigInteger;

import static java.lang.Thread.*;

public class Four_2 {
    public static void main(String[] args) {

        //使用Runnable接口来实现多线程，在实现时内部有函数，或是变量需要获得时，需要对应的实现，不能匿名
        //也就是说，在Runnable实现的函数，你在实现多线程时，创建的Thread是调用不了的。变量也是如此
        MyThread1 myThread1 = new MyThread1();
        MyThread2 myThread2 = new MyThread2();

        Thread t1 = new Thread(myThread1);
        Thread t2 = new Thread(myThread2);

        t1.start();
        t2.start();

        try {
            //等待该线程死亡，即是优先此线程执行
            //因为我们需要此线程执行完，得到最终值
            t1.join();
            t2.join();//join是用于停止主线程的，我们需要主线程在最后行使

        } catch (InterruptedException e) {
            e.printStackTrace();
        }

//        //输出判断，可以先该成少次循环，判断是否有问题
//        System.out.println(myThread1.ShowTime());
//        System.out.println(MyThread2.ShowPer());

         long a1 = myThread1.ShowTime();
         long a2 = MyThread2.ShowPer();

         //输出最后的结果时，需要转换，因为以及溢出了，很明显，输出为负数！
        System.out.println("最终结果为：" + (a1 * a2));

        //如果还是显示为负数，或者不放心是否溢出的情况下，使用大数来进行乘法
        //比如
        BigInteger b1 = new BigInteger(String.valueOf(a1));
        BigInteger b2 = new BigInteger(String.valueOf(a2));
        System.out.println("最终结果为：" + b1.multiply(b2));

    }

    //创建第一个线程，目的实现一万以内素数之和，并返回该值
    private static class MyThread1 implements Runnable{

        // 2是特殊的素数，因为我们的目的是一万以内的素数，直接在初始化这里进行加法！
        private static int a = 2;// = 2

        //作为一个标记，来判断这个数是否有因子
        boolean Flage = true;

        @Override
        public void run()
        {
            //10000明显不是素数，所以这里直接不取得
            //素数除了2都是奇数
            for (int i = 3; i < 1e4; i += 2)
            {
                    //由对称性，可知，只用判断到根号的位置
                //此处判断条件的等号 = 十分重要，不能忘记，省略！
                for (int j = 3; j <= Math.sqrt((double)i); j += 2)
                {
                    if (i % j == 0)
                    {
                        //出现非素数，标记变为false
                        Flage = false;
                        break;//一旦出现因子，立马跳出循环！
                    }
                }

                //对标记进行判断，为真则累加，假则改变Flage的符号，继续循环
                if (Flage)
                {
//                    System.out.println(i);
                    a += i;
                }
                else
                {
                    Flage = true;
                }

            }
        }

        //用于输出素数和 --- a
        public static int ShowTime(){
            return a;
        }
    }

    //创建第二个线程，目的实现一万以内完全数之和，并返回该值
    private static class MyThread2 implements Runnable{

        //用a来记录完全数之和，完全数为真因子之和
        private static int a = 0;
        private static int Perfrct = 0;
        @Override
        public void run()
        {


            //完全数的性质十分特殊，可以采用多种方法实现！
            //此次采用定义，来优化双循环！
            for (int i = 6; i < 1e4; i++)//易知，第一个完全数为 6
            {
                //用于累加真因子
                Perfrct = 0;

                //真因子是不会大于该数本身一半的，
                for (int j = 1; j <= i/2; j++)
                {
                    if (i % j == 0)
                    {
                        //通过双层循环，将所有真因子相加
                        Perfrct += j;
                    }
                }

                //判断真因子之和，是否等于该数
                if (Perfrct == i)
                {
//                    System.out.println(Perfrct);
//                    System.out.println(a);
                    a += Perfrct;
                }

            }

        }

        //用于输出完全数之和！
        public static int ShowPer()
        {
            return  a;
        }
    }

}
