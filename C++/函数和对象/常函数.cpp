#include <iostream>

using namespace std;

class Person
{
public:
	
	//thisָ��ı��� ��ָ�볣�� ָ���ָ���ǲ������޸ĵģ�����
	//Person * const this;
	//���������ϵͳĬ�϶����thisָ��
	//������thisָ���ָ�����ܸģ�����ֵ�����޸ġ�

	//�ڳ�Ա���������const�����ε���ָ��
	//�ͱ���˳�����
	//const Person * const this
	void ShowPerson() const
	{
		//this->m_Age = 10;
	}

	void test03(){
		m_Age = 100;
	}

	int m_Age;
	mutable int m_B;
};

void test01()
{
	Person p;
	p.ShowPerson();
}

//������
//������ֻ�ܵ��ó�����
void test02()
{
	const Person p;
	//p.m_Age = 10;
	p.m_B = 10;
	//p.test03();
}


int main(void)
{


	system("pause");
	return 0;
}