package Internet.two;

import java.net.*;

public class DatagramSocket01 {
    public static void main(String[] args) throws Exception {
        //建立一个Socket
        DatagramSocket datagramSocket = new DatagramSocket();
        //创建一个包
        /*   @NotNull byte[] buf,
        int offset,
        int length,
        InetAddress address,
        int port*/
        String msg = "Hello World!";
        InetAddress address = InetAddress.getByName("localhost");
        int port = 8765;

        DatagramPacket datagramPacket = new DatagramPacket(msg.getBytes(),0,msg.getBytes().length,address,port);

        //发送一个包
        datagramSocket.send(datagramPacket);

        //关闭流
        datagramSocket.close();
    }
}
