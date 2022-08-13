#include <iostream>

using namespace std;

//值传递，值返回都会调用拷贝构造函数。

class Person
{
public:
	Person() {
		age = 10;
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int a) {
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}
	Person(const Person& p) {
		age = p.age;
		cout << "Person的拷贝构造函数的调用" << endl;
	}

    ~Person() {
		cout << "Person的析构函数调用" << endl;
	}
	int age;
};

void text01()
{
	Person p1(20);
	Person p2(p1);

	cout << p2.age << endl;
}

//值传递的方式给函数参数传值
//值传递的本质就是，拷贝一个临时的副本出来！！！
//实参穿给形参就是拷贝过去，这是本质！！！
void doWork(Person p)
{


}

void text02()
{
	Person p;
	doWork(p);

}

//值方式返回局部对象
//函数结束就消亡，所以回传的值是拷贝过去的;
//可以通过打印地址来验证！！！
Person doWork2()
{
	Person p;
	cout << (int*)&p << endl;
	return p;
}
void text03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;
}

int main(void)
{
	//text01();
	//text02();
	//doWork2();
	text03();

	return 0;
}