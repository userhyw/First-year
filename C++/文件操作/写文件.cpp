#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

using namespace std;

//дһ���ļ�
void test01()
{
	//1.include ͷ�ļ� fstream

	//2.��������
	ofstream ofs;

	//3.ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);

	//4.д����
	ofs << "�������ã������ź���" << endl;
	ofs << "����������ź��ģ�" << endl;
	ofs << "������أ�" << endl;

	//5.�ر��ļ�
	ofs.close();
}


int main(void)
{
	test01();



	system("pause");
	return 0;
}

//ofstream out put fstream
//ifstream input fream
//fstream �ȿ��Զ��ֿ���д��files;