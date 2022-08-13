import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;
import java.util.Iterator;

public class Three0307_1 {

    //控制画出来的图像的大小的常量
    static final int W = 20, H = 20;

    public static void main(String[] args) {
        new MyFrame();
    }

    static class MyFrame extends Frame {

        ArrayList<MyPoint> myPoints;
        int m_c = 0;

        //        int i = 0;
//        int[] Point = new int[1000];//放五百个点
//        MyPoint[] myPoints = new MyPoint[1000];

        MyFrame() {

            // int[] Point = new int[1000];//放五百个点
            myPoints = new ArrayList<>();

            setBounds(400, 400, 600, 600);
            setVisible(true);

            addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e) {
                    super.windowClosing(e);
                    System.exit(0);
                }
            });

            addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    super.mouseClicked(e);
                    MyFrame myFrame = (MyFrame) e.getSource();//不用new，相当于接管地址

                    //用一个动态的数组不断的接收点击鼠标后的地址
                    //还需要判断鼠标的点击方式
                    m_c = e.getClickCount();

                    myPoints.add(new MyPoint(e.getX(),e.getY(),e.getButton()));

                    //用于刷新
                    myFrame.repaint();
                }
            });
        }

        @Override
        public void paint(Graphics g) {
            super.paint(g);

            //因为数组会动态的更新，所以我们一直遍历它

            if (m_c == 1){
                for (int i = 0; i < myPoints.size(); i++){

                    if (myPoints.get(i).z == 1){
                        g.setColor(Color.green);
                        g.fillOval(myPoints.get(i).x,myPoints.get(i).y,W,H);
                    }
                    else if (myPoints.get(i).z == 3){
                        g.setColor(Color.red);
                        g.fillRect(myPoints.get(i).x,myPoints.get(i).y,W,H);
                    }

                }
            }
            else if (m_c == 2){
                myPoints.clear();
            }

        }


    }

        static class MyPoint {
        //新增变量c，记录鼠标的点击键位
            public int x, y, z;

           MyPoint(int a, int b, int c) {
                x = a;
                y = b;
                z = c;
            }
        }


    }


