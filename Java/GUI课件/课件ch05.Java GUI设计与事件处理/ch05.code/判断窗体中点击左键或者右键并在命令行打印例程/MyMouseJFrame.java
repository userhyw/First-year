//�жϴ����е����������Ҽ����������д�ӡ����
import javax.swing.*;
import java.awt.event.*;
public class MyMouseJFrame extends JFrame{
	public MyMouseJFrame(){
		setSize(300,300);
		this.getContentPane().addMouseListener(new mouseProcessor());
		setVisible(true);
		//setLocationRelativeTo(null);//���ô��������ָ�����λ��
	}

	public class mouseProcessor extends MouseAdapter{
		public void mouseClicked(MouseEvent e){
			String outStr = "";
			if(e.getButton() == e.BUTTON1){//���
				outStr = "���";
			}else if(e.getButton() == e.BUTTON3){
				outStr = "�Ҽ�";
			}else{
				outStr = "�м�";
			}
			if(e.getClickCount() == 2){
				outStr = outStr + "˫��";
			}else{
				outStr = outStr + "���";
			}
				System.out.println(outStr);
		}
	}
}