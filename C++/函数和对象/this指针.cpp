#include <iostream>

using namespace std;

class Person
{
public:
	Person(int age) {
		this->age = age;
	}


	//ֵ��ʽ���ػ´���µĶ���
	//Ҫ����ԭ���Ķ�������Ҫ���õķ�ʽ���أ�����
	Person &AddAge(Person& p) {
		this->age += p.age;

		//this ָ��p2;
		//�жϷ���ֵ���Ƿ��ض��󣡣���
		return *this;
	}

	int age;
};

void test01()
{
	Person p(10);

	cout << "p������Ϊ " << p.age << endl;
}

void test02()
{
	Person p1(10);

	Person p2(10);

	//��ʽ���˼��;
	p2.AddAge(p1).AddAge(p1).AddAge(p1).AddAge(p1);

	cout << "p2������Ϊ " << p2.age << endl;
}

int main(void)
{
	test01();
	test02();


	system("pause");
	return 0;
}