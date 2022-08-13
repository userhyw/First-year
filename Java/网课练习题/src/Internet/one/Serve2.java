package Internet.one;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

//服务端
public class Serve2 {
    public static void main(String[] args) throws Exception {
        //创建一个服务端
        ServerSocket serverSocket = new ServerSocket(9981);
        //监听客户端的输入
        Socket socket = serverSocket.accept();
        //创建一个输入流
        InputStream is = socket.getInputStream();

        //写入文件到文件，首先要有一个对应的文件来存储       //这部分写入时会阻塞线程，也就是无法获得信息
        FileOutputStream fops = new FileOutputStream(new File("vangao.jpg"));
        //同理，开始读文件，度到文件中
        byte[] buffer = new byte[1024];
        int lenth;
        while ((lenth = is.read(buffer)) != -1){
            //将读到buffer里面的内容写到文件中
            fops.write(buffer, 0, lenth);
        }

        //最后关闭流
        serverSocket.close();
        socket.close();
        is.close();
        fops.close();

    }
}
