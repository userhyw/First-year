#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#define M 1000
using namespace std;

struct Person
{
	string Name;
	int Sex;
	int Age;
	string Phone;
	string Address;
};

struct Addressbooks
{
	struct Person personArrary[M];
	int Size;

};

void showMenu();
void addPerson(Addressbooks* abs);
void showPerson(Addressbooks* abs);
//*********************************************************
int main(void)
{
	Addressbooks abs;
	abs.Size = 0;
	int select = 0;
	while (1) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1: //添加联系人
			addPerson(&abs);
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			break;
		case 4://查找联系人
			break;
		case 5://修改联系人
			break;
		case 6://清空联系人
			break;
		case 0://选0结束退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
				break;
		default:
			break;
		}
	}





	system("pause");
	return 0;
}
//************************************************************
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;

	return;
}

//1.添加联系人
void addPerson(Addressbooks *abs)
{
	//判断通讯录是不是满了
	if (abs->Size == M) {
		cout << "人满了，不能继续添加 !" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArrary[abs->Size].Name = name;
		//******************************************

		int sex;
		cout << "请输入性别" << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArrary[abs->Size].Sex = sex;
				break;
			}
				cout << "请输入正确的性别" << endl;
		}
		//*******************************************

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArrary[abs->Size].Age = age;
		//*********************************************
		
		string phone;
		cout << "请输入电话号码" << endl;
		cin >> phone;
		abs->personArrary[abs->Size].Phone = phone;
		//*********************************************
		
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArrary[abs->Size].Address = address;
		//*************************************************
	}
	abs->Size++;
	cout << "添加成功! 请按任意键回到初始菜单" << endl;
	system("pause");
	system("cls");
	return;
}

//显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->Size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->Size; i++) {
			cout << "姓名：" << abs->personArrary[i].Name << "\t";
            cout << "性别：" << abs->personArrary[i].Sex << "\t";
            cout << "年龄：" << abs->personArrary[i].Age << "\t";
            cout << "电话：" << abs->personArrary[i].Phone << "\t";
            cout << "住址：" << abs->personArrary[i].Address << endl;
		}
	}

	cout << "显示成功！请按任意键回到菜单" << endl;
	system("pause");
	system("cls");
	return;
}
