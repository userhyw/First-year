//*********************************************************
//File name	 : 12
//Author  	 : he yang
//Date   	 : 2021/12/02
//Student ID   : 2021218148
//*********************************************************
//������һ����ʮ�˰༶��һ�ſγ̵ĳɼ�������һ�����������Ƿ��иóɼ���������������ţ�û�д�ӡ��ʾ!

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define N 20    //����༶����Ϊ20;

//�����ṹ�����༶��ʼ��
struct Student
{
	string Name;
	string Nomber;//������Щѧ�Ŵ���ĸ������!
	float Socre;
	int Class = 1;
};

//ͨ��ѧ��������Ӧ��������
void Setsocre(Student * str)
{
	int i = 0;
	cout << "������20���˵�ѧ�źͳɼ�!" << endl;
	while (i < 20) {
		cin >> str[i].Nomber >> str[i].Socre;
		i++;
	}
	cout << "����ɹ���" << endl;
	system("pause");
	system("cls");
	return;
}

//���ҷ����Ƿ�����ҵ���������Ҳ�������ʾ��
void Findscore(Student* str, float score)
{
	int i = 0, flage = 0;
	while (i < 20) {
		if (score == str->Socre) {
			flage++;
			cout << "��� ��" << i << endl;
			
		}
			str++;
			i++;
	}
	if (flage == 0) {
		cout << "�ڴ�����û���ҵ��÷���" << endl;
	}
	return;
}

int main(void)
{
	float score = 0;
	Student str[N];
	Setsocre(str);

	cout << "��������Ҫ���ҵķ���" << endl;
	cin >> score;

	Findscore(str, score);
	system("pause");
	return 0;
}