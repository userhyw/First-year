#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

#include <fstream>
//���ļ�
void test02()
{
	//1.ͷ�ļ�

	//2.��������
	ifstream ifs;

	//3.ָ���򿪷�ʽ�����ж��Ƿ�ɹ���
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "��ʧ�ܣ���������ڴ����ļ�����û�����������" << endl;
		return;
	}

	//4.��ʼ���������ַ���
	//��һ��
	/*char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}*/

	//�ڶ��ִ򿪷�ʽ
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))){
	//	cout << buf << endl;
	//}

	//�����ִ򿪷�ʽ
	//string buf;
	//while (getline(ifs, buf)) {
	//	cout << buf << endl;
	//}

	//�����ַ���//end of file�ļ�β������˼
	//��һ��һ���Ķ��ģ�Ч�ʺܵͣ����Ƽ�
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}
		
	//5.�ر��ļ�
	ifs.close();

}

int main(void)
{

	test02();



	system("pause");
	return 0;
}