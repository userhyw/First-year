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
		case 1: //�����ϵ��
			addPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			break;
		case 4://������ϵ��
			break;
		case 5://�޸���ϵ��
			break;
		case 6://�����ϵ��
			break;
		case 0://ѡ0�����˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;

	return;
}

//1.�����ϵ��
void addPerson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�ǲ�������
	if (abs->Size == M) {
		cout << "�����ˣ����ܼ������ !" << endl;
		return;
	}
	else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArrary[abs->Size].Name = name;
		//******************************************

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArrary[abs->Size].Sex = sex;
				break;
			}
				cout << "��������ȷ���Ա�" << endl;
		}
		//*******************************************

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArrary[abs->Size].Age = age;
		//*********************************************
		
		string phone;
		cout << "������绰����" << endl;
		cin >> phone;
		abs->personArrary[abs->Size].Phone = phone;
		//*********************************************
		
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArrary[abs->Size].Address = address;
		//*************************************************
	}
	abs->Size++;
	cout << "��ӳɹ�! �밴������ص���ʼ�˵�" << endl;
	system("pause");
	system("cls");
	return;
}

//��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->Size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->Size; i++) {
			cout << "������" << abs->personArrary[i].Name << "\t";
            cout << "�Ա�" << abs->personArrary[i].Sex << "\t";
            cout << "���䣺" << abs->personArrary[i].Age << "\t";
            cout << "�绰��" << abs->personArrary[i].Phone << "\t";
            cout << "סַ��" << abs->personArrary[i].Address << endl;
		}
	}

	cout << "��ʾ�ɹ����밴������ص��˵�" << endl;
	system("pause");
	system("cls");
	return;
}
