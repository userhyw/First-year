//判断窗体中点击左键或者右键并在命令行打印例程
import javax.swing.*;
import java.awt.event.*;
public class MyMouseJFrame extends JFrame{
	public MyMouseJFrame(){
		setSize(300,300);
		this.getContentPane().addMouseListener(new mouseProcessor());
		setVisible(true);
		//setLocationRelativeTo(null);//设置窗口相对于指定组件位置
	}

	public class mouseProcessor extends MouseAdapter{
		public void mouseClicked(MouseEvent e){
			String outStr = "";
			if(e.getButton() == e.BUTTON1){//左键
				outStr = "左键";
			}else if(e.getButton() == e.BUTTON3){
				outStr = "右键";
			}else{
				outStr = "中键";
			}
			if(e.getClickCount() == 2){
				outStr = outStr + "双击";
			}else{
				outStr = outStr + "点击";
			}
				System.out.println(outStr);
		}
	}
}