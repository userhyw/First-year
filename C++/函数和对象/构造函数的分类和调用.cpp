#include <iostream>

using namespace std;

class Person
{
public:
	
	Person() {
		 age = 10;
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int a) {
		cout << "Person���вι��캯������" << endl;
		age = a;
	}

	//�������캯��
	Person(const Person& p) {
		age = p.age;
		cout << "Person�Ŀ������캯������" << endl;
	}
	 
	~Person() { cout << "Person��������������" << endl; }
    int age;

};

void text01()
{
	//1.���ŷ�
	Person p;//Ĭ�Ϲ��캯������
	Person p2(10);//�вι��캯������
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