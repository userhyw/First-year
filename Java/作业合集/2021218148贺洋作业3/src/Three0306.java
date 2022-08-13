import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Three0306 {
    public static void main(String[] args) {
         new MyFrame();
    }

    private static class MyFrame extends Frame {

         MyFrame() {
            //设置窗口出现的位置，以及窗口的大小
            setBounds(400, 400, 650, 650);
            setVisible(true);

            //退出窗口的设置
            addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e) {
                    super.windowClosing(e);
                    System.exit(0);
                }
            });
        }

        //先画出一个正方形，再画出剩下的四个圆形
        @Override
        public void paint(Graphics g) {
            super.paint(g);
            g.setColor(Color.BLACK);
            g.drawRect(50,50,550,550);//绘制矩形

            //改变画笔颜色
            g.setColor(Color.red);

            //剩下的四个圆形
            g.fillOval(100,100,150,150);
            g.fillOval(400,400,150,150);
            g.fillOval(400,100,150,150);
            g.fillOval(100,400,150,150);
        }
    }

}

