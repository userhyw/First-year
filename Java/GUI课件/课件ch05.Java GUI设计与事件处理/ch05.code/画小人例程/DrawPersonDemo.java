//��С������
//https://blog.csdn.net/x541211190/article/details/77414861?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class DrawPersonDemo {

    public static void main(String[] args) {
        // �������
        JFrame jFrame = new JFrame();
        // ��������
        JPanel jpanel = new JPanel() {
            //���кţ���ʡ�ԣ�
            private static final long serialVersionUID = 1L;

            // ��дpaint����
            @Override
            public void paint(Graphics graphics) {
                // �����ȵ��ø����paint����
                super.paint(graphics);
                // �û���Graphics���ڻ���JPanel�ϻ�һ��С��
                graphics.drawOval(100, 70, 30, 30);// ͷ������Բ�Σ�
                graphics.drawRect(105, 100, 20, 30);// ���壨�����Σ�
                graphics.drawLine(105, 100, 75, 120);// ��ۣ���ֱ�ߣ�
                graphics.drawLine(125, 100, 150, 120);// �ұۣ���ֱ�ߣ�
                graphics.drawLine(105, 130, 75, 150);// ���ȣ���ֱ�ߣ�
                graphics.drawLine(125, 130, 150, 150);// ���ȣ���ֱ�ߣ�
            }
        };
        //������С��ͼ��Ļ���Ƕ�뵽�����
        jFrame.add(jpanel);
        // ���û����С����ȣ��߶ȣ���Ĭ�϶�Ϊ0
        jFrame.setSize(300, 300);
        // ������չʾ������true���ÿɼ���Ĭ��Ϊfalse����
        jFrame.setVisible(true);
    }
}