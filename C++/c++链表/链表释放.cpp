/*-----------------------------------------------
  Filename: CHAP7EXC.cpp
  Purpose: Basic linked list test!
  Date:   2021.11.06
 ----------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct student {
	long lNum;
	float fScore;
	struct student* pNext;
};

const int SIZE = sizeof(struct student);

struct student* CreatLiList(void);
void TraverLiList(struct student*);
int AppendNode(struct student*, long, float);
int DeleteNode(struct student*, long);
int SearchNode(struct student*, long);
struct student* ReleaseLiList(struct student*);

int main(void) {
	struct student* spHead = NULL;
	int iIndex, iStatus = 0;
	long lID;
	float fScore;
	do {
		system("CLS");
		cout << "������0��5��ѡ����:\n";
		cout << "0.�˳���\n";
		cout << "1.��������\n";
		cout << "2.������ʾ����\n";
		cout << "3.����β��׷�ӽ�㡣\n";
		cout << "4.ɾ��ָ����㡣\n";
		cout << "5.����ѧ�Ų��ҡ�\n";

		cout << "\n����ѡ���";
		cin >> iIndex;
		//fflush(stdin);

		switch (iIndex)
		{
		case 0:
			if (spHead != NULL) {//�ͷ�����
				ReleaseLiList(spHead);
				spHead = NULL;
			}
			exit(0);
		case 1:
			system("CLS");
			if (spHead != NULL) {
				ReleaseLiList(spHead);
				spHead = NULL;
			}
			cout << "�Կո�ָ�����ѧ�š��ɼ���س�ȷ�ϣ�����-1������\n";
			spHead = CreatLiList();
			break;
		case 2:
			system("CLS");
			if (spHead == NULL) {
				cout << "������δ��������ѡ��1��������";
				system("Pause");
				break;
			}
			cout << "�����е�����Ϊ��\n";
			TraverLiList(spHead);
			system("pause");
			break;
		case 3:
			system("CLS");
			if (spHead == NULL) {
				cout << "������δ��������ѡ��1��������";
				system("Pause");
				break;
			}
			cout << "�Կո�ָ�����׷�ӵ�ѧ�ţ�������";
			cin >> lID >> fScore;
			AppendNode(spHead, lID, fScore);
			break;
		case 4:
			system("CLS");
			if (spHead == NULL) {
				cout << "������δ��������ѡ��1��������";
				system("Pause");
				break;
			}
			cout << "����Ҫɾ������ѧ�ţ�";
			cin >> lID;
			iStatus = DeleteNode(spHead, lID);
			if (iStatus == 1) {
				cout << "Fail to delete!\n";
			}
			else {
				cout << "successfully delete!\n";
			}
			system("Pause");
			break;
		case 5:
			system("CLS");
			if (spHead == NULL) {
				cout << "������δ��������ѡ��1��������";
				system("Pause");
				break;
			}
			cout << "������Ҫ���ҵ�ѧ�ţ�";
			cin >> lID;
			iStatus = SearchNode(spHead, lID);
			if (iStatus == 1) {
				cout << "The Id is not found!\n";
			}
			system("Pause");
			break;
		default:
			cout << "Selection is error!\n";
			system("Pause");
		}
	} while (1);
	return 0;
}

/*---------------------------------------------------------
 *	Name		:CreatLiList
 *  Purpose     :Create a linked list
 *  Argument(s)	: No.
 *  return      :struct student * linked list head
 --------------------------------------------------------*/
struct student* CreatLiList(void)
{
	struct student* spHead, * spPre, * spCur;
	long lv;
	float fv;
	spPre = new struct student;
	//spPre  = (struct student *)malloc(SIZE);//ͷ���
	if (spPre == NULL) {
		return NULL;
	}
	spHead = spPre;
	spHead->pNext = NULL;

	do {
		cin >> lv >> fv;
		if (lv != -1) {
			spCur = new struct student;
			//spCur = (struct student *)malloc(SIZE);
			spCur->lNum = lv;
			spCur->fScore = fv;
			spCur->pNext = NULL;
			spPre->pNext = spCur;
			spPre = spCur;


		}
	} while (lv != -1);//��-1������
	return spHead;
}

/*---------------------------------------------------------
 *	Name		:TraverLiList
 *  Purpose     :Traver the linked list,display data field
 *  Argument(s)	:struct student * linked list head
 *  return      :No.
 --------------------------------------------------------*/
void TraverLiList(struct student* sp)
{
	struct student* spCur;
	spCur = sp->pNext;
	while (spCur != NULL) {
		cout << "ID:" << setw(12) << spCur->lNum;
		cout << setw(5) << fixed << setprecision(1) << spCur->fScore;
		cout << endl;
		spCur = spCur->pNext;
	}
}

/*---------------------------------------------------------
 *	Name		:AppendNode
 *  Purpose     :Append a node in the linked list
 *  Argument(s)	:struct student * linked list head
 *				:long lArg & fArg data field.
 *  return      :int status:0 success,1 fail.
 --------------------------------------------------------*/
int AppendNode(struct student* sp, long lArg, float fArg)
{
	struct student* spCur, * spNew;
	spCur = sp;
	while (spCur->pNext != NULL) {
		spCur = spCur->pNext;
	}
	//spNew = (struct student *)malloc(SIZE);
	spNew = new struct student;
	if (spNew == NULL) {
		return 1;
	}
	spNew->lNum = lArg;
	spNew->fScore = fArg;
	spNew->pNext = NULL;
	spCur->pNext = spNew;
	return 0;
}

/*---------------------------------------------------------
 *	Name		:DeleteNode
 *  Purpose     :Delete the node in the linked list
 *  Argument(s)	:struct student * linked list head
 *				:long lArg deleted data field.
 *  return      :int status:0 success,1 fail.
 --------------------------------------------------------*/
int DeleteNode(struct student* sp, long lArg)
{
	struct student* spCur, * spT;
	spCur = sp;
	while (spCur->pNext != NULL && spCur->pNext->lNum != lArg) {
		spCur = spCur->pNext;
	}
	if (spCur->pNext == NULL) {
		return 1;
	}
	spT = spCur->pNext;
	spCur->pNext = spCur->pNext->pNext;
	delete spT;
	//free(spT);
	return 0;
}

/*---------------------------------------------------------
 *	Name		:SearchNode
 *  Purpose     :Search the lNum data in the linked list
 *  Argument(s)	:struct student * linked list head
 *				:long lArg search data field.
 *  return      :int status:0 success,1 fail.
 --------------------------------------------------------*/
int SearchNode(struct student* sp, long lArg)
{
	struct student* spCur;
	spCur = sp;
	while (spCur->pNext != NULL && spCur->lNum != lArg) {
		spCur = spCur->pNext;
	}
	if (spCur->lNum == lArg) {
		cout << "ID:" << setw(12) << spCur->lNum;
		cout << setw(5) << fixed << setprecision(1) << spCur->fScore;
		return 0;
	}
	else
	{
		return 1;
	}
}

/*---------------------------------------------------------
 *	Name		:ReleaseLiList
 *  Purpose     :Release the linked list resource.
 *  Argument(s)	:struct student * linked list head
 *  return      :NULL head pointer point to NULL
 --------------------------------------------------------*/
struct student* ReleaseLiList(struct student* sp)
{
	struct student* spCurr, * spPrv;
	spPrv = sp;
	while (spPrv->pNext != NULL) {
		spCurr = spPrv->pNext;
		//free(spPrv);
		delete spPrv;
		spPrv = spCurr;
	}
	//free(sp);
	delete spPrv;
	return NULL;
}
/*----------------------End of the file ------------------*/
