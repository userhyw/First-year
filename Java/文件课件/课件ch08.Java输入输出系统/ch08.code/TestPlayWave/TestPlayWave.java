/*��������һֱ���ţ�ֱ�����ֽ�����
 *AudioSystem����Ϊ������Ƶϵͳ��Դ����ڵ㡣
 *AudioInputStream��Ƶ�������Ǿ���ָ����Ƶ��ʽ�ͳ��ȵ��������������Բ���֡�������ֽڱ�ʾ��
 *Clip�ӿڣ�������Ƶ����
 */
import java.io.*;
import javax.sound.sampled.*;
public class TestPlayWave {
	public static void main(String[] args) {
		PlayWave pw=new PlayWave("./SUSAN˵.wav");
		pw.start();
	}
}
//������������
class PlayWave extends Thread {
	private String filename;
	public PlayWave(String wavfile) {
		filename = wavfile;
	}

	public void run() {
		File soundFile = new File(filename);
		AudioInputStream audioInputStream = null;
		try {
			audioInputStream = AudioSystem.getAudioInputStream(soundFile);
		} catch (Exception e1) {
			e1.printStackTrace();
			return;
		}
		AudioFormat format = audioInputStream.getFormat();
		SourceDataLine auline = null;
		DataLine.Info info = new DataLine.Info(SourceDataLine.class, format);

		try {
			auline = (SourceDataLine) AudioSystem.getLine(info);
			auline.open(format);
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}

		auline.start();
		int nBytesRead = 0;
		byte[] abData = new byte[512];

		try {
			while (nBytesRead != -1) {
				nBytesRead = audioInputStream.read(abData, 0, abData.length);
				if (nBytesRead >= 0)
					auline.write(abData, 0, nBytesRead);
			}
		} catch (IOException e) {
			e.printStackTrace();
			return;
		} finally {
			auline.drain();
			auline.close();
		}
	}	
}