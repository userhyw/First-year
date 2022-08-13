package Second1_5;

public class Second05 {
    public static void main(String[] args) {

        int m_A = 0;
        try {
            m_A = Integer.parseInt(args[0]);
            System.out.println("result = " + m_A);
        } catch (NumberFormatException e) {//捕获异常，可以并联多分支，但是要主要，大的问题放在最下面
            System.out.println("Exception!");
        } finally {
            System.out.println("Over");//程序到最后一定会执行的操作
        }
    }
}
