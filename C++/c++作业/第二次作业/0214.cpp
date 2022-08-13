//*********************************************************
//File name	 : 0211
//Author  	 : 贺洋
//Date   	 : 2021/10/18
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
    char a, b;

	cout << "请输入一个字符" << endl;
	cin >> b;
	a = (int) b;
	if (a >= 48 && a <= 57)
    {
        cout << "这是一个数字字符" << endl;
    }
	else if (a >= 65 && a <= 90)
    {
        cout << "这是一个大写字母" << endl;
    }
	else if (a >= 97 && a <= 122)
    {
        cout << "这是一个小写字母" << endl;
    }
	else
    {
        cout << "这是一个其他字符"<< endl;
    }


	system("pause");

	return 0;



}
