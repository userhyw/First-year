package ComeOut;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;

//中间商，上帝视角
public class Inventory {
    //初始化对应类的容器
    static ArrayList<Invent> I_T = new ArrayList<>();
    static ArrayList<Work_O> W_O = new ArrayList<>();
    static ArrayList<Work_R> W_R = new ArrayList<>();
    static ArrayList<Work_A> W_A = new ArrayList<>();
    static ArrayList<Work_D> W_D = new ArrayList<>();
    static ArrayList<Shipping> ship = new ArrayList<>();
    static ArrayList<Errors> errors = new ArrayList<>();

    public static void main(String[] args) throws Exception{

        ReadInvent("Inventory.txt");
        ReadTran("Transactions.txt");
        m_add();//先处理---A事件
        m_get();//处理---R事件
        m_send();//处理---O事件
        m_delete();//处理---D事件
        ArrInvent();//处理---排序
        combine();//处理---合并
        WriteShipping("Shipping.txt");
        WriteErrors("Errors.txt");
        WriteNewInventory("NewInventory.txt");

    }

    //读取仓库数据
    static void ReadInvent(String FileName) throws Exception {
        //嵌套字符流读取
        BufferedReader buffer1 = new BufferedReader(new FileReader(FileName));

        //String数组逐行读取
        String s = null;
        while ((s = buffer1.readLine()) != null)
        {
            String []read = s.split("\t");//以TAB为分割线
            I_T.add(new Invent(read[0], Integer.parseInt(read[1]), read[2], read[3]));//将数据读取到对应抽象类中
        }

        buffer1.close();
    }

    //读取对货物多操作的数据
    static void ReadTran(String FileName) throws Exception {
        //读取数据，但是要分多种情况读取
        BufferedReader buffer2 = new BufferedReader(new FileReader(FileName));

        //依旧用String数组逐行读取
        String s = null;
        while ((s = buffer2.readLine()) != null)
        {
            String []read = s.split("\t");

            switch (read[0])
            {
                case "O":
                    W_O.add(new Work_O(read[0], read[1], Integer.parseInt(read[2]), read[3]));
                    break;
                case "R":
                    W_R.add(new Work_R(read[0], read[1], Integer.parseInt(read[2])));
                    break;
                case "A":
                    W_A.add(new Work_A(read[0],read[1], read[2], read[3]));
                    break;
                case "D":
                    W_D.add(new Work_D(read[0], read[1]));
                    break;
            }
        }

        //最后关闭文件流
        buffer2.close();

    }

    //注意上面的全局变量，所以可以直接在函数中使用
    //细分为很多个小块

    //1.在发生的事件中，默认新增是最优先级的-----A
    static void m_add()
    {
        //向仓库中增加一个新货物，数量为0；
        for (int i = 0; i < W_A.size(); i++)
        {
            I_T.add(new Invent(W_A.get(i).Item_number, 0, W_A.get(i).Supplier, W_A.get(i).Description));
        }
    }

    //2.其次是处理到货的事件
    static void m_get()
    {
        for (int i = 0; i < W_R.size(); i++) {
            for (int j = 0; j < I_T.size(); j++) {
                if (W_R.get(i).Item_number.equals(I_T.get(j).Item_number))//找出货物，直接加上去
                {
                    I_T.get(j).Quantity += W_R.get(i).Quantity;
                }
            }
        }
    }

    //3.准备工作完成后处理发货订单
    static void m_send()
    {
        //对O事件的发货数量经行排序
        Collections.sort(W_O, new Comparator<Work_O>() {
            @Override
            public int compare(Work_O o1, Work_O o2) {
                if (o1.Quantity > o2.Quantity){
                    return 1;
                }
                return -1;
            }
        });

        //遍历发货单，检查仓库是否能正常发货
        for (int i = 0; i < W_O.size(); i++) {
            for (int j = 0; j < I_T.size(); j++) {
                //首先找到需要发送的货物
                if ( W_O.get(i).Item_number.equals(I_T.get(j).Item_number)){
                    //再判断是否能正常发货
                    //1.能正常发货
                    if (W_O.get(i).Quantity < I_T.get(j).Quantity){
                        //货物发出，仓库货物数量减少
                        I_T.get(j).Quantity -= W_O.get(i).Quantity;
                        //同时也是一条成功的发货记录，存储到Shoiping中
                        ship.add(new Shipping(W_O.get(i).Custom, W_O.get(i).Item_number, W_O.get(i).Quantity));
                    }
                    else{
                        //这是库存小于要求发货单的记录
                        errors.add(new Errors(W_O.get(i).Custom, W_O.get(i).Item_number, W_O.get(i).Quantity));
                    }
                }
            }
        }
    }

    //4.完成发货后经行删除操作
    static void m_delete()
    {
        //因为需要再遍历的同时删除，使用使用迭代器来遍历
        Iterator iterator = I_T.iterator();
        while (iterator.hasNext()){
            Invent Delete = (Invent) iterator.next();
            for (int i = 0; i < W_D.size(); i++) {
                if (Delete.Item_number.equals(W_D.get(i).Item_number)){//删除货物找到
                    if (Delete.Quantity == 0){//满足条件可以删除
                        iterator.remove();
                        break;
                    }
                    else{//不满足删除条件，但是又要删除，则记录到错误文件中
                        errors.add(new Errors("0", Delete.Item_number, Delete.Quantity));
                        break;
                    }
                }
            }
        }

    }

