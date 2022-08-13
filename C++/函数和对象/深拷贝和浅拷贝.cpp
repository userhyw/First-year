#include <iostream>

using namespace std;
//浅拷贝带来的问题是，堆区的内存重复释放！！！
//浅拷贝的问题，利用深拷贝来解;
//深拷贝不是简单的值拷贝，而是开辟一块新的内存空间来储存相同的数据;
class Person
{
public:
	Person() {
		age = 10;
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(int a, int height) {
		age = a;
		Height = new int(height);
		cout << "Person的有参构造函数调用" << endl;
	}

	Person(const Person& p) {
		age = p.age;
		//深拷贝!!!
		Height = new int(*p.Height);
		cout << "person的拷贝构造函数调用" << endl;
	}

	~Person() {
		//析构代码，将堆区开辟的数据做释放;
		if (Height != NULL) {
			delete Height;
			Height = NULL;//防止成为野指针！！！
		}
		cout << "Person的析构函数调用" << endl;
	}

	int age;
	int *Height;

};

void text01()
{
	Person p1(18, 160);

	cout << "p1的年龄为 " << p1.age << "身高为 " << *p1.Height << endl;

	Person p2(p1);

	cout << "p2的年龄为 " << p2.age << "升高为 " << *p2.Height << endl;
}

int main(void)
{
	text01();


	system("pause");
	return 0;
}