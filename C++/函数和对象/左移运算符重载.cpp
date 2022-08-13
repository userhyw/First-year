#include <iostream>

using namespace std;

//左移运算符 ostream & cout 
//全局函数

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

	//利用成员函数来重载左移运算符 p.opeartor(cout)!不方便
	//不会利用成员函数来重载《《运算符。
	//void operator<< (cout )
	//{

	//}

	int m_A;
	int m_B;


};

ostream & operator<<(ostream & putout , Person & p)
{
	cout << p.m_A << " " << p.m_B;


	return putout;//引用本身就是起别名
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