#include <iostream>

using namespace std;

class Person
{
public:
	
	//this指针的本质 是指针常量 指针的指向是不可以修改的！！！
	//Person * const this;
	//上面这个是系统默认定义的this指针
	//很明显this指针的指向方向不能改，但是值可以修改。

	//在成员函数后面加const，修饰的是指针
	//就变成了常函数
	//const Person * const this
	void ShowPerson() const
	{
		//this->m_Age = 10;
	}

	void test03(){
		m_Age = 100;
	}

	int m_Age;
	mutable int m_B;
};

void test01()
{
	Person p;
	p.ShowPerson();
}

//常对象
//常对象只能调用常函数
void test02()
{
	const Person p;
	//p.m_Age = 10;
	p.m_B = 10;
	//p.test03();
}


int main(void)
{


	system("pause");
	return 0;
}