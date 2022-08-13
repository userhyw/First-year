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
    int a, b, c, d, h;
    cout << "请输入一个四位数" << endl;
    cin >> h;
    a = h % 10;
    b = h/10%10;
    c =  h/100%10;
    d =  h/1000%10;
    cout << a << b << c << d << endl;
    system("pause");
  return 0;



}
