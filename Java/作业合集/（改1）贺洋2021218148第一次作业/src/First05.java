import jdk.swing.interop.SwingInterOpUtils;

import java.math.*;

public class First05 {
    public static void main(String[] args) {

        int i = 1, j = 0;
        BigInteger s = BigInteger.valueOf(j);
        BigInteger n = BigInteger.valueOf(i);

        do{
            n = n.multiply(BigInteger.valueOf(i));//到达阶乘的目的
            s = s.add(n);//累加
            i++;

        }while(i <= 100);//注意等号
        System.out.println(s);

    }
}
