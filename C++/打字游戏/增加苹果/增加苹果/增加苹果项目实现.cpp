/*��дһ����ϰ������Ϸ��ʹ��ͼ�ν��棬��ϰ����
��Ϸ����Ϊ��
1. ��Ϸ��ʼʱ������Ϸ����������������ɸ���ĸ������ʼ��ʱ��
2. �û����ݳ��ֵ���ĸ��ͨ�����������Ӧ���ַ���
3. ����û�������ַ������������ַ��ڳ��ֵ���ĸ�У������ĸ��ʧ��
����Ϊ�û��ĵ÷֡�
4. ��ĸ����Ϸ������Ϸ���������Ϸ����ĵ׶��ƶ���ֱ���û���������
ȷ���ַ�������ĸ�ƶ�����Ϸ����ĵ׶˺���ĸ��ʧ��
5. ��Ϸʱ�䵽��ͳ���û�����ȷ�ʣ������þ���Ϸ�ĵ÷֡�*/


#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <easyx.h> //X Y ͼƬ����ȹ���
#include <mmsystem.h>
#include <ctime>
#pragma comment(lib,"winmm.lib")  //���ֲ��Ź���

#define N 1000 // ����ʱ�����
#define MAX 20 //ƻ�������Ŀ���


//��Ҫȫ��ʹ�õı���
using namespace std;
int TIME, Flage, Score;
float Accuracy, Number1 = 0, Number2;
int Speed = 2;//��ʼ�������ٶ�

//Ԫ��
//����
//����
//����
//����

//�ز�
IMAGE backimg;//����ͼƬ
IMAGE Apple[2];//ƻ��������ͼƬ

//���һ���࣬��ʵ��ƻ��������ʵ�֣�
class AppleMany
{
public:
	//���캯����ʼ����ĸ
	AppleMany()
	{
		m_X = rand() % 14 * 50 + 100;//�γɲ��Ⱦ�;
		m_Y = rand() % 5 *( -50) - 50;//���Ϸ��γɸ߶Ȳ�
		m_ch = rand() % 26 + 'A';
	}
	int m_X;
	int m_Y;
	char m_ch;
};

//�����߽磬�ٴγ�ʼ���������ǻ��к�ĳ�ʼ��
void ManyApple(AppleMany &a)
{
	a.m_X = rand() % 14 * 50 + 100;//�γɲ��Ⱦ�;
	a.m_Y = rand() % 5 * (-50) - 50;//���Ϸ��γɸ߶Ȳ�
	a.m_ch = rand() % 26 + 'A';
}

//����ı亯��
void DateUpdate(AppleMany &a)
{
	a.m_Y += Speed;
}


//һ����Ϸ����������������ٴγ�ʼ��������
//��Ϊͼ���ϵ�����޷��ڴ��ٴγ�ʼ��������
void BecomeStart()
{
	closegraph();
	Flage = 0;
	//Score = 0;

}


//��Ϸ����������������������������ٴμ�Ϊ0������
void PrintfScore(AppleMany *howmany)
{
	if (Number1 != 0) Accuracy = Number2 / Number1;
	cout << "�������ˣ�" << Number2 << "����ƻ����" << endl;
	cout << "���ĵ÷�Ϊ �� " << Score << endl;
	cout << "������ȷ��Ϊ " << 100 * Accuracy << "%" << endl;
	cout << "�ɵ�Ư��������" << endl;
	system("pause");
	Score = 0;
	Number1 = 0;
	Number2 = 0;
	for (int i = 0; i < MAX; i++) {//֮ǰд��N��������Խ���ˣ�����
		howmany[i].m_Y = rand() % 5 * (-50) - 50;
	}
}


//ȷ���˳�������
void SureExit()
{
	int Exit = 0;
	while (1) {
		cout << "���� -1 ȷ���˳���" << endl;
		cin >> Exit;
		system("pause");
		if (Exit == -1) {
			system("cls");
			return;
		}
	}


}


