#include <iostream>

using namespace std;

//ֵ���ݣ�ֵ���ض�����ÿ������캯����

class Person
{
public:
	Person() {
		age = 10;
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int a) {
		age = a;
		cout << "Person���вι��캯������" << endl;
	}
	Person(const Person& p) {
		age = p.age;
		cout << "Person�Ŀ������캯���ĵ���" << endl;
	}

    ~Person() {
		cout << "Person��������������" << endl;
	}
	int age;
};

void text01()
{
	Person p1(20);
	Person p2(p1);

	cout << p2.age << endl;
}

//ֵ���ݵķ�ʽ������������ֵ
//ֵ���ݵı��ʾ��ǣ�����һ����ʱ�ĸ�������������
//ʵ�δ����βξ��ǿ�����ȥ�����Ǳ��ʣ�����
void doWork(Person p)
{


}

void text02()
{
	Person p;
	doWork(p);

}

//ֵ��ʽ���ؾֲ�����
//�������������������Իش���ֵ�ǿ�����ȥ��;
//����ͨ����ӡ��ַ����֤������
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