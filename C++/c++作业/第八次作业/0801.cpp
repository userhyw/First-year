//*********************************************************
//File name	 : 0801
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

//����һ�����ŷ����Ľṹ��
struct Score
{
	socre()
	{
		A_score = 0;
		P_score = 0;
		for (int i = 0 ; i < 4; i++){
			a[i] = 0;
		}	
	} 
	float a[4] ;
	float A_score;
	float P_score;
	void ALL()//�����ÿһ��ѧ�����ֺܷ;���
	{
		for (int i = 0; i < 4; i++){
			A_score += a[i];
		}
		P_score = A_score / 4.0;
	}


};

//����ѧ����ṹ������������ѧ���Լ����Ź��εĳɼ���
struct Student
{
	string Name ;
	string Number;
	Score socre;
};

//���ѧ��������Ϣ
void AddStudent(Student* p, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "��ֱ�����ѧ����������ѧ�š����ſ�Ŀ�ɼ�������" << endl;
		cin >> p[i].Name >> p[i].Number >> p[i].socre.a[0]
			>> p[i].socre.a[1] >> p[i].socre.a[2] >> p[i].socre.a[3];
	}
	cout << "����ɹ�������������ظղŽ��棡" << endl;
	system("pause");
	system("cls");

	
}

//����ѧ�����ֺܷ;���
void ALLscore(Student* p, int n)
{   //Ҫ��n���˵ģ�
	for (int i = 0; i < n; i++) {
		p[i].socre.ALL();
	}
	
}

//���ָܷߵ�ѧ������
void Printf1(Student* p, int n)
{
	for (int i = 0; i < n - 1; i++) {
		int iMax = p[i].socre.A_score;
		for (int j = i + 1; j < n ; j++) {
			if (iMax < p[j].socre.A_score) {
				struct Student iTmp = p[j];
				p[j]= p[i];
				p[i]= iTmp;
			}
		}
	}
}

//���ִܷ�ӡѧ���������������Ͼ��֣�
void Printf2(Student* p, int n)
{
	cout << "������ " << " ѧ�ţ�" << "     " << "��Ŀһ�� " << "��Ŀ���� " << "��Ŀ���� " << "��Ŀ�ģ� "
		<< "�ܷ֣� " << "ƽ���֣� " << endl;
	for (int i = 0; i < n; i++) {
		cout << p[i].Name << setw(7) << p[i].Number << "  "
			<< p[i].socre.a[0] << setw(7)<< p[i].socre.a[1] << setw(7) << p[i].socre.a[2] << setw(7)
			<< p[i].socre.a[3] << setw(7)
			<< p[i].socre.A_score << setw(7) << p[i].socre.P_score << endl;
	}
	cout << "�鿴�ɹ����밴��������أ�" << endl;
	system("pause");
	system("cls");

}


int main(void)
{
	int n, Select;
	cout << "������ѧ����������������ʾ��ֻ��һ�λ��ᣩ������" << endl;
	cin >> n;
	struct Student* arr = new Student[n];                                                                                    
	if (arr == NULL) {
		cout << "�����ڴ�ʧ��" << endl;
		return 1;
	}
	
	while (1) {
	cout << "**********  ����* 1 *����ѧ����������ѧ�š����Ʒ���¼��  **********" << endl;
	cout << "**********  ����* 2  *Ϊ�鿴ѧ���ܷ�������������߷�  **********" << endl;
	cout << "***********  ����* 3 *�˳�  **********" << endl;
			
	while (1) {
		cin >> Select;
		if (Select != 1 && Select != 2 && Select != 3) {
			cout << "��������ȷ��ָ��" << endl;
		}
		else {
			break;
		}
	}
		switch (Select) {
		case 1 ://¼����Ϣ
			AddStudent(arr, n);
			break;
		case 2://�ֺܷ͵������
			ALLscore(arr, n);
			Printf1(arr, n);
			Printf2(arr, n);
			break;
		case 3:
			delete[] arr;
			return 0;
		}
	}

	system("pause");

	return 0;
}
