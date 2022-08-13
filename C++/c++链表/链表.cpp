#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//创建结构体
struct Student
{
	string Name;
	Student* Next;
};

//创建头指针及头结点

struct Student *Creatlilist(void)
{
	struct Student* spHead, * spPre, * spCur;
	string name;
	int flage = 1;
	spPre = new Student;//FREE!!!!
	spHead = spPre;
	spHead->Next = NULL;
	do {
		cout << "请输入姓名" << endl;
		cin >> name;
		spCur = new Student;
		spCur->Name = name;
		spCur->Next = NULL;
		spPre->Next = spCur;
		spPre = spCur;
		cout << "退出输入打0" << endl;
		cin >> flage;
	} while (flage);
	return spHead;
}

//遍历链表
void Traverlilist(struct Student* arr)
{
	struct Student* spCur;
	spCur = arr->Next;
	while (spCur != NULL) {
		cout << spCur->Name << endl;
		spCur = spCur->Next;
	}

}

//删除所有结点的函数
void Deletelilist(struct Student* arr)
{



}

int main(void)
{
	//创建头指针，以及添加人
	struct Student* arr;
	arr = Creatlilist();
	Traverlilist(arr);
	


	system("pause");
	return 0;
}