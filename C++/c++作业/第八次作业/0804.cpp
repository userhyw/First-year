//*********************************************************
//File name	 : 0804
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <windows.h>

using namespace std;

#define N 5 //�Ƶ���ʾ��ʱ�䣬��λΪ�룡
typedef  unsigned  char BYTEPORT;

//����һ���ṹ�壬����6bit�ı���a;
typedef struct ControlSystem
{
	//��ʼ����һ��ʼ�Ǻ�ơ��̵ƣ����濼��ʱ�����̻� ���̻ƣ�100 100;
	ControlSystem() { a = 34; }

	//ʹ��һ���ֽڰ�λ�е���λ������ 
	BYTEPORT a : 6;

}CSM;

void DelayTime(int iTime);

int main(void)
{
	//�����ṹ�����
	CSM p;

	//��������̵�ʱ���������ݣ�����
	int NR, NG, SR, SG;//NR -> north red!

	//������ʾ��
	cout << "��ֱ������ϱ���ĺ��ʱ����̵�ʱ�䣬�Լ�������ĺ��ʱ����̵�ʱ��" << endl;
	cout << "�����ʱ��������㣺��� > ���̵� + �Ƶƣ� * 3���������㣬������Σ�գ�����" << endl;
	cout << "�Ƶ�Ĭ�����룡��ƶ����ʱ����������е�ʱ�䣡" << endl;

	//�����ƺ��̵Ƶ�ʱ��
	cin >> NR >> NG >> SR >> SG;

	//���� a ��ֵ������ת����̵ƣ�����
	while (1) {
		system("cls");
		if (p.a == 36) {
			cout << "�ϱ����죡" << "   " << "�������죡" << endl;
			DelayTime(NG + N + SG + N);
			if (NR > NG + N + SG + N + SG + N) {
				cout << "���������е�ʱ�䣡" << endl;
				DelayTime(NR -( NG + N + SG + N + SG + N));
			}
			p.a = 20;//010 100
		}
		else if (p.a == 20) {
			cout << "�ϱ����̣�" << "   " << "�������죡" << endl;
			DelayTime(NG);
			p.a = 12;//001 100
		}
		else if (p.a == 12) {
			cout << "�ϱ����ƣ�" << "   " << "�������죡" << endl;
			DelayTime(N);
			p.a = 34;//100 010
		}
		else if (p.a == 34) {
			cout << "�ϱ����죡" << "   " << "�������̣�" << endl;
			DelayTime(SG);
			p.a = 33;//100 001
		}
		else if (p.a == 33) {
			cout << "�ϱ����죡" << "   " << "�������ƣ�" << endl;
			DelayTime(N);
			p.a = 36;//100 100
		}
	}

	system("pause");
	return 0;
}

//ʵ�ָ��ݲ���ʵ�ֵ���ʱ����
void DelayTime(int iTime)
{
	Sleep(1000 * iTime);
}
