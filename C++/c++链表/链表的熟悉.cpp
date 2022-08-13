#include <iostream>

using namespace std;

//创建一个类
struct Person
{
	int date;
	Person* Next;
};


//链表的建立函数
void BuildLinkedList(struct Person* Head)
{
	struct Person* Previous = NULL, * Current = NULL;
	int date;
	Previous = (struct Person*)malloc(sizeof(struct Person));
	if (Previous == NULL) {
		cout << "建立失败！请再次建立！" << endl;
		return;
	}

	Head = Previous;
	Head->Next = NULL;

	Current = (struct Person*)malloc(sizeof(struct Person));
	if (Current == NULL) {
		cout << "建立失败！请再次建立！" << endl;
		return;
	}

	cout << "请输入数据：" << endl;
	cin >> date;
	Current->date = date;
	Current->Next = NULL;
	Previous->Next = Current;
	Previous = Current;

	cout << "建立成功！按任意键返回！" << endl;
	system("pause");
	system("cls");


}

int main(void)
{
	//创建头指针
	Person* Head = NULL;
	BuildLinkedList(Head);


	system("pause");
	return 0;
}