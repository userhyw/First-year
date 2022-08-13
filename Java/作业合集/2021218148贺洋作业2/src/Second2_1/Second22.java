package Second2_1;
import Second2_1.Second02;

import java.util.Random;

public class Second22 {

    public static void main(String[] args) {
        final int M_X = 5;
        Random r = new Random();//随机数生产
        Person[] Per = new Person[M_X];//创建父类对象集合，类似接口集合，指针数组！

        int m_a = -1;
        for (int i = 0; i < 5; i++) {
            m_a = r.nextInt(3);//从0开始计算有三个数！
            switch(m_a){
                case 0:
                    Student St = new Student();
                    St.SetInf();
                    Per[i] = St;
                    break;

                case 1:
                    Faculty Fc = new Faculty();
                    Fc.SetInf();
                    Per[i] = Fc;
                    break;

                case 2:
                    Staff Sf = new Staff();
                    Sf.SetInf();
                    Per[i] = Sf;
                    break;
                default:
                    System.out.println("出现了随机数随机意外！！！");
                    break;
            }
        }

        for (int i = 0; i < 5; i++) {
            System.out.println(Per[i].toString());//输出每个元素的信息
        }
    }
}
