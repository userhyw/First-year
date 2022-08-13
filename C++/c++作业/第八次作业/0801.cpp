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

//创建一个四门分数的结构体
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
	void ALL()//计算出每一个学生的总分和均分
	{
		for (int i = 0; i < 4; i++){
			A_score += a[i];
		}
		P_score = A_score / 4.0;
	}


};

//创建学生类结构，包括姓名，学号以及四门功课的成绩；
struct Student
{
	string Name ;
	string Number;
	Score socre;
};

//添加学生基本信息
void AddStudent(Student* p, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "请分别输入学生的姓名·学号·四门科目成绩！！！" << endl;
		cin >> p[i].Name >> p[i].Number >> p[i].socre.a[0]
			>> p[i].socre.a[1] >> p[i].socre.a[2] >> p[i].socre.a[3];
	}
	cout << "输入成功！按任意键返回刚才界面！" << endl;
	system("pause");
	system("cls");

	
}

//储存学生的总分和均分
void ALLscore(Student* p, int n)
{   //要算n个人的；
	for (int i = 0; i < n; i++) {
		p[i].socre.ALL();
	}
	
}

//对总分高的学生排序
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

//按总分打印学生的排名单，附上均分；
void Printf2(Student* p, int n)
{
	cout << "姓名： " << " 学号：" << "     " << "科目一： " << "科目二： " << "科目三： " << "科目四： "
		<< "总分： " << "平均分： " << endl;
	for (int i = 0; i < n; i++) {
		cout << p[i].Name << setw(7) << p[i].Number << "  "
			<< p[i].socre.a[0] << setw(7)<< p[i].socre.a[1] << setw(7) << p[i].socre.a[2] << setw(7)
			<< p[i].socre.a[3] << setw(7)
			<< p[i].socre.A_score << setw(7) << p[i].socre.P_score << endl;
	}
	cout << "查看成功！请按任意键返回！" << endl;
	system("pause");
	system("cls");

}


int main(void)
{
	int n, Select;
	cout << "请输入学生的数量（友情提示您只有一次机会）！！！" << endl;
	cin >> n;
	struct Student* arr = new Student[n];                                                                                    
	if (arr == NULL) {
		cout << "分配内存失败" << endl;
		return 1;
	}
	
	while (1) {
	cout << "**********  输入* 1 *进行学生的姓名·学号·各科分数录入  **********" << endl;
	cout << "**********  输入* 2  *为查看学生总分排名及该生最高分  **********" << endl;
	cout << "***********  输入* 3 *退出  **********" << endl;
			
	while (1) {
		cin >> Select;
		if (Select != 1 && Select != 2 && Select != 3) {
			cout << "请输入正确的指令" << endl;
		}
		else {
			break;
		}
	}
		switch (Select) {
		case 1 ://录入信息
			AddStudent(arr, n);
			break;
		case 2://总分和单科最高
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
