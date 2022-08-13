//*********************************************************
//File name	 : 12
//Author  	 : he yang
//Date   	 : 2021/12/02
//Student ID   : 2021218148
//*********************************************************
//⒓输入一个二十人班级的一门课程的成绩，输入一个分数查找是否有该成绩，如果有则输出序号，没有打印提示!

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define N 20    //定义班级人数为20;

//创建结构，给班级初始化
struct Student
{
	string Name;
	string Nomber;//考虑有些学号带字母和数字!
	float Socre;
	int Class = 1;
};

//通过学号输入相应分数函数
void Setsocre(Student * str)
{
	int i = 0;
	cout << "请输入20个人的学号和成绩!" << endl;
	while (i < 20) {
		cin >> str[i].Nomber >> str[i].Socre;
		i++;
	}
	cout << "存入成功！" << endl;
	system("pause");
	system("cls");
	return;
}

//查找分数是否存在找到就输出，找不到给提示。
void Findscore(Student* str, float score)
{
	int i = 0, flage = 0;
	while (i < 20) {
		if (score == str->Socre) {
			flage++;
			cout << "序号 ：" << i << endl;
			
		}
			str++;
			i++;
	}
	if (flage == 0) {
		cout << "在储存中没有找到该分数" << endl;
	}
	return;
}

int main(void)
{
	float score = 0;
	Student str[N];
	Setsocre(str);

	cout << "请输入您要查找的分数" << endl;
	cin >> score;

	Findscore(str, score);
	system("pause");
	return 0;
}