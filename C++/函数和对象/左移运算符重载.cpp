#include <iostream>

using namespace std;

//��������� ostream & cout 
//ȫ�ֺ���

 class Person
{
	friend ostream& operator<<(ostream& putout, Person& p);

public:
	Person()
	{
		m_A = 10;
		m_B = 10;
	}

private:

	//���ó�Ա������������������� p.opeartor(cout)!������
	//�������ó�Ա���������ء����������
	//void operator<< (cout )
	//{

	//}

	int m_A;
	int m_B;


};

ostream & operator<<(ostream & putout , Person & p)
{
	cout << p.m_A << " " << p.m_B;


	return putout;//���ñ�����������
	//cout == putout;
}

void test01()
{
	Person p;
	//p.m_A = 10;
	//p.m_B = 10;

	cout << p << endl;

}

int main(void)
{
	test01();


	system("pause");
	return 0;
}