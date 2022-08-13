package testthree.Server;

import java.io.*;
import java.net.*;
import java.util.*;

//记录文本域内输出的信息
class Messager {
    @FunctionalInterface
    //  自己定义的函数式接口
    static interface canPrint {
        public void println(String message);
    }

    public canPrint message;

    public Messager() {
    }

    public Messager(canPrint message) {
        this.message = message;
    }
}

//  处理客户端信息的线程
class ClientHandler implements Runnable {
    Socket server;
    Messager messagerPrint;
    Scanner messagerRecive;

    public ClientHandler(Socket server, Messager messagerPrint) {
        this.server = server;
        this.messagerPrint = messagerPrint;
        try {
            //  获取服务端接收的信息
            messagerRecive = new Scanner(new InputStreamReader(server.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {

        //  在服务端文本域内输出客户端发送的信息
        while (messagerRecive.hasNextLine()) {
            messagerPrint.message.println(messagerRecive.nextLine());
        }

        // 客户端断开连接
        try {
            server.close();
            messagerPrint.message.println("A client disconnected");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

public class Server implements Runnable {

    ServerSocket server;
    Socket socket;
    Messager messagerPrint;

    //  如果不需要服务器自动群发至客户端，此条应被注释
    //  private Messager messagerSend;

    //  存储服务端的输出流
    ArrayList<PrintWriter> clientSenders;

    public Server(ServerSocket server, Messager messagerPrint, Messager messagerSend) {

        this.server = server;
        this.messagerPrint = messagerPrint;

        // 如果不需要服务器自动群发至客户端，此条应被注释
        // this.messagerSend = messagerSend;


        this.clientSenders = new ArrayList<>();
        //  向所有服务端的输出流（所有客户端）写数据（发送数据）
        messagerSend.message = (message) -> {
            for (PrintWriter i : clientSenders)
                i.println(message);
            // 刷新并删除已断开连接的客户端
            clientSenders.removeIf((PrintWriter i) -> {
                return i.checkError();
            });
        };
    }

    @Override
    public void run() {
        try {
            while (!Thread.currentThread().isInterrupted()) {
                // 监听客户端的连接  阻塞式  没有输入就一直卡在这
                // 会一直等待客户端，客户端连接就关闭
                socket = server.accept();

                //  将服务端的所有输出流（所有的客户端）存储到arraylist中
                clientSenders.add(new PrintWriter(socket.getOutputStream()));

               //  开启线程在服务器端文本框输出客户端发送的信息
                new Thread(new ClientHandler(socket, messagerPrint)).start();
                messagerPrint.message.println("A new client connected");
            }
            server.close();
        } catch (SocketException e) {
            // 服务端被关闭
            messagerPrint.message.println("Server closed");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //控制台输出形式
/*
    public static void main(String[] args) {
        final int DEFALUT_PORT = 8888;
        Messager messagerSend = new Messager();
        try {
            new Thread(new Server(new ServerSocket(DEFALUT_PORT), new Messager((message) -> {
                System.out.println(message);
            }), messagerSend)).start();
        } catch (IOException e) {
            e.printStackTrace();
        }
        new Thread() {
            @Override
            public void run() {
                Scanner input = new Scanner(new InputStreamReader(System.in));
                while (input.hasNextLine()) {
                    messagerSend.message.println(input.nextLine());
                }
            }
        }.start();
    }

 */
}

