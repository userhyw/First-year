#include <iostream>

using namespace std;

//�������Ͳ�ͬ��������ͬ��˳��ͬ;
//�������أ���߸����ԣ�����

//1.��ͬһ����������
void func(int)
{
	cout << "func �ĵ���" << endl;

}

void func()
{
	cout << "func �ĵ���1" << endl;

}

int main(void)
{
	func(5);


	system("pause");
	return 0;
}