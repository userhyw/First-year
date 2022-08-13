package Internet.UdpDemo01;

import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;

public class UdpSend01 {
    public static void main(String[] args) throws Exception {
        //创建一个Socket
        DatagramSocket datagramSocket = new DatagramSocket(8868);

        //从控制台读取数据存在包中，再发过去
        //从控制台读取数据
        InputStreamReader is = new InputStreamReader(System.in);

        //嵌套成其他流
        BufferedReader buffer = new BufferedReader(is);

        //String存储控制台获得输入
        String msg = new String(buffer.readLine());

        //创建一个包                                     //再将String转化为字节流传出
        DatagramPacket datagramPacket = new DatagramPacket(msg.getBytes(),0,msg.getBytes().length,new InetSocketAddress("localhost", 6666));

        //发送包
        datagramSocket.send(datagramPacket);

        //关闭流
        datagramSocket.close();

    }
}
