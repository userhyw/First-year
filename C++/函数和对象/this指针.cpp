#include <iostream>

using namespace std;

class Person
{
public:
	Person(int age) {
		this->age = age;
	}


	//值方式返回会拷贝新的对象
	//要返回原来的对象，我们要引用的方式返回！！！
	Person &AddAge(Person& p) {
		this->age += p.age;

		//this 指向p2;
		//判断返回值还是返回对象！！！
		return *this;
	}

	int age;
};

void test01()
{
	Person p(10);

	cout << "p的年龄为 " << p.age << endl;
}

void test02()
{
	Person p1(10);

	Person p2(10);

	//链式编程思想;
	p2.AddAge(p1).AddAge(p1).AddAge(p1).AddAge(p1);

	cout << "p2的年龄为 " << p2.age << endl;
}

int main(void)
{
	test01();
	test02();


	system("pause");
	return 0;
}