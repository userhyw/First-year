package LibrarySystem;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Minstor {
    public static void main(String[] args) {
        new MyFrame();


    }
    static class MyFrame extends Frame{
        public MyFrame(){
//            Frame frame = new Frame();
//            frame.setSize(400,400);
//            frame.setLocationRelativeTo(null);
//            frame.setVisible(true);
            setSize(400,300);
            setLocationRelativeTo(null);
            setVisible(true);


            TextField textField = new TextField();
            textField.setEchoChar('*');

            add(textField);



            MyMinstor myMinstor = new MyMinstor();
            textField.addActionListener(myMinstor);

        }
    }

}

class MyMinstor implements ActionListener{

    @Override
    public void actionPerformed(ActionEvent e) {
        TextField field = (TextField) e.getSource();
        System.out.println(field.getText());
        field.setText("");
    }
}
