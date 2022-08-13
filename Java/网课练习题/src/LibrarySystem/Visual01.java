package LibrarySystem;

import javax.swing.*;

public class Visual01 {

    public static void main(String[] args) {
        //1.创建一个顶层容器
        JFrame jf = new JFrame();

        //设置大小
        jf.setSize(400, 300);

        //设置位置
        jf.setLocationRelativeTo(null);//居于当前窗口居中，NULL表示默认当前系统

        //设置关闭退出
        //jf.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);(无法关闭窗口)

        //退出应用的程序，仅在应用程序中使用！
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //设置标题
        jf.setTitle("列兵晚上玩阿古朵！");

        //设置不能最大化
        jf.setResizable(false);

        //2.创建中间容器
        JPanel panel = new JPanel();

        //3.创建按钮组件
        JButton btn = new JButton("你爱我吗！");

        //4.将按钮添加到panel中
        panel.add(btn);//把按钮添加到中间容器中

        //5.再将中间容器添加到窗口中---就是分别组合
        jf.setContentPane(panel);

        //6.显示窗口位置（但是关闭此窗口程序不会停止！）
        jf.setVisible(true);//放到最后-----类似上学期做打字游戏的绘制图案，一帧一帧的放出来！
    }
}
