/*这个类仅能一直播放，直到音乐结束。
 *AudioSystem类作为采样音频系统资源的入口点。
 *AudioInputStream音频输入流是具有指定音频格式和长度的输入流，长度以采样帧而不是字节表示。
 *Clip接口，加载音频数据
 */
import java.io.*;
import javax.sound.sampled.*;
public class TestPlayWave {
	public static void main(String[] args) {
		PlayWave pw=new PlayWave("./SUSAN说.wav");
		pw.start();
	}
}
//播放声音的类
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