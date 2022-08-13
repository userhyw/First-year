package demo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class AySort {
    public static void main(String[] args) {
        //利用arraylist数组进行排序
        //1.整数
        ArrayList<Integer> ay = new ArrayList<>();
        ay.add(8);
        ay.add(2);
        ay.add(4);
        ay.add(5);
        ay.add(3);
        ay.add(6);
        ay.add(7);
        ay.add(8);

        //利用集合的排序工具，默认排序
        Collections.sort(ay);
        //使用for循环输出
        for (int i = 0; i < ay.size(); i++) {
            System.out.print(ay.get(i));
        }

        System.out.println();
        //自我选择式排序
        Collections.sort(ay, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (o1 < o2)  return 1;
                else if (o1 > o2) return -1;
                return 0;
            }
        });

        //使用for循环输出
        for (int i = 0; i < ay.size(); i++) {
            System.out.print(ay.get(i));
        }
    }
}
