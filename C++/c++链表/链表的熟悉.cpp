#include <iostream>

using namespace std;

//����һ����
struct Person
{
	int date;
	Person* Next;
};


//����Ľ�������
void BuildLinkedList(struct Person* Head)
{
	struct Person* Previous = NULL, * Current = NULL;
	int date;
	Previous = (struct Person*)malloc(sizeof(struct Person));
	if (Previous == NULL) {
		cout << "����ʧ�ܣ����ٴν�����" << endl;
		return;
	}

	Head = Previous;
	Head->Next = NULL;

	Current = (struct Person*)malloc(sizeof(struct Person));
	if (Current == NULL) {
		cout << "����ʧ�ܣ����ٴν�����" << endl;
		return;
	}

	cout << "���������ݣ�" << endl;
	cin >> date;
	Current->date = date;
	Current->Next = NULL;
	Previous->Next = Current;
	Previous = Current;

	cout << "�����ɹ�������������أ�" << endl;
	system("pause");
	system("cls");


}

int main(void)
{
	//����ͷָ��
	Person* Head = NULL;
	BuildLinkedList(Head);


	system("pause");
	return 0;
}