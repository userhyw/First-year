package Internet.two;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class DatagramSocket02 {
    public static void main(String[] args) throws Exception {
        //建立一个Socket
        DatagramSocket datagramSocket = new DatagramSocket(6666);

        //创建包来接收包
        //把接收到的包里的东西存起来
        byte[] buffer = new byte[1024];
        DatagramPacket datagramPacket = new DatagramPacket(buffer,0,buffer.length);

        //接收包
        datagramSocket.receive(datagramPacket);

        //读取包的内容
        System.out.println(datagramPacket.getAddress().getHostAddress());
        System.out.println(new String(datagramPacket.getData(),0,datagramPacket.getLength()));

        datagramSocket.close();
    }
}
