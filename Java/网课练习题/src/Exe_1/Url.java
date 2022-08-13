package Exe_1;
import java.net.*;
import java.io.*;
public class Url {
public static void main(String[] args) throws Exception{
             //URL数据-> InputStreamReader对象 -> BufferedReader对象 -> 程序处理
             URL hfut = new URL("http://www.baidu.com");
             URLConnection uc = hfut.openConnection();
             BufferedReader in = new BufferedReader(
                     new InputStreamReader(uc.getInputStream()) );
             String inputLine;
             //打印输出HTML
             while ( (inputLine = in.readLine() ) != null )
                 System.out.println(inputLine);
             //关闭缓冲区
             in.close();
             }
}

