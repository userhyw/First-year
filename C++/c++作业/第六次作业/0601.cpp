//*********************************************************
//File name	 : 0201
//Author  	 : 贺洋
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main(void)
{
    int a , b,*p1= NULL,*p2 = NULL;
   int t = 0;
    cout << "请输入两个整形值" << endl;
    cin >> a >> b;
    p1 = &a;
    p2 = &b;
    t = *p1;
    *p1 = *p2;
    *p2 = t;

    cout << a << " " << b;

    system("pause");
    return 0;
}
