#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//�����ṹ��
struct Student
{
	string Name;
	Student* Next;
};

//����ͷָ�뼰ͷ���

struct Student *Creatlilist(void)
{
	struct Student* spHead, * spPre, * spCur;
	string name;
	int flage = 1;
	spPre = new Student;//FREE!!!!
	spHead = spPre;
	spHead->Next = NULL;
	do {
		cout << "����������" << endl;
		cin >> name;
		spCur = new Student;
		spCur->Name = name;
		spCur->Next = NULL;
		spPre->Next = spCur;
		spPre = spCur;
		cout << "�˳������0" << endl;
		cin >> flage;
	} while (flage);
	return spHead;
}

//��������
void Traverlilist(struct Student* arr)
{
	struct Student* spCur;
	spCur = arr->Next;
	while (spCur != NULL) {
		cout << spCur->Name << endl;
		spCur = spCur->Next;
	}

}

//ɾ�����н��ĺ���
void Deletelilist(struct Student* arr)
{



}

int main(void)
{
	//����ͷָ�룬�Լ������
	struct Student* arr;
	arr = Creatlilist();
	Traverlilist(arr);
	


	system("pause");
	return 0;
}