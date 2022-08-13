import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class Test01 {
    public static void main(String[] args) {
        Collection c = new ArrayList<>();

        c.add("张山");
        c.add("李四");
        c.add("王五");
        c.add("赵六");
        c.add("钱七");
        c.add("不知道");

        Iterator iterator = c.iterator();//放回的是一个迭代器

        while (iterator.hasNext()){
            Object obj = iterator.next();//返回的是obj类
            System.out.println(obj);

            if (obj.equals("不知道")){

                //c.remove(obj);//无法做到，会报错

                iterator.remove();//会删除当前匹配到的元素

            }

        }

    }
}
