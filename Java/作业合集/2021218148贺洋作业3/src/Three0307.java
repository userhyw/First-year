import java.awt.*;
import java.awt.event.*;
import java.awt.geom.AffineTransform;
import java.awt.geom.Rectangle2D;
import java.awt.image.ColorModel;
import java.util.ArrayList;

//此程序为实验，作废
//-------------------------------------------------------------

//只有缩放窗口才会出现图像，而且上一个图像会消失！
//刷新后可以显示出图像来
//需要一个能够动态存储的东西来存点，还可以把存的点都删掉

//发现Java有一个Arrylist数组
//清除缓存的点用里面的clear函数

//使用数组，还没有找到使得下标和点击窗口坐标一起同步变化的方法！！！

public class Three0307 {
    static final int W = 10, H = 10;
    public static void main(String[] args) {

        //ArrayList
        MyFrame myFrame = new MyFrame();
    }

     static class MyFrame extends Frame{
        int m_X = 0, m_Y = 0, m_C = 0;

         MyFrame() {
            setBounds(400, 400, 600, 600);//设置窗大小
            //setResizable(false);
            setVisible(true);//设置窗口显示可见

            addWindowListener(new WindowAdapter() {//设置窗口可被关闭，同时程序截止
                @Override
                public void windowClosing(WindowEvent e) {
                    super.windowClosing(e);
                    System.exit(0);
                }
            });

            addMouseListener(new MouseAdapter() {//再构造函数里完成，直接获取坐标和点击
                @Override
                public void mouseClicked(MouseEvent e) {
                    super.mouseClicked(e);
                     m_X = e.getX();
                     m_Y = e.getY();
                     m_C = e.getButton();
                     MyFrame myFrame = (MyFrame)e.getSource();
                     myFrame.repaint();

//                    System.out.println(m_C);
//                       if(e.getButton() == 1){
//
//                       }



                }
            });


//            //此处是调用的是父类的函数，我们没有重写它
//            MyMouse myMouse = new MyMouse();
//            addMouseListener(myMouse);
        }


//            addMouseListener(new MyMouse());

         @Override
         public void paint(Graphics g) {
            // super.paint(g);

             //这样无法保留之前的点
             switch(m_C){
                 case 1:
                     g.setColor(Color.green);
                     g.fillOval(m_X,m_Y,W,H);
//                     System.out.print("2/n");
                     break;

                 case 3:
                     g.setColor(Color.red);
                     g.fillRect(m_X,m_Y,W,H);
                     break;

                 default:
                     break;
             }

         }

//         class MyMouse extends MouseAdapter{
//
//            @Override
//            public void mouseClicked(MouseEvent e) {
//                super.mouseClicked(e);
//                e.getX();
//                e.getY();
//                System.out.println(e.getClickCount());
//            }
//        }


     }
}
