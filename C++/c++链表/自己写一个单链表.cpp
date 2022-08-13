#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Student
{
	int date;
	Student* Next;
}STU;

//��ʼҳ����ʾ��
void Information()
{
	cout << "����1��������" << endl;
	cout << "����2������β����ӽڵ�" << endl;
	cout << "����3�鿴����ÿ���ڵ������" << endl;
	cout << "����4����ĳһ���ڵ��ɾ��" << endl;
	cout << "����5��������" << endl;
	cout << "����-1�˳�������" << endl;
}

//����������//�����ٴδ��������⣡
STU* CreatList(void)
{
	STU* Head, * Cur, * Pre;//����Preָ���ԭ���ֹ��������ƶ���ͷָ�룬�ǿ��ܻᵼ�������Դ�����������
	int Date;
	//����ͷ�ڵ�
	Head = (STU*)malloc(sizeof(STU));
	if (Head == NULL) {
		cout << "����ʧ�ܣ�" << endl;
		return NULL;
	}

	//Pre = Head;//��������Ԫ�ڵ��ֹͷָ���ƶ���//�Ա�����

	//������Ԫ�ڵ�
	Cur = (STU*)malloc(sizeof(STU));
	if (Cur == NULL) {
		cout << "����ʧ�ܣ�" << endl;
		return NULL;
	}

	//������Ԫ�ڵ�����ݣ�
	cout << "������date��" << endl;
	cin >> Date;
	Cur->date = Date;
	Cur->Next = NULL;
	Head->Next = Cur;

	cout << "�����ɹ���" << endl;//���Խ���һ����ѭ���������ص�ֵ�˳�ѭ��
	system("pause");
	system("cls");	
	return Head;
}

//�������β����ӽ��
void Addjiedian(STU* Head)
{
	STU* Current, *Creat;
	int Date;
	Current = Head;//�����ƶ�ͷָ�룬ͷָ��ʼ��ָ��ͷ�ڵ�
	               //����Ҫ���Ǳ��������ָ��������һ���ڵ㣬������NULL������

	if (Head == NULL) {
		cout << "���Ƚ�������" << endl;
		system("pause");
		system("cls");
		return;
	}


	//����Ԫ�ڵ㿪ʼ�����ҵ�β�ڵ㣡����
	while (Current->Next) {
		Current = Current->Next;
   }

	//�ҵ�β�ڵ㿪ʼ��ӽڵ㵽β��
	Creat = (STU*)malloc(sizeof(STU));
	if (Creat == NULL) {
		cout << "���ʧ�ܣ�" << endl;
		return;
	}

	//¼�����ݣ�
	cout << "������date��" << endl;
	cin >> Date;
	Creat->date = Date;
	Creat->Next = NULL;
	Current->Next = Creat;//��һ�����д˴����ֶϵ㣡����

	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");

}

//�������������������Ԫ�أ�
void TraverList(STU* Head)
{
	STU* Current;
	if (Head == NULL) {
		cout << "�㿴�����ӣ���û������" << endl;
		system("pause");
		system("cls");
		return;
	}
	Current = Head->Next;

	//���ǵ�����Ϊ�յ����
	if (Current == NULL) {
		cout << "�����ǿյģ��㿴�����ӣ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	while (Current) {
		cout << "����Ϊ��" << Current->date << endl;
		Current = Current->Next;
	}

	cout << "�鿴�ɹ���" << endl;
	system("pause");
	system("cls");

}

//�ͷ��ڴ棡����
void Release(STU* Head)
{
	STU* Previous, * Current;
	Current = Head->Next;
	while (Current) {
		Previous = Current->Next;
		free(Current);
		Current = Previous;
	}

	free(Head);
	//cout << "�ͷųɹ���" << endl;
}

//ɾ���ڵ�---����Ѱ�Һ�ɾ��
void DeleteListone(STU* Head, int Date)
{
	STU* Current,  *Previous, *Delete;
	Current = Head;//����������У�Ҫ����ɾ���ڵ��ǰһ���ڵ㣡
	if (Head == NULL) {
		cout << "��ɾ�����ӣ�����û�����ݴ����������" << endl;
		system("pause");
		system("cls");
		return;
	}

	//���ȱ����ҵ�����ڵ��ǰһ���ڵ㣡
	while (Current->Next) {
		if (Current->Next->date == Date)break;
		Current = Current->Next;
	}
	if (Current->Next == NULL) {
		cout << "�㳶�����أ���û������ݣ���ɾ�����ӣ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	//����ɾ���������������ԣ�//�˴��û�ͼ������!!!/*����һ����*/
	Delete = Current->Next;
	Previous = Current;
	Previous->Next = Current->Next->Next;
	free(Delete);

	/*�����������ܷ���������//�˷�������࣬���ǳ�ѧ���߼��׻��ң�����
    Previous = Current->Next;
	Current->Next = Current->Next->Next;
	free(Previous)
	*/

	cout << "ɾ���ɹ���" << endl;
	system("pause");
	system("cls");
}

//���������ͷ�巨��
void ReverseList(STU* Head)
{
	STU* Current, * Previous;
	if (Head == NULL) {
		cout << "�㵹�ø����ӣ� ����û��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	Current = Head->Next;//ͷ����ָ�����Ҫ�����ƶ������һ���ڵ�ĵط���
	Head->Next = NULL;

	//����ͷ�巨����⣬Ҫ����ѭ��������ͼ��������⣡����
	while (Current) {
		Previous = Current;
		Current = Current->Next;

		Previous->Next = Head->Next;//�Ѽ�ͷ��ת�Ĳ������ڵ�һ��ѭ��ʱ�������ָ��NULL;!!!
		Head->Next = Previous;
	}

	cout << "���óɹ���" << endl;
	system("pause");
	system("cls");
}

int main(void)
{
	STU* Head = NULL;
	int Select;

	while (1) {
		Information();
		cin >> Select;
		switch (Select) {
		case 1:
			system("cls");
			if (Head != NULL) Release(Head);//�ٴν����Ļ��൱������һ������
			Head = CreatList();
			break;

		case 2:
			system("cls");
			Addjiedian(Head);
			break;

		case 3:
			system("cls");
			TraverList(Head);
			break;

		case 4:
			system("cls");
			int date;
			cout << "����������Ҫɾ��������" << endl;
			cin >> date;
			DeleteListone(Head, date);
			break;

		case 5:
			system("cls");
			ReverseList(Head);
			break;
		case -1:
			Release(Head);
			return 0;

		default:
			break;
		}

		

	}
	system("pause");
	return 0;
}

/*		cout << "�����ǿյģ��㿴�����ӣ�" << endl;
		system("pause");
		system("cls");
		
		�ܽ᣺����������д���������ж���ã����Լ��ٴ�����ظ��ԣ�����
		�������������￼��ʱ��Ҳ��������©�����������	
		
		*/