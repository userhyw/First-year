#include <iostream>

using namespace std;


class Animal
{
public:
	virtual void Speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:

	//���������ż̳�
	virtual void Speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:

	//���������ż̳�
	 virtual void Speak()
	{
		cout << "С����˵��" << endl;
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