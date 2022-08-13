package Five05;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

//服务端-------传输文件
public class Server {
    public static void main(String[] args) throws Exception {
        //创建服务端口                            //书写端口号
        ServerSocket server = new ServerSocket(9922);

        //接收Socket          //阻塞式接收
        Socket socket = server.accept();

        //获得发送过来的字节数据内容
        InputStream is = socket.getInputStream();

        //创建文件存储
        FileOutputStream fs = new FileOutputStream(new File("r.txt"));

        //将数据写入到文件当中
        byte[] buffer = new byte[1024];
        int len;

        //持续读取
        while ((len = is.read(buffer)) != -1){
            fs.write(buffer,0,len);
        }

        //byte数组转化为String，输出在控制台
        String msg = new String(buffer);
        //用String里面的trim方法，去除数组后面多余的空格
        System.out.println(msg.trim());

        //最后关闭流
        server.close();
        socket.close();
        is.close();
        fs.close();

    }
}
