package LibrarySystem;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class TrySomeThing {
    public static void main(String[] args) {
        Frame frame = new Frame();
        frame.setSize(400,300);

        frame.setLayout(new GridLayout(2,1));

        Panel p1 = new Panel(new BorderLayout());
        Panel p2 = new Panel(new GridLayout(2,1));
        Panel p3 = new Panel(new BorderLayout());
        Panel p4 = new Panel(new GridLayout(2,2));

        Button btn1 = new Button("21");
        Button btn2 = new Button("32");
        Button btn3 = new Button("43");
        Button btn4 = new Button("54");

        p1.add(btn1,BorderLayout.WEST);
        p1.add(btn2,BorderLayout.EAST);
        p2.add(btn3);
        p2.add(btn4);
        p1.add(p2, BorderLayout.CENTER);

        p3.add(new Button("left"), BorderLayout.WEST);
        p3.add(new Button("right"), BorderLayout.EAST);

        for (int i = 0; i < 4; i++){
            p4.add(new Button("hello" + i));
        }
        p3.add(p4, BorderLayout.CENTER);

        frame.add(p1);
        frame.add(p3);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                System.exit(0);
            }
        });

        frame.setVisible(true);
    }
}