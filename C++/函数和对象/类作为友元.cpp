#include <iostream>

using namespace std;
#include <string>

class Building
{
	//��������Ҫ��һ�����ݣ�����
	friend class GoodGay;
public:
	Building();

public:

	string m_SettingRoom;//����

private:

	string m_BedRoom;//����

};

class GoodGay
{
public:

	GoodGay();

	void visit();//�ιۺ��� ����Buliding�е�����

	Building* building;


};

//����д��Ա����
Building::Building()
{
	m_SettingRoom = "����";
	m_BedRoom = "����";
}

GoodGay::GoodGay()
{
	//����һ��������Ķ���
	building = new Building;
}

void GoodGay::visit()
{
	cout << "�û��������ڷ���" << building->m_SettingRoom << endl;

	cout << "�û��������ڷ���" << building->m_BedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
}

int main(void)
{

	test01();

	system("pause");
	return 0;
}