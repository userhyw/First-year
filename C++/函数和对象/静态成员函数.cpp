#include <iostream>

using namespace std;

//��̬��Ա����
//���ж�����һ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

class Person
{
public:

	//�������Զ����õģ����ԷǾ�̬��Ա�����޷�д�룡����
	static void func() {
		m_A = 100;
		//m_B = 200;
		cout << "static void func �ĵ���" << endl;
	}

	static int m_A;//��̬��Ա����
	int m_B;//�Ǿ�̬��Ա����;

};

int Person::m_A = 10;//��̬��Ա������ֵ��Ϊ

void test01()
{
	//ͨ������
	Person p;
	p.func();

	//ͨ������
	Person::func();
}

int main(void)
{
	test01();



	system("pause");
	return 0;
}