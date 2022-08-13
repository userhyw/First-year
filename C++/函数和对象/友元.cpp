#include <iostream>

using namespace std;
#include <string>


//建筑物
class Building
{
	//很想函数的声明
	//就多了一个friend;
	friend void goodGay(Building& builiding);
public:
	Building() {
		m_sittingRoom = "客厅";
		m_BedRoom = "卧室";
	}


public:
	string m_sittingRoom;

private:
	string m_BedRoom;
};

//全局函数
void goodGay(Building &builiding)
{
	cout << "好基友的全局函数正在访问" << builiding.m_sittingRoom << endl; 

	cout << "好基友的全局函数正在访问" << builiding.m_BedRoom << endl; 

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