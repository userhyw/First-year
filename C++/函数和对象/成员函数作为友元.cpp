#include <iostream>

using namespace std;
#include <string>

/*在一个类中要包含其他类的变量，有两种方法。
 1. 是我们利用指针的方式去访问这个变量 并且要加上被包含类的声明
 eg ：Building *p；
2.我们直接创建这个类的变量， 但是条件比较苛刻，需要在创建这个变量之前。
完成结构体的书写.下面已经完成了第二种情况！！！*/

class Building
{
	public:
		//Building() {
		//	m_SettingRoom = "客厅";
		//	m_BedRoom = "卧室";
		//}
	

		string m_SettingRoom;
private:
		string m_BedRoom;
};

class GoodGay
{
public:

	GoodGay();

	void visit01();

	void visit02();

	Building building;
};

 void GoodGay ::  visit01()
{

}

int main(void)
{




	system("pause");
	return 0;
}