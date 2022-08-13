//»­Ô²ºÍ²Á³ýÀý³Ì

import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class DrawTest extends JFrame { final DrawPanel pnlImg = new DrawPanel();
	public DrawTest() {
		init();
	}
	private void init() {
		setLayout(new GridLayout(2, 1));
		add(pnlImg);
		final JButton btnDraw = new JButton("»­Í¼");
		btnDraw.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				pnlImg.setDrawRadius(200);
				pnlImg.setDrawOval(true);
			}
		});
		final JButton btnClear = new JButton("ÇåÆÁ");
		btnClear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				pnlImg.setDrawOval(false);
			}
		});
		final JPanel pnlButton = new JPanel(new GridLayout(1, 2));
		pnlButton.add(btnDraw);
		pnlButton.add(btnClear);
		add(pnlButton);
		setSize(800, 600);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String [] args) throws Exception {
		javax.swing.SwingUtilities.invokeAndWait(new Runnable() {
			public void run() {
				new DrawTest().setVisible(true);
			}
		});
	}
	
	class DrawPanel extends JPanel {
		boolean flag;
		int radius = 100;
		public void setDrawOval(boolean flag) {
			this.flag = flag;
			repaint();
		}
		public void setDrawRadius(int radius) {
			this.radius = radius;
		}
		public void paintComponent(Graphics g){
			super.paintComponent(g);
			Rectangle rect = getBounds();
			if (flag && rect.width > radius && rect.height > radius) {
				g.drawOval((rect.width - radius) / 2, (rect.height - radius) / 2, radius, radius);
			}
		}
	}
}