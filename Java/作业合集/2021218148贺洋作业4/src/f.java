import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.util.*;

public class f {
    public static void main(String[] args) throws IOException {

        //�ڵ�ǰĿ¼�´����ļ�
        FileWriter f1 = new FileWriter("Now.txt");
        BufferedWriter b1 = new BufferedWriter(f1);
        FileWriter f3 = new FileWriter("Then.txt");
        BufferedWriter b3 = new BufferedWriter(f3);

        //�ڵ�ǰĿ¼���ҵ��ļ����������������
        FileReader f2 = new FileReader("Now.txt");
        BufferedReader b2 = new BufferedReader(f2);

        //��������
        MyFrame myFrame = new MyFrame();
        myFrame.setTitle("����ϵͳ���������");

        //����������ʾ��ǩ
        Label m_Name = new Label("������������",1);
        Label m_Number = new Label("������ѧ�ţ�",1);
        Label m_Score = new Label("������ɼ���",1);


        //�����ı���������
        TextField c_Name = new TextField();
        TextField c_Number = new TextField();
        TextField c_Score = new TextField();

        //������������Ʋ���
        Panel m_Up = new Panel(new GridLayout(3,2,20,20));

        //���������С�Ű�
        m_Up.setBounds(10,30,300,150);

        //�����������ı��ͱ�ǩ
        m_Up.add(m_Name);
        m_Up.add(c_Name);
        m_Up.add(m_Number);
        m_Up.add(c_Number);
        m_Up.add(m_Score);
        m_Up.add(c_Score);

        //��Ӱ�ť����
        //��ӳ�ʼ���ݵ��ı��еİ�ť
        Button m_Sure = new Button("������ݵ��ı�");
        m_Sure.setBounds(10,190,150,50);//����ȷ�����밴ť��λ�úʹ�С
        //����������ݵ��ı��еİ�ť
        Button m_Sure2 = new Button("��Ӻ������ı�");
        m_Sure2.setBounds(200,190,150,50);//����ȷ�����밴ť��λ�úʹ�С

        //��Ӹ��������ײ������
        //���÷Ŷ���������
        Container container = myFrame.getContentPane();

        //���þ��Բ���
        //��Ӹ����
        container.setLayout(null);
        container.add(m_Up);
        container.add(m_Sure);
        container.add(m_Sure2);

        //�����ı��������ʾ
        TextArea m_Down = new TextArea();
        m_Down.setBounds(10,250,380,140);
        container.add(m_Down);//���ı�����ӵ�������



        //�Ե�һ����ť���м���
        m_Sure.addActionListener(new ActionListener() {

            boolean Imprison = true;//�ж��Ƿ��пտ�
            String Name, Number, Score;//���ڴ��浽�ļ���
            int m_People = 0;//���ڼ�¼��ǰ����

            //��Ӽ������԰�ť�¼����м���
            @Override
            public void actionPerformed(ActionEvent e) {

                Imprison = true;
                CheckWdf(c_Name,"����");
                CheckWdf(c_Number,"ѧ��");
                CheckWdf(c_Score,"����");

                Name = c_Name.getText();
                Number = c_Number.getText();
                Score = c_Score.getText();

                if (Imprison)
                {
                    try {
//                        System.out.println("------------------");
                        b1.write(Name + " ");//����ӿո���Ϊ�˶��ļ���ʱ��÷ֿ��ó���
                        b1.write(Number + " ");
                        b1.write(Score);
                        b1.newLine();//�Ƶ���һ��
                        b1.flush();//��ջ�����������д���ı���
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }

                    m_People++;
                    m_Down.setText("�Ѿ�������" + m_People + "��ѧ������Ϣ�ˣ�");
                    c_Name.setText("");
                    c_Number.setText("");
                    c_Score.setText("");

                }

            }

            //�����Ƿ�ÿһ������������Ϣ
            private void CheckWdf(TextField TF, String tf)
            {
                if (!Imprison) return;

                String m_c = TF.getText();
                if (m_c.length() == 0)
                {
                    JOptionPane.showMessageDialog(myFrame,tf + "��û������");
                    Imprison = false;
                }
            }
        });


        ArrayList<Students> Stu = new ArrayList<>();
        //�����ڶ�����ť�����ļ����ж�ȡ����
       m_Sure2.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
                String m_read =null;
               while (true) {
                   try {
                       m_read = b2.readLine();
                       if (m_read == null){//����ǿվ��˳�
                           break;
                       }
                   } catch (IOException ex) {
                       ex.printStackTrace();
                   }

                   String []s =m_read.split(" ");//�ո�����С�ζ�
                   Stu.add(new Students(s[0], s[1],Double.parseDouble(s[2])));//���Ԫ�ص�������
               }

               if (Stu.size() > 1) {//��֤��Խ�磬���˷�����
                   //����, ��Arraylist�����򹤾�
                   Collections.sort(Stu, new Comparator<Students>() {
                       @Override
                       public int compare(Students o1, Students o2) {
                            if (o2.Score - o1.Score > 0)//doubleֵ���ز��ˣ�����һ���ok
                            {
                                return 1;
                            }
                            else
                            {
                                return -1;
                            }

                       }
                   });

                   //�����������ƽ���֣�˳����ӵ��ļ���
                   Iterator iterator = Stu.iterator();
                   double AllScore = 0;
                   while (iterator.hasNext()) {//��������
                       Students wdf = (Students) iterator.next();
                       AllScore += wdf.Score;//�ۼӷ���
                       try {
                           b3.write(wdf.Name + " ");
                           b3.write(wdf.Number + " ");
                           b3.write("" + wdf.Score);//�ܼ򵥵�ת�������������������͵Ķ��ᱻת��ΪString
                           b3.newLine();
                           b3.flush();
                       } catch (IOException ex) {
                           ex.printStackTrace();
                       }

                   }

                   //����������֮��д����߷ֺ���ͷ֣�ƽ����
                   AllScore /= Stu.size();
                   try {
                       b3.write("��߷�Ϊ��" + Stu.get(0).Score);//�����ֱ���þͿ�����
                       b3.newLine();
                       b3.write("��ͷ�Ϊ��" + Stu.get(Stu.size() - 1).Score);
                       b3.newLine();
                       b3.write("ƽ����Ϊ��" + AllScore);
                       b3.flush();
                   } catch (IOException ex) {
                       ex.printStackTrace();
                   }

                   //���õ�����ʾ
                   JOptionPane.showMessageDialog(myFrame, "��ϲ�����ν����ˣ�����д����");
               }
               else{
                   //���õ�����ʾ
                   JOptionPane.showMessageDialog(myFrame,"����ң���Ӻ��ٹ�����");
               }
           }
       });

       //���ô��ڼ�����
       myFrame.addWindowListener(new WindowAdapter() {
           @Override
           public void windowClosing(WindowEvent e) {
               super.windowClosing(e);
               try {//���رմ����¼�����ʱ
                   f1.close();
                   b1.close();
                   f2.close();
                   b2.close();
                   f3.close();
                   b3.close();//�ر�������
               } catch (IOException ex) {
                   ex.printStackTrace();
               }
           }
       });


    }



    //����һ���̳�Frame������
    private static class MyFrame extends JFrame{

        //�ڹ��캯������ʵ�֣������Ĺ���
        MyFrame()
        {
            //���ô��ڳ��ֵ�λ�ã����ô��ڵĴ�С
            setBounds(400,400,410,400);

            //���ô��ڵĿ��ӻ�
            setVisible(true);

            //���ô��ڿɹر�
            setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);


        }

    }

    //����һ��ѧ���࣬��ȡ�ļ�����ʱ�����б��棬��������
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
