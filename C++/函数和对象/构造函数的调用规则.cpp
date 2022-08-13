#include <iostream>

using namespace std;

//1.只要创建一个类，c++就会给每个类添加至少3个函数
//默认构造（空实现）
//析构函数（空实现）
//拷贝构造（值拷贝）

class Person
{
public:
	Person() {
		age = 10;
		cout << "Person的默认构造函数调用" << endl;
	}
	
	//有了有参构造函数，就不提供默认构造函数了
	Person(int a){
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}

	//Person(const Person& p) {
	//	age = p.age;
	//	cout << "Person的拷贝构造函数调用" << endl;
	//}

	~Person() { cout << "Person的析构函数调用" << endl; }

	int age;
};

void text01()
{
	Person p;
	p.age = 18;
	Person p6(20);
	cout << p6.age << endl;
	//没有写构造函数也拷贝成功了！！！
	Person p2(p);
	cout << "p2的年龄： " << p2.age << endl;
}

int main(void)
{
	text01();

	system("pause");
	return 0;
}