//���� ��ʱ�չ� start
void DrawPictures(AppleMany &a)
{
	//��ʼ�������;
	//BeginBatchDraw();
	//�������->����һ֡һ֡������ʾ����;

	//���Ⱥ�ã���Ȼ�ᱻ�ڵ���
	//putimage(0, 0, &backimg);//�Ӵ���0.0�������ͼƬ

	putimage(a.m_X - 18, a.m_Y - 18, &Apple[1], SRCPAINT);
	putimage(a.m_X - 18, a.m_Y - 18, &Apple[0], SRCAND);

	outtextxy(a.m_X, a.m_Y, a.m_ch);

	//EndBatchDraw();//�����������
}

//����ָ���֪ʶ������
//DWORD (WINAPI* PTHREAD_START_ROUTINE)(
//	LPVOID lpThreadParameter
//	);

//CreateThread //����ָ��
DWORD WINAPI Boom(LPVOID lpThreadParameter)
{
	mciSendString(L"open ��ը.mp3", 0, 0, 0);//���٣������ö��̵߳ķ�ʽȥ���
	mciSendString(L"play ��ը.mp3 wait", 0, 0, 0);
	mciSendString(L"close ��ը.mp3", 0, 0, 0);
	return 0;
}


//���� + ��������
void PlayGame(AppleMany *a)
{
	char key;			//���ܰ������ַ�����
	if (_kbhit())		 //�Ƿ��а����Ķ���
	{
		key = _getch();   //�����û��İ���
		if (key == '1') {
			//Speed = 2;
			
			//���ٶȵ���
			Speed = 1;

			//mci media contorl interface
			mciSendString(L"close IOU02.mp3", 0, 0, 0);
			mciSendString(L"close IOU03.mp3", 0, 0, 0);
			mciSendString(L"open IOU01.mp3", 0, 0, 0);
			mciSendString(L"play IOU01.mp3", 0, 0, 0);
		}
		else if (key == '2') {
			Speed = 4;
			mciSendString(L"close IOU01.mp3", 0, 0, 0);
			mciSendString(L"close IOU03.mp3", 0, 0, 0);
			mciSendString(L"open IOU02.mp3", 0, 0, 0);
			mciSendString(L"play IOU02.mp3", 0, 0, 0);
		}
		else if (key == '3') {
			Speed = 6;
			mciSendString(L"close IOU01.mp3", 0, 0, 0);
			mciSendString(L"close IOU02.mp3", 0, 0, 0);
			mciSendString(L"open IOU03.mp3", 0, 0, 0);
			mciSendString(L"play IOU03.mp3", 0, 0, 0);

		}
		else if ( key == ' ') {
			mciSendString(L"close IOU03.mp3", 0, 0, 0);
			mciSendString(L"close IOU02.mp3", 0, 0, 0);
			mciSendString(L"close IOU01.mp3", 0, 0, 0);

			//��һ���ո���ͣ�Ĳ�����
			while (_getch() != ' ') {
				
			}
		}
		else {

			Number1++;

	
			//������������¼��
			int SameApple[MAX] = { 0 };
			int j;
			j = 0;

			for (int i = 0; i < MAX; i++) {
				if (key == a[i].m_ch) {
					//CreateThread(0, 0, Boom, 0, 0, 0);
					//Number2++;
					//Score += 10;

					//������ֶ����ͬ��ĸʱ����һ������ʧ������
					//���Ƚ��������ѭ����ɸ����ͬ��ĸ���±꣡
					SameApple[j] = i;
					j++;

					//ManyApple(a[i]);//��ʼ���Ӻ�
					//break;//Ŀ�ģ�������ͬ��ĸʱ������һ����ʧ���������÷֣�����
				}
			}
			if (j != 0) {//ȷ��������ȷ����ĸ�ٽ����жϣ�

				int LocaTion;
				LocaTion = SameApple[0];//������ʱ����������һ��Ϊ�������

				for (int i = 0; i < j - 1; i++) {

					int iMax = SameApple[i];

					for (int k = i + 1; k < j; k++) {

						if (a[iMax].m_Y < a[SameApple[k]].m_Y)
						{
							iMax = SameApple[k];
							SameApple[k] = SameApple[i];
							SameApple[i] = iMax;

						}
					}
					break;//ȡð������ĵ�һ�ξͿ��ԣ�ֻ��Ҫ����ֵ
				}

				CreateThread(0, 0, Boom, 0, 0, 0);
				Number2++;
				Score += 10;
				ManyApple(a[SameApple[0]]);
			}

		}
	}
}


