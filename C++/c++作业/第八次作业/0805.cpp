//*********************************************************
//File name	 : 0805
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
#define N 10               //������������;

class OtherStudent;
//�������ѧ����
class Student
{

public:
	Student()
	{
		strcpy(Name, "None");
		Number = -1;
		Age = 0;
		Sex = 'M';
	}

	void Set();
	void show();

public:
	char Name[40];
	long Number;
	int Age;
	char Sex;
};

//��������̳и���
class OtherStudent :public Student
{
	friend void Files(OtherStudent* Arr);
public:
	OtherStudent()
	{
		strcpy(Academic, "�������ѧ�뼼��");
		Ave = 0;
		All = 0;


		for (int i = 0; i < 4; i++) {
			Score[i] = 0;
		}
	}
	~OtherStudent()
	{

	}

	void AllandAve();
	void Add();
	void Show2();

	float All;
public:
	char Academic[40];
	float Score[4];
	float Ave;
};

void Scanf(OtherStudent* Arr);
void Sort(OtherStudent* Arr);
void Show3(OtherStudent* Arr);
void Files(OtherStudent* Arr);
void Printf();

int main(void)
{
	struct OtherStudent Arr[N];

	Printf();
	Scanf(Arr);
	Sort(Arr);
	cout << "����ɹ���" << endl;
	system("pause");
	system("cls");
	
	cout  << std :: left<< "ѧ�ţ�" << setw(12) << "������" << setw(12) << "���䣺" << setw(12)
		<< "�Ա�" << setw(12) << "רҵ��" << setw(12) << "���ſ�Ŀ������" << setw(12) << "�ܷ֣�" << setw(12) << "ƽ���֣�"
		<< endl;
	Show3(Arr);
	Files(Arr);
	system("pause");
	return 0;
}

//������Ϣ��ʾ
void Printf()
{
	cout << "��ֱ�����10�˵�ѧ�ţ����������䣬�Ա�M OR W����רҵ�����ſγɼ���" << endl;
}

//�ⲿʵ��STUDENT�������Ա����
void Student::Set()
{
	cin >> this->Number;
	cin >> this->Name;//�ո��ǿ��ԶϿ�����ַ������
	cin >> this->Age;
	cin >> this->Sex;

}

//�ⲿʵ��STUDENT����ʾ��Ա��������
void Student::show()
{
	cout << std :: left << setw(15) << this->Number << setw(12) << this->Name << setw(12)
		<< this->Age << setw(7) << this->Sex << setw(17);

}

//�ⲿʵ��OTHERSTUDENT�ļ���ƽ���ֺ��ֵܷĺ���;
void OtherStudent::AllandAve()
{
	for (int i = 0; i < 4; i++) {
		All += this->Score[i];
	}
	Ave = All / 4.0;
}

//�ⲿ����OTHERSTUDENT�����뺯��
void OtherStudent::Add()
{
	//����רҵ���ĿƷ���:
	cin >> this->Academic;
	for (int i = 0; i < 4; i++) {
		cin >> this->Score[i];
	}

}

//��ʾ�����е�����
void OtherStudent::Show2()
{
    cout << std :: left<< this->Academic << setw(9) << this->Score[0] << setw(9) << this->Score[1] << setw(9) << this->Score[2]
		<< setw(9) << this->Score[3]<< setw(9) << this->All << setw(9) << this->Ave << setw(9)
		<< endl;
		 

}

//�������������ݣ����ҵ��ú���������ֺ��ܷ�
void Scanf(OtherStudent* Arr)
{
	int j = 1;
	for (int i = 0; i < N; i++) {
		 Arr[i].Set();
		 Arr[i].Add();
		 Arr[i].AllandAve();
		 cout << "���ǵ�" << j << "��ѧ����" << endl;
		 j++;
	}

}

//���ܷ�������ð������
void Sort(OtherStudent* Arr)
{
	for (int i = 0; i < N - 1; i++) {
		
		for (int j = i + 1; j < N; j++) {
			if (Arr[i].All < Arr[j].All) {
				OtherStudent iTemp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = iTemp;
			}
		}
	}


}

//���������ʾ��
void Show3(OtherStudent* Arr)
{

	for (int i = 0; i < N; i++) {
		Arr[i].show();
		Arr[i].Show2();
	}

}

//�����õ������ݴ����ļ��еĺ���
void Files(OtherStudent* Arr)
{
	fstream fs("8148.txt", ios::out);
	for (int i = 0; i < N; i++) {

		//fs.write((char*)&Arr[i], sizeof(Arr[i]));
        fs << std::setw(15) << Arr[i].Number << "\t" << std::setw(15) << Arr[i].Name << "\t" << std::setw(15)
		<< Arr[i].Age << "\t" << std::setw(15) << Arr[i].Sex << "\t" << std::setw(15)
		<< Arr[i].Academic << "\t" << std::setw(15) << Arr[i].Score[0] << "\t" << std::setw(15)
		<< Arr[i].Score[1] << "\t" << std::setw(15) << Arr[i].Score[2] << "\t" << std::setw(15)
		<< Arr[i].Score[3] << "\t" << std::setw(15) << endl;
	}
	fs.close();
}
