//*********************************************************
//File name	 : 0806.1
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	fstream fs("hamlet.txt", ios::in | ios::binary);
	fstream fs2("Cyb.dat", ios::out | ios::binary);
	char ch, ch2, Key;

	if (!fs.is_open()) {
		cout << "�ļ���ʧ��, ����ʧ�ܣ�" << endl;
		return 1;
	}

	cout << "������������Կ��" << endl;
	cin >> Key;

	
	while ((ch = fs.get()) != EOF) {
/*		ch2 = (ch << (Key - '0')%8 | ch >> 8 - (Key - '0')%8);*///���ƴ���8λȡ��
		ch2 = (ch ^ Key);
		fs2.write(&ch2, sizeof(ch2));
	}

	cout << "���ܳɹ���" << endl;
	cout << "�����ļ��Ѵ���Cyb.dat�У�" << endl;

	fs.close();
	fs2.close();

	system("pause");
	return 0;
}
