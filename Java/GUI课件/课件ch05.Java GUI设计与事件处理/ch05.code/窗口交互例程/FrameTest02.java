//�Զ��崰���¼�����������
import java.awt.*;
import java.awt.event.*;

public class FrameTest02{ 		
    public static void main(String[] args){ 
        myFrame frm=new myFrame("���ڽ��� !"); 

    } 
}

class myFrame extends Frame {//�½��Ĵ����� 		
	myFrame(String s){
		super(s);  
		this.setSize(600, 400);
		this.setBackground(Color.orange);
		this.addWindowListener(new MyWindowListener());//���������������������ڶ���
        	this.setVisible(true); 
    }
	class MyWindowListener implements WindowListener {//�����Լ��Ĵ����¼���������
		public void windowClosing(WindowEvent e) { 
			System.out.println ("�رմ���");
			System.exit(0);	}	
		public void windowActivated(WindowEvent e) { }
		public void windowClosed(WindowEvent e) { }
		public void windowDeactivated(WindowEvent e) { }
		public void windowDeiconified(WindowEvent e) { }
		public void windowIconified(WindowEvent e) { }
		public void windowOpened(WindowEvent e) { }
	}
}