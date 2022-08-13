#include <iostream>

using namespace std;

//通过成员函数重载+运算符
class Person
{
public:
	Person() {
		m_A = 10;
		m_B = 10;
		cout << "Person的普通构造函数调用，进行简单的初始化" << endl;
	}

	int m_A;
	int m_B;
};

Person operator+(Person& p1,Person &p2) {
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//函数的重载!!!
 Person operator+(Person& p1, int num) {
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test01()
{
	Person p1;

	Person p2;

	Person p3 = p2 + p1;
 
	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;

	Person p4 = p3 + 1000;
	cout << "p4.m_A = " << p4.m_A << endl;
	cout << "p4.m_B = " << p4.m_B << endl;
}

int main(void)
{
	test01();



	system("pause");
	return 0;
}