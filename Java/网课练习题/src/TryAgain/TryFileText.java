package TryAgain;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class TryFileText {
    public static void main(String[] args) {
      new MyFrame();

    }
    static class MyFrame extends Frame{
        MyFrame(){
            setSize(400,300);
            setLocationRelativeTo(null);
            setVisible(true);

            //----------------------------------------------------------
//            addWindowListener(new WindowAdapter() {
//                @Override
//                public void windowClosing(WindowEvent e) {
//                    super.windowClosing(e);
//                    System.exit(0);
//                }
//            });
            //----------------------------------------------------------------

            addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e) {
                    super.windowClosing(e);
                    System.exit(0);
                }
            });


            TextField field = new TextField();
            field.setText("牛哇！");


//            field.setEchoChar('2');
            add(field);

            MyMin myMin = new MyMin();
            field.addActionListener(myMin);

        }
    }
}
class MyMin implements ActionListener{

    @Override
    public void actionPerformed(ActionEvent e) {
        TextField field = (TextField) e.getSource();
        System.out.println(e.getSource());
        System.out.println(field.getText());
        System.out.println("从事件中读取和变成从文件中读取的区别！");
        field.setText("");
    }
}
