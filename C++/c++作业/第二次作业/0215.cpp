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
    int a;
    cout <<"请输入一个年份" << endl;
    cin >> a;
    if (a%400==0)
    {
        cout << "这是一个润年" << endl;
    }
    else
    {
        if (a%4==0)
        {
            cout << "这是一个润年" <<endl;
        }
        else
        {
            cout << "这不是一个润年" << endl;
        }
    }

    system("pause");
    return 0;

}
