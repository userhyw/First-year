
import javax.swing.*;
import javax.swing.plaf.OptionPaneUI;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.util.*;

public class Four_5 {
    public static void main(String[] args) throws IOException {

        //再当前目录下创建文件
        FileWriter f1 = new FileWriter("Now.txt");
        BufferedWriter b1 = new BufferedWriter(f1);
        FileWriter f3 = new FileWriter("Then.txt");
        BufferedWriter b3 = new BufferedWriter(f3);

        //在当前目录下找到文件，排序后输入其中
        FileReader f2 = new FileReader("Now.txt");
        BufferedReader b2 = new BufferedReader(f2);

        //创建窗口
        MyFrame myFrame = new MyFrame();
        myFrame.setTitle("坐牢系统，真的坐牢");

        //创建输入提示标签
        Label m_Name = new Label("请输入姓名：",1);
        Label m_Number = new Label("请输入学号：",1);
        Label m_Score = new Label("请输入成绩：",1);


        //创建文本输入区域
        TextField c_Name = new TextField();
        TextField c_Number = new TextField();
        TextField c_Score = new TextField();

        //设置组件，控制布局
        Panel m_Up = new Panel(new GridLayout(3,2,20,20));

        //设置组件大小排版
        m_Up.setBounds(10,30,300,150);

        //向组件中添加文本和标签
        m_Up.add(m_Name);
        m_Up.add(c_Name);
        m_Up.add(m_Number);
        m_Up.add(c_Number);
        m_Up.add(m_Score);
        m_Up.add(c_Score);

        //添加按钮功能
        //添加初始数据到文本中的按钮
        Button m_Sure = new Button("添加数据到文本");
        m_Sure.setBounds(10,190,150,50);//设置确认输入按钮的位置和大小
        //添加排序数据到文本中的按钮
        Button m_Sure2 = new Button("添加后排序到文本");
        m_Sure2.setBounds(200,190,150,50);//设置确认输入按钮的位置和大小

        //添加各组件到最底层面板中
        //设置放东西的容器
        Container container = myFrame.getContentPane();

        //设置绝对布局
        //添加各组件
        container.setLayout(null);
        container.add(m_Up);
        container.add(m_Sure);
        container.add(m_Sure2);

        //设置文本域，添加提示
        TextArea m_Down = new TextArea();
        m_Down.setBounds(10,250,380,140);
        container.add(m_Down);//将文本域添加到窗口中



        //对第一个按钮经行监听
        m_Sure.addActionListener(new ActionListener() {

            boolean Imprison = true;//判断是否有空框
            String Name, Number, Score;//用于储存到文件中
            int m_People = 0;//用于记录当前人数

            //添加监听器对按钮事件经行监听
            @Override
            public void actionPerformed(ActionEvent e) {

                Imprison = true;
                CheckWdf(c_Name,"姓名");
                CheckWdf(c_Number,"学号");
                CheckWdf(c_Score,"分数");

                Name = c_Name.getText();
                Number = c_Number.getText();
                Score = c_Score.getText();

                if (Imprison)
                {
                    try {
//                        System.out.println("------------------");
                        b1.write(Name + " ");//后面加空格是为了读文件的时候好分块拿出来
                        b1.write(Number + " ");
                        b1.write(Score);
                        b1.newLine();//移到下一行
                        b1.flush();//清空缓冲区，立刻写入文本中
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }

                    m_People++;
                    m_Down.setText("已经输入了" + m_People + "个学生的信息了！");
                    c_Name.setText("");
                    c_Number.setText("");
                    c_Score.setText("");

                }

            }

            //检验是否每一个框都输入了信息
            private void CheckWdf(TextField TF, String tf)
            {
                if (!Imprison) return;

                String m_c = TF.getText();
                if (m_c.length() == 0)
                {
                    JOptionPane.showMessageDialog(myFrame,tf + "还没有填完");
                    Imprison = false;
                }
            }
        });


        ArrayList<Students> Stu = new ArrayList<>();
        //监听第二个按钮，对文件经行读取排序
       m_Sure2.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
                String m_read =null;
               while (true) {
                   try {
                       m_read = b2.readLine();
                       if (m_read == null){//如果是空就退出
                           break;
                       }
                   } catch (IOException ex) {
                       ex.printStackTrace();
                   }

                   String []s =m_read.split(" ");//空格来分小段读
                   Stu.add(new Students(s[0], s[1],Double.parseDouble(s[2])));//添加元素到数组中
               }

               if (Stu.size() > 1) {//保证不越界，不浪费排序
                   //排序, 用Arraylist的排序工具
                   Collections.sort(Stu, new Comparator<Students>() {
                       @Override
                       public int compare(Students o1, Students o2) {
                            if (o2.Score - o1.Score > 0)//double值返回不了，巧妙一点就ok
                            {
                                return 1;
                            }
                            else
                            {
                                return -1;
                            }

                       }
                   });

                   //数组遍历计算平均分，顺便添加到文件中
                   Iterator iterator = Stu.iterator();
                   double AllScore = 0;
                   while (iterator.hasNext()) {//迭代遍历
                       Students wdf = (Students) iterator.next();
                       AllScore += wdf.Score;//累加分数
                       try {
                           b3.write(wdf.Name + " ");
                           b3.write(wdf.Number + " ");
                           b3.write("" + wdf.Score);//很简单的转换方法，后面所有类型的都会被转化为String
                           b3.newLine();
                           b3.flush();
                       } catch (IOException ex) {
                           ex.printStackTrace();
                       }

                   }

                   //迭代遍历完之后写入最高分贺最低分，平均分
                   AllScore /= Stu.size();
                   try {
                       b3.write("最高分为：" + Stu.get(0).Score);//排序后直接拿就可以了
                       b3.newLine();
                       b3.write("最低分为：" + Stu.get(Stu.size() - 1).Score);
                       b3.newLine();
                       b3.write("平均分为：" + AllScore);
                       b3.flush();
                   } catch (IOException ex) {
                       ex.printStackTrace();
                   }

                   //设置弹窗提示
                   JOptionPane.showMessageDialog(myFrame, "恭喜你坐牢结束了！终于写完了");
               }
               else{
                   //设置弹窗提示
                   JOptionPane.showMessageDialog(myFrame,"别搞我，添加好再过来！");
               }
           }
       });

       //设置窗口监听器
       myFrame.addWindowListener(new WindowAdapter() {
           @Override
           public void windowClosing(WindowEvent e) {
               super.windowClosing(e);
               try {//当关闭窗口事件发生时
                   f1.close();
                   b1.close();
                   f2.close();
                   b2.close();
                   f3.close();
                   b3.close();//关闭所有流
               } catch (IOException ex) {
                   ex.printStackTrace();
               }
           }
       });


    }



    //创建一个继承Frame的子类
    private static class MyFrame extends JFrame{

        //在构造函数中先实现，基本的功能
        MyFrame()
        {
            //设置窗口出现的位置，设置窗口的大小
            setBounds(400,400,410,400);

            //设置窗口的可视化
            setVisible(true);

            //设置窗口可关闭
            setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);


        }

    }

    //创建一个学生类，读取文件内容时，经行保存，方便排序
    private static class Students{
         public String Name;
         public String Number;
         public double Score;

        Students(String a, String b, double c)
        {
            Name = a;
            Number = b;
            Score = c;
        }
    }

}
