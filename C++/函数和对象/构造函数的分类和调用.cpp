#include <iostream>

using namespace std;

class Person
{
public:
	
	Person() {
		 age = 10;
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int a) {
		cout << "Person的有参构造函数调用" << endl;
		age = a;
	}

	//拷贝构造函数
	Person(const Person& p) {
		age = p.age;
		cout << "Person的拷贝构造函数调用" << endl;
	}
	 
	~Person() { cout << "Person的析构函数调用" << endl; }
    int age;

};

void text01()
{
	//1.括号法
	Person p;//默认构造函数调用
	Person p2(10);//有参构造函数调用
	Person p3(p2);

	cout << p2.age << endl;
	cout << p3.age << endl;
	cout << p.age << endl;
}

int main(void)
{
	text01();
	
	system("pause");
	return 0;
}