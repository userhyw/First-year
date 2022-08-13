#include <iostream>

using namespace std;


class Animal
{
public:
	virtual void Speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:

	//方便后面接着继承
	virtual void Speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:

	//方便后面接着继承
	 virtual void Speak()
	{
		cout << "小狗在说话" << endl;
	}
};

void WhoSpeak(Animal &animal)
{
	animal.Speak();
}

void test01()
{
	Cat cat;
	Dog dog;

	WhoSpeak(cat);
	WhoSpeak(dog);
}
int main(void)
{
	test01();



	system("pause");
	return 0;
}