package Five04;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

public class urlTry {
    public static void main(String[] args) throws Exception {
        //创建URL对象
        URL url = new URL("https://cn.bing.com/robots.txt");
        //URLConnection对象
        URLConnection ur = url.openConnection();
        //读取数据
        BufferedReader in = new BufferedReader(new InputStreamReader(ur.getInputStream()));
        //逐行读取
        String msg;
        while ((msg = in.readLine()) != null){
            System.out.println(msg);
        }
    }
}
