//*********************************************************
//File name	 : 0805
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
#define N 10               //设置人数限制;

class OtherStudent;
//定义基类学生类
class Student
{

public:
	Student()
	{
		strcpy(Name, "None");
		Number = -1;
		Age = 0;
		Sex = 'M';
	}

	void Set();
	void show();

public:
	char Name[40];
	long Number;
	int Age;
	char Sex;
};

//定义子类继承父类
class OtherStudent :public Student
{
	friend void Files(OtherStudent* Arr);
public:
	OtherStudent()
	{
		strcpy(Academic, "计算机科学与技术");
		Ave = 0;
		All = 0;


		for (int i = 0; i < 4; i++) {
			Score[i] = 0;
		}
	}
	~OtherStudent()
	{

	}

	void AllandAve();
	void Add();
	void Show2();

	float All;
public:
	char Academic[40];
	float Score[4];
	float Ave;
};

void Scanf(OtherStudent* Arr);
void Sort(OtherStudent* Arr);
void Show3(OtherStudent* Arr);
void Files(OtherStudent* Arr);
void Printf();

int main(void)
{
	struct OtherStudent Arr[N];

	Printf();
	Scanf(Arr);
	Sort(Arr);
	cout << "输入成功！" << endl;
	system("pause");
	system("cls");
	
	cout  << std :: left<< "学号：" << setw(12) << "姓名：" << setw(12) << "年龄：" << setw(12)
		<< "性别：" << setw(12) << "专业：" << setw(12) << "四门科目分数：" << setw(12) << "总分：" << setw(12) << "平均分："
		<< endl;
	Show3(Arr);
	Files(Arr);
	system("pause");
	return 0;
}

//输入信息提示
void Printf()
{
	cout << "请分别输入10人的学号，姓名，年龄，性别（M OR W），专业，四门课成绩：" << endl;
}

//外部实现STUDENT的输入成员函数
void Student::Set()
{
	cin >> this->Number;
	cin >> this->Name;//空格是可以断开这个字符输入的
	cin >> this->Age;
	cin >> this->Sex;

}

//外部实现STUDENT的显示成员函数数据
void Student::show()
{
	cout << std :: left << setw(15) << this->Number << setw(12) << this->Name << setw(12)
		<< this->Age << setw(7) << this->Sex << setw(17);

}

//外部实现OTHERSTUDENT的计算平均分和总分的函数;
void OtherStudent::AllandAve()
{
	for (int i = 0; i < 4; i++) {
		All += this->Score[i];
	}
	Ave = All / 4.0;
}

//外部定义OTHERSTUDENT的输入函数
void OtherStudent::Add()
{
	//输入专业和四科分数:
	cin >> this->Academic;
	for (int i = 0; i < 4; i++) {
		cin >> this->Score[i];
	}

}

//显示子类中的数据
void OtherStudent::Show2()
{
    cout << std :: left<< this->Academic << setw(9) << this->Score[0] << setw(9) << this->Score[1] << setw(9) << this->Score[2]
		<< setw(9) << this->Score[3]<< setw(9) << this->All << setw(9) << this->Ave << setw(9)
		<< endl;
		 

}

//输入数组中数据：并且调用函数算出均分和总分
void Scanf(OtherStudent* Arr)
{
	int j = 1;
	for (int i = 0; i < N; i++) {
		 Arr[i].Set();
		 Arr[i].Add();
		 Arr[i].AllandAve();
		 cout << "这是第" << j << "个学生！" << endl;
		 j++;
	}

}

//以总分来排序，冒泡排序：
void Sort(OtherStudent* Arr)
{
	for (int i = 0; i < N - 1; i++) {
		
		for (int j = i + 1; j < N; j++) {
			if (Arr[i].All < Arr[j].All) {
				OtherStudent iTemp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = iTemp;
			}
		}
	}


}

//排序后经行显示：
void Show3(OtherStudent* Arr)
{

	for (int i = 0; i < N; i++) {
		Arr[i].show();
		Arr[i].Show2();
	}

}

//将最后得到的数据存入文件中的函数
void Files(OtherStudent* Arr)
{
	fstream fs("8148.txt", ios::out);
	for (int i = 0; i < N; i++) {

		//fs.write((char*)&Arr[i], sizeof(Arr[i]));
        fs << std::setw(15) << Arr[i].Number << "\t" << std::setw(15) << Arr[i].Name << "\t" << std::setw(15)
		<< Arr[i].Age << "\t" << std::setw(15) << Arr[i].Sex << "\t" << std::setw(15)
		<< Arr[i].Academic << "\t" << std::setw(15) << Arr[i].Score[0] << "\t" << std::setw(15)
		<< Arr[i].Score[1] << "\t" << std::setw(15) << Arr[i].Score[2] << "\t" << std::setw(15)
		<< Arr[i].Score[3] << "\t" << std::setw(15) << endl;
	}
	fs.close();
}
