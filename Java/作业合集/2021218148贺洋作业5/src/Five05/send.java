package Five05;

import java.io.FileInputStream;

import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;

//客户端-------------传输文件
public class send {
    public static void main(String[] args) throws Exception {
        //创建一个Socket对象
        Socket socket = new Socket(InetAddress.getByName("127.0.0.1"),9922);

        //创建流，写东西过去
        OutputStream os = socket.getOutputStream();

        //创建读取文件的预备读取文件                         //改变文件类型，可以传导不同的文件
        FileInputStream fops = new FileInputStream("HelloWorld.txt");

        //读取文件
        byte[] buffer = new byte[1024];
        int len;
        while ((len = fops.read(buffer)) != -1){
            //写到服务端口去
            os.write(buffer, 0, len);
        }//至此文件便能传输过去

        //关闭所有打开的流
        socket.close();
        os.close();
        fops.close();
    }

}
