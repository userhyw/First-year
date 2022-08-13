package testthree.Server;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;

class ServerPanel extends JPanel {

    //  新建标签
    JLabel labelA;
    JLabel labelC;
    //  新建文本框
    JTextField textFieldA;
    JTextField textFieldC;
    //  新建按钮
    JButton buttonA;
    JButton buttonC;
    //  新建文本域
    JTextArea textAreaB;

    Thread threadServer;
    ServerSocket server;

    Messager messagerSend;
    Messager messagerPrint;

    //  设置面板
    public ServerPanel() {
        //  定义一个Lambda表达式来完成文本域内消息显示
        messagerPrint = new Messager((message) -> {
            textAreaB.append(message + "\n");
        });
        //
        messagerSend = new Messager();

        // 面板第一部分
        labelA = new JLabel("Port: ");
        textFieldA = new JTextField(40);
        textFieldA.setBorder(BorderFactory.createLineBorder(Color.gray));
        buttonA = new JButton("Start");

        //  点击了"Connect"按钮
        buttonA.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                try {
                    // 关闭原服务，开启一个新服务
                    if (threadServer != null) {
                        server.close();
                        threadServer.interrupt();
                        while (threadServer.isAlive())
                            ;
                    }
                    int port =Integer.valueOf(textFieldA.getText());
                    messagerPrint.message.println("Server starting" + " at port " + port);
                    //  创建服务，服务端打开端口(端口号由文本框输入)
                    server = new ServerSocket(port);
                    //读取客户端发送过来的数据的线程
                    threadServer = new Thread(new Server(server, messagerPrint, messagerSend));
                    threadServer.start();
                    messagerPrint.message.println("Server started" + " at port " + port);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        //  创建一个从左到右显示其组件的 Box
        Box lineAContent = Box.createHorizontalBox();
        //  将标签，文本框，按钮 添加到Box中
        lineAContent.add(labelA);
        //  同时控制左右间的间距
        lineAContent.add(Box.createHorizontalStrut(10));
        lineAContent.add(textFieldA);
        lineAContent.add(Box.createHorizontalStrut(10));
        lineAContent.add(buttonA);

        //  创建一个从上到下显示其组件的 Box。
        Box lineABorder = Box.createVerticalBox();
        //  控制上下的间距
        lineABorder.add(Box.createVerticalStrut(5));
        //  将上面的box组件放入
        lineABorder.add(lineAContent);
        lineABorder.add(Box.createVerticalStrut(5));

        //  创建一个从左到右显示其组件的 Box
        Box lineA = Box.createHorizontalBox();
        //  添加边框标题
        lineABorder.setBorder(BorderFactory.createTitledBorder("服务器设置"));
        //  同时控制左右间的间距
        lineA.add(Box.createHorizontalStrut(10));
        //  将上下排列好的box容器放入边框内
        lineA.add(lineABorder);
        lineA.add(Box.createHorizontalStrut(10));

        // 面板第三部分
        textAreaB = new JTextArea(10, 40);
        //  文本域设置为不可编辑
        textAreaB.setEditable(false);
        //  设置带有滚动条的面板并将文本域加入
        JScrollPane scrollPaneB = new JScrollPane(textAreaB);
        //  创建面板线边框
        scrollPaneB.setBorder(BorderFactory.createLineBorder(Color.gray));

        //  创建一个从左到右显示其组件的 Box
        Box lineB = Box.createHorizontalBox();
        //  控制左右间距
        lineB.add(Box.createHorizontalStrut(10));
        //  加入线边框
        lineB.add(scrollPaneB);
        lineB.add(Box.createHorizontalStrut(10));

        // 面板第三部分
        labelC = new JLabel("Say: ");
        textFieldC = new JTextField(40);
        textFieldC.setBorder(BorderFactory.createLineBorder(Color.gray));
        buttonC = new JButton( "Say");
        //  点击了"Say"按钮
        buttonC.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (threadServer == null || messagerSend.message == null)
                    return;
                String say = textFieldC.getText();
                // 不允许打印空内容
                if (say.isEmpty())
                    return;
                //  服务端发送给客户端的数据
                messagerSend.message.println("Server: " + say);
                //  服务端文本域输出的数据
                messagerPrint.message.println("Server: " + say);
                // 清空输入框
                textFieldC.setText("");
            }
        });
        //  创建一个从左到右显示其组件的 Box
        Box lineC = Box.createHorizontalBox();
        //  控制左右的间距
        lineC.add(Box.createHorizontalStrut(10));
        //  添加组件
        lineC.add(labelC);
        lineC.add(Box.createHorizontalStrut(10));
        lineC.add(textFieldC);
        lineC.add(Box.createHorizontalStrut(10));
        lineC.add(buttonC);
        lineC.add(Box.createHorizontalStrut(10));

        //  创建一个从上到下显示其组件的 Box。
        Box mainBox = Box.createVerticalBox();
        //  控制上下的间距
        mainBox.add(Box.createVerticalStrut(10));
        //  分别加入之前的三个box组件构成一个box组件
        mainBox.add(lineA);
        //  控制上下间距
        mainBox.add(Box.createVerticalStrut(10));
        mainBox.add(lineB);
        mainBox.add(Box.createVerticalStrut(10));
        mainBox.add(lineC);
        mainBox.add(Box.createVerticalStrut(10));

        //  将最终拼装好的组件加入panel内
        add(mainBox);
    }
}

public class ServerGUI implements Runnable {

    JFrame MyJFrame;
    ServerPanel panel;

    @Override
    public void run() {
        MyJFrame = new JFrame("服务器");
        panel = new ServerPanel();
        //  窗口不可调整
        MyJFrame.setResizable(false);
        //  把panel设置成为frame的内容面板
        MyJFrame.setContentPane(panel);
        //  调整此窗口的大小，以适合其子组件的首选大小和布局
        MyJFrame.pack();
        //  将窗口置于屏幕的中央
        MyJFrame.setLocationRelativeTo(null);
        //	窗口显示
        MyJFrame.setVisible(true);
        //	关闭窗口则退出程序
        MyJFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        Thread threadGUI = new Thread(new ServerGUI());
        threadGUI.start();
    }
}
