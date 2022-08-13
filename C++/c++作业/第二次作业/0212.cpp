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
    double a;
    cout << "请输入一个数" << endl;
    cin >> a;
    if ( a > 0 )
    {
        cout << "这是一个正数" << endl;
    }
          else if ( a == 0)
    {
        cout << "这是零" << endl;
    }
      else if ( a < 0)
      {
        cout << "这是一个负数" << endl;
      }



    system("pause");
    return 0;

}

