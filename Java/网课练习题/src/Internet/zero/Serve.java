package Internet.zero;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketAddress;

//服务端
public class Serve {
    public static void main(String[] args) {

        ServerSocket s2 = null;
        Socket s11 = null;
        InputStream im = null;
        ByteArrayOutputStream baos = null;
        while (true) {
            try {
                s2 = new ServerSocket(8806);////接收端口，s1 --- s2建立连接
                s11 = s2.accept();//接收s1
                im = s11.getInputStream();
                baos = new ByteArrayOutputStream();

                byte[] buffer = new byte[1024];
                int lenth;
                while ((lenth = im.read(buffer)) != -1) {
                    baos.write(buffer, 0, lenth);
                }
                System.out.println(baos.toString());
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (s2 != null) {
                    try {
                        s2.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        }

    }
}
