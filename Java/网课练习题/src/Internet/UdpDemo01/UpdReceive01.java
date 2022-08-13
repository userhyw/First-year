package Internet.UdpDemo01;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UpdReceive01 {
    public static void main(String[] args) throws Exception {
        //创建一个Socket
        DatagramSocket datagramSocket = new DatagramSocket(6666);

        while (true) {
            //创建对应包来接收对应的包
            byte[] buffer = new byte[1024];
            DatagramPacket datagramPacket = new DatagramPacket(buffer, 0, buffer.length);

            //接收包
            datagramSocket.receive(datagramPacket);

            //接收到数据后读出
            byte[] data = datagramPacket.getData();

            //收到的数据为字节流，把字节流转化为字符流输出到控制台
            String msg = new String(data, 0, datagramPacket.getLength());

            //输出到控制台
            System.out.println(msg);
        }
    }
}
