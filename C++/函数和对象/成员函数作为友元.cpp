#include <iostream>

using namespace std;
#include <string>

/*��һ������Ҫ����������ı����������ַ�����
 1. ����������ָ��ķ�ʽȥ����������� ����Ҫ���ϱ������������
 eg ��Building *p��
2.����ֱ�Ӵ��������ı����� ���������ȽϿ��̣���Ҫ�ڴ����������֮ǰ��
��ɽṹ�����д.�����Ѿ�����˵ڶ������������*/

class Building
{
	public:
		//Building() {
		//	m_SettingRoom = "����";
		//	m_BedRoom = "����";
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