    //5.整理仓库，对仓库里的货物依据编号经行排序
    static void ArrInvent()
    {
        //使用排序器经行排序
        Collections.sort(I_T, new Comparator<Invent>() {
            @Override
            public int compare(Invent o1, Invent o2) {
                int a = Integer.parseInt(o1.Item_number);
                int b = Integer.parseInt(o2.Item_number);

                if (a > b) return 1;
                else if (a < b) return -1;
                return 0;
            }
        });
    }

    //6.合并可以合并的发货单子
    static void combine()
    {
        //在发货单中寻找可以合并的订单
        for (int i = 0; i < ship.size() - 1; i++) {
            for (int j = i + 1; j < ship.size(); j++) {
                //查找是否出现可以合并的订单
                if (ship.get(i).Item_number.equals(ship.get(j).Item_number) && ship.get(i).Custom.equals(ship.get(j).Custom)){
                    //若出现一个买家，买同一个东西的记录，则合并
                    ship.get(i).Quantity += ship.get(j).Quantity;
                    //合并后删除多余记录
                    ship.remove(j);
                    //同时注意处理，下标，保证遍历完全
                    i--;
                    break;
                }
            }
        }

    }

    //7.把需要写入文件的数据，写到文件中去
    static void WriteShipping(String FileNmae) throws IOException {
        //嵌套字符流读取
        BufferedWriter buffer1 = new BufferedWriter(new FileWriter(FileNmae));
        //遍历ship，读取数据
        for (int i = 0; i < ship.size(); i++) {
            buffer1.write(ship.get(i).toString());
            buffer1.newLine();
        }
        //使用完要关闭流，不然可能出现错误，比如，文件为空
        buffer1.close();
//        buffer1.flush();
    }
    static void WriteErrors(String FileNmae) throws IOException {
        //嵌套字符流读取
        BufferedWriter buffer1 = new BufferedWriter(new FileWriter(FileNmae));
        //遍历ship，读取数据
        for (int i = 0; i < errors.size(); i++) {
            buffer1.write(errors.get(i).toString());
            buffer1.newLine();
        }
        buffer1.close();
    }
    static void WriteNewInventory(String FileNmae) throws IOException {
        //嵌套字符流读取
        BufferedWriter buffer1 = new BufferedWriter(new FileWriter(FileNmae));
        //遍历ship，读取数据
        for (int i = 0; i < I_T.size(); i++) {
            buffer1.write(I_T.get(i).toString());
            buffer1.newLine();
        }
        buffer1.close();
    }

}

//抽象出两个类，作为信息储存的单位
//作为大仓库！！！
class Invent
{
    //构造函数，读文件一一存入
    Invent(String Item_number, int Quantity, String Supplier, String Description)
    {
        this.Item_number = Item_number;
        this.Quantity = Quantity;
        this.Supplier = Supplier;
        this.Description = Description;
    }

    public String toString()
    {
        return this.Item_number + "\t" + this.Quantity + "\t" + this.Supplier + "\t" + this.Description;
    }

     String Item_number;//货物编号
     int Quantity;//货物数量
     String Supplier;//供应商编号
     String Description;//货物描述

}

//O---发货订单
//R---到货记录
//A---新增货物
//D---删除货物
//相同部分作为父类属性---类型和货物编号总是要有的
class Transact
{
    Transact(){};//--------查过写报告里面-----------
    Transact(String Type, String Item_number)//构造函数实现类型和货物编号的初始化
    {
        this.Type = Type;
        this.Item_number = Item_number;
    }
     String Type;
     String Item_number;
}

//发货订单抽象类
class Work_O extends Transact
{
    Work_O(String Type, String Item_number, int Quantity, String Custom)
    {
        super(Type, Item_number);
        this.Quantity = Quantity;
        this.Custom = Custom;
    }

     int Quantity;//订单数量
     String Custom;//客户编号
}

//到货记录抽象类
class Work_R extends Transact
{
    Work_R(String Type, String Item_number, int Quantity)
    {
        super(Type, Item_number);
        this.Quantity = Quantity;
    }

     int Quantity;
}

//新增货物抽象类
class Work_A extends Transact
{
    Work_A(String Type, String Item_number, String Supplier, String Description)
    {
        super(Type, Item_number);
        this.Supplier = Supplier;
        this.Description = Description;
    }

     String Supplier;//供应商编号
     String Description;//货物描述
}

//删除货物抽象类
class Work_D extends Transact
{
    Work_D(String Type, String Item_number)
    {
        super(Type, Item_number);
    }
}

//客户信息发送抽象类
class Shipping
{

    Shipping(String Custom, String Item_number, int Quantity)
    {
        this.Custom = Custom;
        this.Item_number = Item_number;
        this.Quantity = Quantity;
    }

    //用于将重复的货单，经行相加
    public void add(int Quantity)
    {
        this.Quantity += Quantity;
    }

    //获取当前的数据，存入到客户信息发送文件中
    public String toString()
    {
        return this.Custom + "\t" + this.Item_number + "\t" + this.Quantity;
    }

     String Custom;
     String Item_number;
     int Quantity;
}

//错误信息抽象类
class Errors
{
    //包含未发送的发货记录，和库存量大于的删除记录

    Errors(String Custom, String Item_number, int Quantity)
    {
        this.Custom = Custom;
        this.Item_number = Item_number;
        this.Quantity = Quantity;
    }

    //获取当前的数据，存入到错误信息文件中
    public String toString()
    {
        return this.Custom + "\t" + this.Item_number + "\t" + this.Quantity;
    }

     String Custom;
     String Item_number;
     int Quantity;

}
