#include <iostream>

using namespace std;

class Person
{
public:
	//初始化列表
	//为了更灵活
	Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c){}

		int m_A;
		int m_B;
		int m_C;
};

void text01()
{
	//更灵活的赋予初值;
	//联系宏定义进行数据的初始化的修改！！！
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