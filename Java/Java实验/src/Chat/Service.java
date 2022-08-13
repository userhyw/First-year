package Chat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

//服务端
public class Service implements ActionListener {

    ServerSocket server = null;//服务端
    Socket socket = null;//接收客户端
    OutputStream os = null;//发送
    InputStream is = null;//接收来自客户端的消息

    static boolean flage = false;//是否连接上的标志
    static boolean F0 = true;//用于退出程序

    //创建文本域
    JTextArea T0 = new JTextArea();//端口号输入
    JTextArea T1 = new JTextArea();//信息显示
    JTextArea T2 = new JTextArea();//消息发送

    //创建滚动条在文本域当中
    JScrollPane T_T_T = new JScrollPane(T1);

    //创建按钮
    JButton b0 = new JButton(" Start ");//启动按钮
    JButton b1 = new JButton(" Say ");//发送消息

    //创建标签
    JLabel l0 = new JLabel("Set Service：");
    JLabel l1 = new JLabel("Port：");
    JLabel l2 = new JLabel("Say：");

    JFrame frame;//为弹窗，提升作用域


    public static void main(String[] args) {
        new Service();
    }


    //构造函数实现窗口的创建
    Service() {
        //创建Jframe窗口
        frame = new JFrame("服务器");
        //设置窗口出现位置和大小
        frame.setBounds(400, 400, 500, 375);

        //创建容器实现绝对布局
        Container c = frame.getContentPane();
        c.setLayout(null);//实现绝对布局

        //-------------------------------------------------------
        //对文本框，按钮设置大小，进行排版
        l0.setBounds(20, 20, 100, 20);//第一个标签

        l1.setBounds(20, 60, 100, 20);//第二个端口号标签
        T0.setBounds(100, 60, 250, 20);//第一个文本域
        b0.setBounds(400, 50, 80, 30);//第一个按钮

        T_T_T.setBounds(20, 100, 450, 175);//显示界面的文本框

        l2.setBounds(20, 300, 80, 20);//第3个标签
        T2.setBounds(80, 300, 300, 20);//第3个文本域
        b1.setBounds(400, 295, 80, 30);//第3个按钮

        frame.add(l0);
        frame.add(l1);
        frame.add(T0);
        frame.add(b0);
        frame.add(T_T_T);
        frame.add(l2);
        frame.add(T2);
        frame.add(b1);

        //添加监听
        b0.addActionListener(this);
        b1.addActionListener(this);

        //------------------------------------------------------

        //设置不可改变大小
        frame.setResizable(false);

        //设置窗口可视化
        frame.setVisible(true);

        //设置窗口可以关闭
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }


    @Override   //监听按钮事件，即为发消息给对方
    public void actionPerformed(ActionEvent e) {

        Object source = e.getSource();
        if (source == b0) {
            String s1;
            s1 = T0.getText();//接收端口号
            if (!s1.equals("")) {
                try {
                    server = new ServerSocket(Integer.parseInt(s1));
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
                linsner1 linsner1 = new linsner1(s1);
                linsner1.start();
            }
            else{
                //弹窗提示输入端口号
                JOptionPane.showMessageDialog(frame, "请先输入端口号！");
            }
        }
        else {
            //点击Say之后，创建发消息的线程
            String s = T2.getText();
            if (!s.equals("") && flage) {
                linsner2 linsner2 = new linsner2();
                linsner2.start();
            }
            else if (!flage){
                JOptionPane.showMessageDialog(frame, "请先建立连接！");
            }
            else{
                JOptionPane.showMessageDialog(frame,"输入内容不能为空！");
            }

        }
    }


        class linsner1 extends Thread
        {
            String s1;
            linsner1(String s1)
            {
                this.s1 = s1;
            }
            @Override
            public void run() {
                T1.append("Server starting…" + "\n");//打印等待连接中
                try {
                        socket = server.accept();//接收Socket
                        T1.append("Connect Success!" + "\n");//打印连接成功
                        //连接成功打印提示在文本框
                        flage = true;
                        F0 = true;
                        linsner3 linsner3 = new linsner3();//接收消息的线程创立
                        linsner3.start();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                finally {
                    String s = T2.getText();
                    if (s.equals("确认退出")){
                        T1.append("连接断开，可以退出程序！");
                        if (is != null){
                            try {
                                is.close();
                            } catch (IOException ex) {
                                System.out.println("is problem");
                            }
                        }
                        if (os != null){
                            try {
                                os.close();
                            } catch (IOException ex) {
                                System.out.println("os problem");
                            }
                        }
                        if (socket != null){
                            try {
                                socket.close();
                            } catch (IOException ex) {
                                System.out.println("socket problem");
                            }
                        }
                        if (server != null){
                            try {
                                server.close();
                            } catch (IOException ex) {
                                System.out.println("server problem");
                            }
                        }
                    }

                }

            }
        }

        //对输出信息进行多线程输出，并且打印在文本框中
        class linsner2 extends Thread {

            @Override
            public void run() {
                String s = T2.getText();
                //先发送再打印
                try {
                        os = socket.getOutputStream();//写消息到客户端
                        os.write((s + "\n").getBytes(StandardCharsets.UTF_8));//字节流传输
                        os.flush();
                        //传输过后打印在文本框
                        T1.append("Server: " + s + "\n");
                        //同时清空发送框
                        T2.setText("");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        //对来自客户端的消息进行打印
        class linsner3 extends Thread {
            @Override
            public void run() {
                try {
                    while (F0){//初始为死循环一直读取
                        is = socket.getInputStream();//等待信息传入
                        BufferedReader reader = new BufferedReader(new InputStreamReader(is));
                        String tem = reader.readLine();//逐行读取
                        while(tem != null) {
                            if (tem.equals("再见")){//读取到特定语句退出循环
                                F0 = false;//改变参量。退出循环
                                T1.append("客户端已断开连接！");//打印提示语句
                                break;
                            }
                            if (F0)
                            {
                                T1.append("Client: " + tem + "\n");//打印接收的信息
                                tem = reader.readLine();//持续读取
                            }
                        }reader.close();//流用完就关闭，防止重复new
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                    }
                }
            }
}
