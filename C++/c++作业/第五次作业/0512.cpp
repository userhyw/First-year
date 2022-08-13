//*********************************************************
//File name	 : 0509
//Author  	 : 贺洋
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;
int main(void)
{
    string a[10], s;
    int flage = 0, b = 0;
    cout << "请输入10个姓名" << endl;
    for(int i=0; i<10; i++)
    {
        cin >>a[i];
    }

    cout << "请输入您要查找的姓名" << endl;
    cin >> s;
    for(int i=0; i<10 ;i++)
   {
       if(a[i] == s)
        {
            b = i;
        }

   }

      if(b != 0 )
      {
          cout << b << endl;
      }
      else
      {
          cout << "查无此人"  << endl;
      }
    system("pause");
    return 0;
}
