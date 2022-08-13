package Chat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

//客户端
public class Clinet implements ActionListener {

    Socket socket = null;//接收客户端
    OutputStream os = null;//发送
    InputStream is = null;//接收来自客户端的消息
    static boolean flage = false;//判断是否连接上的标志
    static boolean F0 = false;//退出连接的标志

    //创建文本域
    JTextArea T0 = new JTextArea();//IP
    JTextArea T1 = new JTextArea();//消息显示
    JTextArea T2 = new JTextArea();//PORT
    JTextArea T3 = new JTextArea();//消息发送

    //创建滚动条在文本域中
    JScrollPane T_T_T = new JScrollPane(T1);

    //创建标签
    JLabel l0 = new JLabel("Set Client：");
    JLabel l1 = new JLabel("Server IP：");
    JLabel l2 = new JLabel("Server Port：");
    JLabel l3 = new JLabel("Say：");

    //创建按钮
    JButton b0 = new JButton(" Connect ");//启动按钮
    JButton b1 = new JButton(" Say ");//发送消息

    JFrame frame;//为弹窗，提升作用域
    linstner2 linstner2 = null;//线程
    linstner3 linstner3 = null;

    public static void main(String[] args) {
        new Clinet();
    }

    //构造函数实现窗口的创建
    Clinet() {
        //创建Jframe窗口
        frame = new JFrame("客户端");
        //设置窗口出现位置和大小
        frame.setBounds(400, 400, 600, 375);

        //创建容器实现绝对布局
        Container c = frame.getContentPane();
        c.setLayout(null);//实现绝对布局

        //-------------------------------------------------------
        //对文本框，按钮设置大小，进行排版
        l0.setBounds(20, 20, 100, 20);//第一个标签

        l1.setBounds(10, 60, 100, 20);//第二个端口号标签
        T0.setBounds(70, 60, 180, 20);//第一个文本域
        b0.setBounds(475, 50, 100, 30);//第一个按钮

        l2.setBounds(260,60,80,20);//第3个标签
        T3.setBounds(340, 60, 110, 20);//


        T_T_T.setBounds(20, 100, 450, 175);//显示界面的文本框

        l3.setBounds(10, 300, 80, 20);//第3个标签
        T2.setBounds(80, 300, 300, 20);//第3个文本域
        b1.setBounds(400, 295, 80, 30);//第3个按钮

        frame.add(l0);
        frame.add(l1);
        frame.add(T0);
        frame.add(b0);
        frame.add(T_T_T);
        frame.add(l3);
        frame.add(T2);
        frame.add(b1);
        frame.add(l2);
        frame.add(T3);

        //添加监听
        b0.addActionListener(this);
        b1.addActionListener(this);

        //------------------------------------------------------

        //设置不可改变大小
        frame.setResizable(false);

        //设置窗口可视化
        frame.setVisible(true);

        //设置关闭窗口时关闭程序
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object source = e.getSource();

        if (source == b0){
            String s1 = T0.getText();
            String s2 = T3.getText();

            if (!s1.equals("") && !s2.equals("")){//文本框都不为空
                T1.append("Connect to server…" + "\n");
                InetAddress address;//IP
                try {
                    address = InetAddress.getByName(s1);
                    socket = new Socket(address, Integer.parseInt(s2));//匹配连接
                    T1.append("Connect Success!" + "\n");

                    //开启接收消息的线程
                    linstner2 = new linstner2();
                    linstner2.start();

                    //连接上了标记改变
                    flage = true;
                    F0 = true;
                } catch (IOException ex) {
                    ex.printStackTrace();
                }

            }
            else if (s1.equals("")){
                JOptionPane.showMessageDialog(frame,"IP不能为空！");
            }
            else{
                JOptionPane.showMessageDialog(frame, "端口号不能为空！");
            }
        }

        else{
            String s = T2.getText();
            if(flage && !s.equals("")){
                //开启发送消息的线程
                linstner3 = new linstner3();
                linstner3.start();
            }
            else if(!flage){
                JOptionPane.showMessageDialog(frame, "请先建立连接！");
            }
            else {
                JOptionPane.showMessageDialog(frame, "输入内容不能为空！");
            }
        }

    }


    //设置接收消息的线程
    class linstner2 extends Thread
    {
        @Override
        public void run() {
            try {
                while(F0) {
                is = socket.getInputStream();
                BufferedReader reader = new BufferedReader(new InputStreamReader(is));
                    while (true){
                        if (!F0){
                        break;
                    }
                        T1.append("Server: " + reader.readLine() + "\n");
                    }
                    reader.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            finally {
                T1.append("连接断开，可以退出程序！");
                if (os != null){
                    try {
                        os.close();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
                if (is != null){
                    try {
                        is.close();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
                if (socket != null){
                    try {
                        socket.close();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }
        }
    }

    //设置发消息给客户端的线程
    class linstner3 extends Thread
    {
        @Override
        public void run() {

                //先发送再打印
                try {
                    String s = T2.getText();

                    os = socket.getOutputStream();//写消息到客户端
                    os.write((s + "\n").getBytes(StandardCharsets.UTF_8));//字节流传输，在末尾做记号
                    os.flush();

                    //传输过后打印在文本框
                    T1.append("Client: " + s + "\n");
                    //同时清空发送框
                    T2.setText("");

                    //安全和平退出程序
                    if (s.equals("再见")){
                        F0 = false;
                    }

                } catch (IOException e) {
                    e.printStackTrace();
                }
        }
    }

}
