//*********************************************************
//File name	 : 0806.2
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <fstream>

using namespace std;

#define NEWLINE cout << endl

int main(void)
{
	fstream fs("Cyb.dat", ios::in | ios::binary);//�������ļ��򿪵ķ�ʽ����ȡ��
	char ch2, Key1;
	int ch3;//EOF��ʾ���ε�-1����int���������գ�����ĩβ��

	cout << "������������ʱ����Կ��" << endl;
	cin >> Key1;
	NEWLINE;
	
	if (!fs.is_open()) {
		cout << "�ļ���ʧ�ܣ�����ʧ�ܣ�" << endl;
	}


	while ((ch3 = fs.get()) != EOF) {//������Ŷ�ȡ��ֱ�������ļ�ĩβ��

		//�ƶ�λ�����ܳ����ˣ�����
		//ch2 = (char)(ch3 >>( Key1 - '0') | ch3 << 8 - (Key1 - '0'));//������
		ch2 = (ch3 ^ Key1);//����һ
		cout << ch2;
	}
	NEWLINE;

	cout << "�����ļ����ϣ�" << endl;
	NEWLINE;

	system("pause");
	return 0;
}
