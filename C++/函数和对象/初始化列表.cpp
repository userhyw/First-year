#include <iostream>

using namespace std;

class Person
{
public:
	//��ʼ���б�
	//Ϊ�˸����
	Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c){}

		int m_A;
		int m_B;
		int m_C;
};

void text01()
{
	//�����ĸ����ֵ;
	//��ϵ�궨��������ݵĳ�ʼ�����޸ģ�����
	Person p(30,20,10);
	cout << "m_A = " << p.m_A << endl;
	cout << "m_B = " << p.m_B << endl;
	cout << "m_C = " << p.m_C << endl;
}

int main(void)
{
	text01();


	system("pause");
	return 0;
}