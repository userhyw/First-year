package LibrarySystem;


import javax.swing.*;
import java.awt.*;

//网格布局
public class GridLayOut01 {
    public static void main(String[] args) {

        JFrame jf = new JFrame();

        jf.setSize(400,300);//大小

        jf.setTitle("网格布局实现");//标题

        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//关闭

        jf.setLocationRelativeTo(null);//居中

        //创建网格布局
        //多个默认构造函数，参数不同
        GridLayout layout = new GridLayout(3, 3, 10, 10);

        //设置间隙
        //注意：可以直接加到上面的代码中
//        layout.setHgap(10);//水平
//        layout.setVgap(10);//垂直

        JPanel panel = new JPanel(layout);//第二容器

//        JButton btn1 = new JButton("按钮1");
//        JButton btn2 = new JButton("按钮2");
//        JButton btn3 = new JButton("按钮3");
//        JButton btn4 = new JButton("按钮4");
//        JButton btn5 = new JButton("按钮5");
//        JButton btn6 = new JButton("按钮6");
//
//        panel.add(btn1);//添加组件
//        panel.add(btn2);
//        panel.add(btn3);
//        panel.add(btn4);
//        panel.add(btn5);
//        panel.add(btn6);

        //以上两个步骤可以使用for循环来减少代代码！！!
        for(int i = 0; i < 9; i++){
            panel.add(new JButton("按钮"  + (i + 1)));
        }


        jf.setContentPane(panel);//添加到窗口

        jf.setVisible(true);//显示

    }
}