//��Ϸʱ�����
int ShowTime()
{
	Flage++;
	if (Flage < N) {
		return 0;
	}
	else {
		return 1;
	}

}


//��ڽ�����Ϣ���ܵĺ���
void imformation()
{
	cout << "*******  ����7������Ϸ��-7�˳���Ϸ��������֮ǰ������ϸ�Ķ���Ϸ˵���� *******" << endl;
	cout << "*******  ������Ϸ�󣬰�һ�� 1 ��ʾ��һ�Ѷȣ����а�������  *******" << endl;
	cout << "*******  ������Ϸ�󣬰�һ�� 2 ��ʾ�ڶ��Ѷȣ����а�������  *******" << endl;
	cout << "*******  ������Ϸ�󣬰�һ�� 3 ��ʾ�����Ѷȣ����а�������  *******" << endl;
	cout << "*******  ������Ϸ�󣬰��¿ո��Ϊ��ͣ���ٰ�������  *******" << endl;
	cout << "*******  ������Ϸ�󣬰�һ�� 4 ��Ϸ��ʱ��ͣ������Ҳ����֮��ͣ  *******" << endl;
	cout << "*******  ÿ����Ϸʱ��Ϊһ���ӣ� �����ῴ�����ĵ÷�����ȷ�ʣ�  *******" << endl;
	cout << "*******  ��ܰ��ʾ����������ĸҲ�ᱻ��¼��������ȷ���У�  ******* " << endl;
}

//�˳�ʱ�ر����е�����
void CloseMusci()
{
	mciSendString(L"close IOU03.mp3", 0, 0, 0);
	mciSendString(L"close IOU02.mp3", 0, 0, 0);
	mciSendString(L"close IOU01.mp3", 0, 0, 0);

}

//************************************************************������***************************************************
int main(void)
{
	int select;
	srand(time(NULL));//ʵ�����������������α���������
	class AppleMany HowMany[MAX];


	while (1) {
		imformation();
		cin >> select;
		system("cls");
		switch (select) {
		case 7:
			initgraph(800, 600);
			loadimage(&backimg, L"01.jpg", 800, 600);
			loadimage(&Apple[0], L"100.jpg", 50, 50);//����ƻ��ͼƬ���ֶ���ͼ������
			loadimage(&Apple[1], L"99.jpg", 50, 50);
			setbkmode(0);//���ñ���ģʽ
		//	putimage(0, 0, &backimg);
			//�������ͼƬ
			while (1) {
				PlayGame(HowMany);
				BeginBatchDraw();
				putimage(0, 0, &backimg);
				for (int i = 0; i < MAX; i++){
					DrawPictures(HowMany[i]);
					DateUpdate(HowMany[i]);
					if (HowMany[i].m_Y > 600) {//��ƻ������ȥ����������
						ManyApple(HowMany[i]);
						Number1++;				//������ȷ�ʣ�����
					}
				}
				Sleep(50);
				EndBatchDraw();
				
				int IOU = ShowTime();//������Ϸʱ��ı�־
				if (IOU == 1) {
					//��֮ǰ�������ٴγ�ʼ��������
					BecomeStart();


					//�ر�����
					CloseMusci();


					//���������֮�󽫷�����Ϊ0;
					PrintfScore(HowMany);


					//ȷ���˳�
					SureExit();

					break;
				}
			}
			break;

		case -7:
			//������ȫ�˳�������
			system("cls");
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;

		default:
			break;
		}


	}
	system("pause");
	return 0;
}

/*2022, 01, 03, 17:06��ϣ�����*/