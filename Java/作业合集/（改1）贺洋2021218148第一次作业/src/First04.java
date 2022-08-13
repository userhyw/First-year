import java.util.Scanner;
public class First04 {

    public static void main(String[] args){
        double PI = 3.1415927;
        // 已知圆球体积为4/3πr3，试编写一个程序，输入圆球半径，经过计算输出圆球的体积
        System.out.println("请输入圆球的半径，我们将会计算出该圆球的体积：");

        double m_r, m_V;

        Scanner sc = new Scanner(System.in);
        m_r = sc.nextInt();

        m_V = 4/3. * PI * m_r * m_r * m_r;
        System.out.println("该圆球的体积为：" + String.format("%.3f", m_V));
    }
}
