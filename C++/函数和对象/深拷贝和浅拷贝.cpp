#include <iostream>

using namespace std;
//ǳ���������������ǣ��������ڴ��ظ��ͷţ�����
//ǳ���������⣬�����������;
//������Ǽ򵥵�ֵ���������ǿ���һ���µ��ڴ�ռ���������ͬ������;
class Person
{
public:
	Person() {
		age = 10;
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(int a, int height) {
		age = a;
		Height = new int(height);
		cout << "Person���вι��캯������" << endl;
	}

	Person(const Person& p) {
		age = p.age;
		//���!!!
		Height = new int(*p.Height);
		cout << "person�Ŀ������캯������" << endl;
	}

	~Person() {
		//�������룬���������ٵ��������ͷ�;
		if (Height != NULL) {
			delete Height;
			Height = NULL;//��ֹ��ΪҰָ�룡����
		}
		cout << "Person��������������" << endl;
	}

	int age;
	int *Height;

};

void text01()
{
	Person p1(18, 160);

	cout << "p1������Ϊ " << p1.age << "���Ϊ " << *p1.Height << endl;

	Person p2(p1);

	cout << "p2������Ϊ " << p2.age << "����Ϊ " << *p2.Height << endl;
}

int main(void)
{
	text01();


	system("pause");
	return 0;
}