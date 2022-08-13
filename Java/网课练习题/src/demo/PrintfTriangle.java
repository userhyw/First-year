package demo;

public class PrintfTriangle {
    public static void main(String[] args) {

        //打印一个五行的三角形

        for (int i = 0; i < 5; i++) {

            for (int i1 = 5; i1 > i; i1--) {
                System.out.print(" ");
            }

            //等号保证了下面两个for循环打印的*号始终相差一个！
            for (int j = 0; j <= i; j++) {
                System.out.print("*");
            }

            for (int k = 0; k < i; k++) {
                System.out.print("*");
            }

            System.out.println();
        }
    }
}
