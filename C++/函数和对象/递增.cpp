#include <iostream>
#include <iomanip>
#include<stdlib.h>

using namespace std;

//经过黑马和弹幕的柔和，得到的比较正确的版本;

class Person
{	
	friend ostream &operator<<( ostream& cout, Person &p);

public:
	Person() {
		m_A = 10;
		m_B = 10;
	}

	Person &operator++() {
		m_A++;
		m_B++;
		return* this;
	}
	Person &operator++(int) {
		Person temp = *this;
		m_A++;
		m_B++;
		return temp;
	}

private:
	int m_A;
	int m_B;
};

//首先先让 cout 和 Person 能组合起来
                                //这边Person 引用会报错
ostream& operator<<(ostream & cout, Person &p)
{
	cout << p.m_A << "  " << p.m_B;
		return cout;
}

void test01()
{
	Person p;
	cout << p << endl;
	cout << ++p << endl;
	cout << p++ << endl;
	cout << p << endl;

}

int main(void)
{
	test01();

	system("pause");
	return 0;
}