package testthree.Client;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;

class ClientPanel extends JPanel {

    //  新建标签
    JLabel labelHost; 
    JLabel labelPort;
    JLabel labelC;
    //  新建文本框
    JTextField textFieldHost;
    JTextField textFieldPort;
    JTextField textFieldC;
    //  新建按钮
    JButton buttonA;
    JButton buttonC;
    //  新建文本域
    JTextArea textAreaB;
    //  读服务端数据的线程
    Thread threadClient;
    Socket client;
    Messager messagerSend;
    Messager messagerPrint;


    public ClientPanel() {
        //获取文本域内的信息
        messagerPrint = new Messager((message) -> {
            textAreaB.append(message + "\n");
        });
        messagerSend = new Messager();

        //  面板第一部分
        labelHost = new JLabel("Server IP: ");
        textFieldHost = new JTextField(15);
        textFieldHost.setBorder(BorderFactory.createLineBorder(Color.gray));
        labelPort = new JLabel("Server Port: ");
        textFieldPort = new JTextField(15);
        textFieldPort.setBorder(BorderFactory.createLineBorder(Color.gray));
        buttonA = new JButton("Connect");

        //  点击了"Connect"按钮
        buttonA.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                try {
                    // 关闭原服务，开启一个新服务
                    if (threadClient != null) {
                        client.close();
                        threadClient.interrupt();
                        while (threadClient.isAlive());
                    }
                    //  IP地址
                    String host =textFieldHost.getText();
                    //  端口号
                    int port = Integer.valueOf(textFieldPort.getText());
                    //  正在连接中
                    messagerPrint.message.println("Connecting" + " to server " + host + " at port " + port);
                    //  获取端口号和IP地址
                    client = new Socket(host, port);
                    //  读取服务端发送过来的数据
                    threadClient = new Thread(new Client(client, messagerPrint, messagerSend));
                    threadClient.start();
                    //  连接成功
                    messagerPrint.message.println("Connected" + " to server " + host + " at port " + port);
                } catch (ConnectException e) {
                    messagerPrint.message.println("Connection refused!!!");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        //  创建一个从左到右显示其组件的 Box
        Box lineAContent = Box.createHorizontalBox();
        //  将标签，文本框，按钮 添加到Box中
        lineAContent.add(labelHost);
        //  同时控制左右间的间距
        lineAContent.add(Box.createHorizontalStrut(10));
        lineAContent.add(textFieldHost);
        lineAContent.add(Box.createHorizontalStrut(10));
        lineAContent.add(labelPort);
        lineAContent.add(Box.createHorizontalStrut(10));
        lineAContent.add(textFieldPort);
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
        lineABorder.setBorder(BorderFactory.createTitledBorder("客户机设置"));
        //  同时控制左右间的间距
        lineA.add(Box.createHorizontalStrut(10));
        //  将上下排列好的box容器放入边框内
        lineA.add(lineABorder);
        lineA.add(Box.createHorizontalStrut(10));

        //  面板第二部分
        textAreaB = new JTextArea(10, 30);
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

        //  面板第三行
        labelC = new JLabel("Say: ");
        textFieldC = new JTextField(30);
        textFieldC.setBorder(BorderFactory.createLineBorder(Color.gray));
        buttonC = new JButton("Say");
        //  点击了"Say"按钮
        buttonC.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (threadClient == null || messagerSend.message == null)
                    return;
                String say = textFieldC.getText();
                //  不允许打印空内容
                if (say.isEmpty())
                    return;
                //  记录客户端发送给服务端的数据
                messagerSend.message.println("Client: " + say);
                //  客户端文本域输出
                messagerPrint.message.println("Client: " + say);
                //  清空输入框
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

public class ClientGUI implements Runnable {

    JFrame MyJFrame;
    ClientPanel panel;

    @Override
    public void run() {
        MyJFrame = new JFrame("客户端");
        panel = new ClientPanel();
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
        Thread threadGUI = new Thread(new ClientGUI());
        threadGUI.start();
    }
}
