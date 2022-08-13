#include <iostream>

using namespace std;

//静态成员函数
//所有对象共享一个函数
//静态成员函数只能访问静态成员变量

class Person
{
public:

	//这是所以对象共用的，所以非静态成员变量无法写入！！！
	static void func() {
		m_A = 100;
		//m_B = 200;
		cout << "static void func 的调用" << endl;
	}

	static int m_A;//静态成员变量
	int m_B;//非静态成员变量;

};

int Person::m_A = 10;//静态成员变量赋值行为

void test01()
{
	//通过对象
	Person p;
	p.func();

	//通过类名
	Person::func();
}

int main(void)
{
	test01();



	system("pause");
	return 0;
}