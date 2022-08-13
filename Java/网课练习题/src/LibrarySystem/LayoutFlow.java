package LibrarySystem;
import javax.swing.*;
import java.awt.*;

//测试流式布局
public class LayoutFlow {
    public static void main(String[] args) {

        //1.创建顶层容器
        JFrame jf = new JFrame();

        //设置长宽
        jf.setSize(400,300);

        //设置关闭
        jf.setDefaultCloseOperation(3);//jf.EXIT_ON_CLOSE

        //设置位置
        jf.setLocationRelativeTo(null);

        //设置标题
        jf.setTitle("实验流式布局！");

        //注意：这个在添加了JPanel后会被覆盖，可以使用JPanel自带的背景颜色设置类
//        //设置窗口颜色
//        jf.setBackground(new Color(212, 55, 26));

        //2.创建中间容器(设置布局)                  //设置布局，左、右、中等等！
        JPanel panel = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 20));

        //3.创建按钮
        JButton btn1 = new JButton("按钮1");
        JButton btn2 = new JButton("按钮2");
        JButton btn3 = new JButton("按钮3");
        JButton btn4 = new JButton("按钮4");
        JButton btn5 = new JButton("按钮5");

        //4.组装
        panel.add(btn1);
        panel.add(btn2);
        panel.add(btn3);
        panel.add(btn4);
        panel.add(btn5);

        //5.将中间容器装到窗口中
        jf.setContentPane(panel);

        panel.setBackground(Color.GRAY);

        //6.显示窗口
        jf.setVisible(true);
    }
}
