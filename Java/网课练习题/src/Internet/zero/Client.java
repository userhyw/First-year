package Internet.zero;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;


//客户端
public class Client {
    public static void main(String[] args) {

        Socket s1 = null;
        OutputStream os = null;
            try {
                InetAddress address = InetAddress.getByName("127.0.0.1");//IP
                int port = 9981;//端口
                s1 = new Socket(address, port);//插头

                os = s1.getOutputStream();//写东西--->服务端口
                os.write("Hello World!".getBytes());//预备发送的信息
            } catch (Exception e) {
                e.printStackTrace();
            }
            finally {
                if (s1 != null) {
                    try {
                        s1.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }

    }
}
