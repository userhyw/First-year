import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Three0307_2 {

    //控制画出来的图像的大小的常量
    static final int W = 20, H = 20;

    public static void main(String[] args) {

        new MyFrame();

    }
    //继承Frame
    static class MyFrame extends Frame{


        MyFrame(){

            //设置窗口的大小，出现的位置，以及可见
            setBounds(400,400,600,600);
            setVisible(true);

            //设置窗口可以关闭
            addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e) {
                    super.windowClosing(e);
                    System.exit(0);
                }
            });

            //创建监听系统，获得鼠标点击信息
            addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    super.mouseClicked(e);

                    //关键：
                    //Graphics graphics1 =(Graphics)e.getSource();
                    Graphics graphics = getGraphics();

                    //鼠标单击后进行左右键位的判断
                    if (e.getClickCount() == 1){
                        if (e.getButton() == 1){
                            //Graphics graphics = getGraphics();
                            graphics.setColor(Color.green);
                            graphics.fillOval(e.getX(),e.getY(),W,H);
                        }
                        else if (e.getButton() == 3 ){
                          //  Graphics graphics1 = getGraphics();
                            graphics.setColor(Color.red);
                            graphics.fillRect(e.getX(),e.getY(),W,H);
                        }
                    }
                    else if (e.getClickCount() == 2 ){
                        repaint();//鼠标双击后经行清屏操作
                    }

                }
            });


        }


    }

}


