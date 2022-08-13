//*********************************************************
//File name	 :0302
//Author  	 :heyang 
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
    int a;//a代表月份
    cout << "请输入月份" << endl;
    cin >> a;
    switch(a)
    {
case 1 :
             cout << "January" << endl;
              break;
case 2 :
             cout << "February" << endl;
              break;
case 3 :
             cout << "March" << endl;
              break;
case 4 :
             cout << "April" << endl;
              break;
case 5 :
             cout << "May" << endl;
              break;
case 6 :
             cout << "June" << endl;
              break;
case 7 :
             cout << "July" << endl;
              break;
case 8 :
             cout << "August" << endl;
              break;
case 9 :
             cout << "September" << endl;
              break;
case 10 :
             cout << "October" << endl;
              break;
case 11 :
             cout << "November" << endl;
              break;
case 12 :
             cout << "December" << endl;
             break;
default :
              cout << "一年就十二个月，你想什么呢" <<endl;
    }
    system("pause");

    return 0;
}
