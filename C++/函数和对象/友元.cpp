#include <iostream>

using namespace std;
#include <string>


//������
class Building
{
	//���뺯��������
	//�Ͷ���һ��friend;
	friend void goodGay(Building& builiding);
public:
	Building() {
		m_sittingRoom = "����";
		m_BedRoom = "����";
	}


public:
	string m_sittingRoom;

private:
	string m_BedRoom;
};

//ȫ�ֺ���
void goodGay(Building &builiding)
{
	cout << "�û��ѵ�ȫ�ֺ������ڷ���" << builiding.m_sittingRoom << endl; 

	cout << "�û��ѵ�ȫ�ֺ������ڷ���" << builiding.m_BedRoom << endl; 

}

void test01()
{
	Building p;
	goodGay(p);

}

int main(void)
{
	test01();

	system("pause");
	return 0;
}