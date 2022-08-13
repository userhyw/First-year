#include <iostream>

using namespace std;
#include <string>

class Building
{
	//这是最重要的一行内容！！！
	friend class GoodGay;
public:
	Building();

public:

	string m_SettingRoom;//客厅

private:

	string m_BedRoom;//卧室

};

class GoodGay
{
public:

	GoodGay();

	void visit();//参观函数 访问Buliding中的属性

	Building* building;


};

//类外写成员函数
Building::Building()
{
	m_SettingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	//创建一个建筑物的对象
	building = new Building;
}

void GoodGay::visit()
{
	cout << "好基友类正在访问" << building->m_SettingRoom << endl;

	cout << "好基友类正在访问" << building->m_BedRoom << endl;
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