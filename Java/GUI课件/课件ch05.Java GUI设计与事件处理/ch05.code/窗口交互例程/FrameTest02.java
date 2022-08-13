//自定义窗口事件监听器例程
import java.awt.*;
import java.awt.event.*;

public class FrameTest02{ 		
    public static void main(String[] args){ 
        myFrame frm=new myFrame("窗口交互 !"); 

    } 
}

class myFrame extends Frame {//新建的窗口类 		
	myFrame(String s){
		super(s);  
		this.setSize(600, 400);
		this.setBackground(Color.orange);
		this.addWindowListener(new MyWindowListener());//创建监听器并关联到窗口对象
        	this.setVisible(true); 
    }
	class MyWindowListener implements WindowListener {//定义自己的窗口事件监听器类
		public void windowClosing(WindowEvent e) { 
			System.out.println ("关闭窗口");
			System.exit(0);	}	
		public void windowActivated(WindowEvent e) { }
		public void windowClosed(WindowEvent e) { }
		public void windowDeactivated(WindowEvent e) { }
		public void windowDeiconified(WindowEvent e) { }
		public void windowIconified(WindowEvent e) { }
		public void windowOpened(WindowEvent e) { }
	}
}