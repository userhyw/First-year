//*********************************************************
//File name	 : 0210
//Author  	 : 贺洋
//Date   	 : 2021/10/18
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
    int a, b, c;
    cout << "请输入两个整数" << endl;
    cin >> a >> b;
    c = b;
    b = a;
    a = c;

    cout << a << endl;
    cout << b << endl;

    system("pause");

    system("pause");
   return 0;

}
