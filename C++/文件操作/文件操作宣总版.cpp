#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

//���ܴ��ļ������� :��д�ɹ�
void text01(void)
{
	fstream ofs("love.txt", ios::out);
	ofs << "�Ұ��㣬��Ҫ����." << endl;
	ofs << "�һ�һֱ��������." << endl;
	ofs << "���ǿ�����Ҳ�������." << endl;
	ofs << "������������!" << endl;

	ofs.close();
}

//�򿪿�����
void text02(void)
{
	fstream ifs("love.txt", ios::in);

	if (!ifs) {
		cout << "wrong" << endl;
		exit(1);
	}

	char buf[80];
	while (ifs >> buf) {
		cout << buf << endl;
	}
}


int main(void)
{
	text01();
	text02();




	system("pause");
	return 0;
}