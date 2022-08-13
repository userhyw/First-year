package Internet.one;

import java.io.FileInputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

//客户端
public class Client2 {
    public static void main(String[] args) throws Exception {
       //创建一个Socket连接
        Socket socket = new Socket(InetAddress.getByName("127.0.0.1"), 9981);
        //创建一个输出流
        OutputStream os = socket.getOutputStream();

        //读取文件                                //这部分读取时，会阻塞线程，也就是无法输出信息
        FileInputStream fs = new FileInputStream("van.jpg");

        //将文件通过输出流传到服务端
        byte[] buffer = new byte[1024];
        int lenth;
        while ((lenth = fs.read(buffer)) != -1){
            //文件内容存在buffer中，用输出流传送过去
            os.write(buffer, 0, lenth);
        }//至此文件便传输过去了

        //关闭流
        socket.close();
        os.close();
        fs.close();
    }
}
