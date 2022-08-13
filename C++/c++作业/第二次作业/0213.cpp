//*********************************************************
//File name	 : 0213
//Author  	 : 贺洋
//Date   	 : 2021/10/18
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
	int a;
	cout << "请输入一个整数，我们判断其奇偶" << endl;
	cin >> a;
	if (a % 2 == 0)
	{
		cout << "这是一个偶数" << endl;
	}
	else
	{
		cout << "这是一个奇数" << endl;
	}
	system("pause");

	return 0;



}
