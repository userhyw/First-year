//show GUI Frame
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class myFrame extends Frame {//�½��Ĵ����� 		
	myFrame(String s){
	    super(s);  
      	this.setSize(600, 400);
      	this.setBackground(Color.blue);
		this.addWindowListener( new WindowAdapter()	{
				public void windowClosing(WindowEvent we) {
					System.out.println ("�رմ���");
					System.exit(0);
				}
			}
		);	
        this.setVisible(true); 
    }
}
public class FrameTest01{ 		
    public static void main(String[] args){ 
        myFrame frm=new myFrame("���ڽ��� !"); 
    } 
}