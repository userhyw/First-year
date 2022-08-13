package demo;

public class NithNith {
    public static void main(String[] args) {
        //目的：打印99乘法表
        for (int i = 1; i <= 9; i++) {
            for (int i1 = 1; i1 <= i; i1++) {
                System.out.print(i +"*" + i1 + "=" + i * i1 + "\t");
            }
            System.out.printf("\n");
        }
    }
}
