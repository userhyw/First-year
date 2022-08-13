package Exe_1;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class equs {
    public static void main (String[] args)throws Exception {
        stu q = new stu();
        stu w = new stu();
        q.a = 10;
        w.a = 10;

        System.out.println(q == w);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String s = null;

        s = reader.readLine();
        System.out.println(s);
    }
    static public class stu
    {
        int a;
    }
}
