//*********************************************************
//File name	 : 0803
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
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
struct student* NewHead(struct student* spHead);
void HeadTurn(struct student* spHead);

int main(void) {
	struct student* spHead = NULL;
	int iIndex, iStatus = 0;
	long lID;
	float fScore;
	do {
		system("CLS");
		cout << "请输入0到5，选择功能:\n";
		cout << "0.退出！\n";
		cout << "1.建立链表。\n";
		cout << "2.遍历显示链表。\n";
		cout << "3.链表尾部追加结点。\n";
		cout << "4.删除指定结点。\n";
		cout << "5.输入学号查找。\n";
		cout << "6.输入实现链表的头插。\n";
		cout << "7.输入实现链表的逆序。\n";

		cout << "\n输入选择项：";
		cin >> iIndex;
		//fflush(stdin);

		switch (iIndex)
		{
		case 0:
			if (spHead != NULL) {//释放链表
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
			cout << "以空格分隔输入学号、成绩后回车确认（输入-1结束）\n";
			spHead = CreatLiList();
			break;
		case 2:
			system("CLS");
			if (spHead == NULL) {
				cout << "链表尚未建立，请选择1建立链表！";
				system("Pause");
				break;
			}
			cout << "链表中的数据为：\n";
			TraverLiList(spHead);
			system("pause");
			break;
		case 3:
			system("CLS");
			if (spHead == NULL) {
				cout << "链表尚未建立，请选择1建立链表！";
				system("Pause");
				break;
			}
			cout << "以空格分隔输入追加的学号，分数：";
			cin >> lID >> fScore;
			AppendNode(spHead, lID, fScore);
			break;
		case 4:
			system("CLS");
			if (spHead == NULL) {
				cout << "链表尚未建立，请选择1建立链表！";
				system("Pause");
				break;
			}
			cout << "输入要删除结点的学号：";
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
				cout << "链表尚未建立，请选择1建立链表！";
				system("Pause");
				break;
			}
			cout << "输入需要查找的学号：";
			cin >> lID;
			iStatus = SearchNode(spHead, lID);
			if (iStatus == 1) {
				cout << "The Id is not found!\n";
			}
			system("Pause");
			break;
		case 6://实现链表的头插;
			system("cls");
			NewHead(spHead);


			break;

		case 7://实现链表的逆序;
			system("cls");
			HeadTurn(spHead);

			break;
		default:
			cout << "Selection is error!\n";
			system("Pause");
		}
	} while (1);
	return 0;
}

/*---------------------------------------------------------
 *	Name		:NewHead
 *  Purpose     :Create a  New Head linked list
 *  Argument(s)	: No.
 *  return      :struct student*
 --------------------------------------------------------*/
struct student *NewHead(struct student* spHead)
{
	if (spHead != NULL) {
		struct student* current, * spHead2;
		long lv;
		float fv;
		current = new struct student;
		if (current == NULL) {
			return NULL;
		}

		cout << "请输入学生的学号： " << endl;
		cin >> lv;
		current->lNum = lv;

		cout << "请输入学生的成绩  " << endl;
		cin >> fv;
		current->fScore = fv;


		current->pNext = spHead->pNext;
		spHead->pNext = current;

		cout << "插入成功！请按任意键返回！" << endl;
		system("pause");
		system("cls");
		return spHead;
	}
	else {
		cout << "请您先返回建立链表！" << endl;
		cout << "按任意键均可返回！" << endl;
		system("pause");
	}


}

/*---------------------------------------------------------
 *	Name		:HeadTurn
 *  Purpose     :make Head become tail
 *  Argument(s)	: No.
 *  return      :void
 --------------------------------------------------------*/
//头插法实现
void HeadTurn(struct student* spHead)
{
	if (spHead == NULL) {
		cout << "您还没有创建链表！" << endl;
		cout << "按任意键返回哦！" << endl;
		system("pause");
		return;
	}
	struct student*p, *q;
	p = spHead->pNext;
	spHead->pNext = NULL;

	while (p){

		q = p;
		p = p->pNext;

		q->pNext = spHead->pNext;
		spHead->pNext = q;
		
		//后面和链表的头插一模一样！！！
		/*current->pNext = spHead->pNext;
		spHead->pNext = current;*/

	}

	cout << "倒序成功！按任意键返回！" << endl;
	system("pause");
	system("cls");

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
	//spPre  = (struct student *)malloc(SIZE);//头结点
	if (spPre == NULL) {
		return NULL;
	}
	spHead = spPre;
	spHead->pNext = NULL;

	do {
		cin >> lv >> fv;
		if (lv != -1) {
			spCur = new struct student;
			//spcur = (struct student *)malloc(size);
			spCur->lNum = lv;
			spCur->fScore = fv;
			spCur->pNext = NULL;
			spPre->pNext = spCur;
			spPre = spCur;
		}
	} while (lv != -1);//以-1结束。
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
