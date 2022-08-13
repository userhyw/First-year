#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Student
{
	int date;
	Student* Next;
}STU;

//开始页面提示！
void Information()
{
	cout << "输入1建立链表" << endl;
	cout << "输入2在链表尾部添加节点" << endl;
	cout << "输入3查看链表每个节点的数据" << endl;
	cout << "输入4进行某一个节点的删除" << endl;
	cout << "输入5将链表倒置" << endl;
	cout << "输入-1退出！！！" << endl;
}

//建立链表开端//考虑再次创建的问题！
STU* CreatList(void)
{
	STU* Head, * Cur, * Pre;//创建Pre指针的原因防止错误操作移动了头指针，那可能会导致灾难性错误发生！！！
	int Date;
	//创建头节点
	Head = (STU*)malloc(sizeof(STU));
	if (Head == NULL) {
		cout << "建立失败！" << endl;
		return NULL;
	}

	//Pre = Head;//在连接首元节点防止头指针移动：//对比宣总

	//创建首元节点
	Cur = (STU*)malloc(sizeof(STU));
	if (Cur == NULL) {
		cout << "建立失败！" << endl;
		return NULL;
	}

	//输入首元节点的数据：
	cout << "请输入date：" << endl;
	cin >> Date;
	Cur->date = Date;
	Cur->Next = NULL;
	Head->Next = Cur;

	cout << "建立成功！" << endl;//可以建立一个死循环来输入特点值退出循环
	system("pause");
	system("cls");	
	return Head;
}

//在链表的尾部添加结点
void Addjiedian(STU* Head)
{
	STU* Current, *Creat;
	int Date;
	Current = Head;//不能移动头指针，头指针始终指向头节点
	               //我们要的是遍历到最后指向的是最后一个节点，而不是NULL！！！

	if (Head == NULL) {
		cout << "请先建立链表！" << endl;
		system("pause");
		system("cls");
		return;
	}


	//从首元节点开始遍历找到尾节点！！！
	while (Current->Next) {
		Current = Current->Next;
   }

	//找到尾节点开始添加节点到尾部
	Creat = (STU*)malloc(sizeof(STU));
	if (Creat == NULL) {
		cout << "添加失败！" << endl;
		return;
	}

	//录入数据！
	cout << "请输入date：" << endl;
	cin >> Date;
	Creat->date = Date;
	Creat->Next = NULL;
	Current->Next = Creat;//第一遍运行此处出现断点！！！

	cout << "添加成功！" << endl;
	system("pause");
	system("cls");

}

//遍历链表，并且输出其中元素！
void TraverList(STU* Head)
{
	STU* Current;
	if (Head == NULL) {
		cout << "你看个锤子，还没有链表" << endl;
		system("pause");
		system("cls");
		return;
	}
	Current = Head->Next;

	//考虑当链表为空的情况
	if (Current == NULL) {
		cout << "链表都是空的，你看个锤子！" << endl;
		system("pause");
		system("cls");
		return;
	}

	while (Current) {
		cout << "数据为：" << Current->date << endl;
		Current = Current->Next;
	}

	cout << "查看成功！" << endl;
	system("pause");
	system("cls");

}

//释放内存！！！
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
	//cout << "释放成功！" << endl;
}

//删除节点---数据寻找后删除
void DeleteListone(STU* Head, int Date)
{
	STU* Current,  *Previous, *Delete;
	Current = Head;//在这个过程中，要保留删除节点的前一个节点！
	if (Head == NULL) {
		cout << "你删个锤子，都还没有数据存进来！！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//首先遍历找到这个节点的前一个节点！
	while (Current->Next) {
		if (Current->Next->date == Date)break;
		Current = Current->Next;
	}
	if (Current->Next == NULL) {
		cout << "你扯犊子呢，都没这个数据，你删个锤子！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//进行删除，并保持连续性！//此处用画图理解最佳!!!/*方案一：：*/
	Delete = Current->Next;
	Previous = Current;
	Previous->Next = Current->Next->Next;
	free(Delete);

	/*方案二：宣总方案：：：//此方案更简洁，但是初学者逻辑易混乱！！！
    Previous = Current->Next;
	Current->Next = Current->Next->Next;
	free(Previous)
	*/

	cout << "删除成功！" << endl;
	system("pause");
	system("cls");
}

//链表的逆序：头插法！
void ReverseList(STU* Head)
{
	STU* Current, * Previous;
	if (Head == NULL) {
		cout << "你倒置个锤子， 都还没链表！！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	Current = Head->Next;//头结点的指向待会要跟着移动到最后一个节点的地方；
	Head->Next = NULL;

	//对于头插法的理解，要跟着循环画几次图更容易理解！！！
	while (Current) {
		Previous = Current;
		Current = Current->Next;

		Previous->Next = Head->Next;//把箭头反转的操作，在第一次循环时，巧妙的指向NULL;!!!
		Head->Next = Previous;
	}

	cout << "倒置成功！" << endl;
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
			if (Head != NULL) Release(Head);//再次建立的话相当于清零一次链表！
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
			cout << "请输入您想要删除的数据" << endl;
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

/*		cout << "链表都是空的，你看个锤子！" << endl;
		system("pause");
		system("cls");
		
		总结：这个东西最好写主函数里判断最好，可以减少代码的重复性！！！
		而且在主函数里考虑时，也不容易遗漏情况！！！！	
		
		*/