#include <iostream>

using namespace std;

//1.ֻҪ����һ���࣬c++�ͻ��ÿ�����������3������
//Ĭ�Ϲ��죨��ʵ�֣�
//������������ʵ�֣�
//�������죨ֵ������

class Person
{
public:
	Person() {
		age = 10;
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	
	//�����вι��캯�����Ͳ��ṩĬ�Ϲ��캯����
	Person(int a){
		age = a;
		cout << "Person���вι��캯������" << endl;
	}

	//Person(const Person& p) {
	//	age = p.age;
	//	cout << "Person�Ŀ������캯������" << endl;
	//}

	~Person() { cout << "Person��������������" << endl; }

	int age;
};

void text01()
{
	Person p;
	p.age = 18;
	Person p6(20);
	cout << p6.age << endl;
	//û��д���캯��Ҳ�����ɹ��ˣ�����
	Person p2(p);
	cout << "p2�����䣺 " << p2.age << endl;
}

int main(void)
{
	text01();

	system("pause");
	return 0;
}