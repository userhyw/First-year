//*********************************************************
//File name	 :0307
//Author  	 :heyang 
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    int a, b;
    cout << "请分别输入年份和月份" << endl;
    cin >> a >> b;
    if(a%400==0 || a%4==0)
    {
        switch(b)
    {
    case 1 : cout << "31"<< endl;
    break;
    case 2 : cout << "29"<< endl;
    break;
    case 3 : cout << "31"<< endl;
    break;
    case 4 : cout << "30"<< endl;
    break;
    case 5 : cout << "31"<< endl;
    break;
    case 6 : cout << "30"<< endl;
    break;
    case 7 : cout << "31"<< endl;
    break;
     case 8 : cout << "31"<< endl;
    break;
    case 9 : cout << "30"<< endl;
    break;
    case 10 : cout << "31"<< endl;
    break;
    case 11 : cout << "30"<< endl;
    break;
    case 12 : cout << "31"<< endl;
    break;}

    }
    else
    {
          switch(b)
           {
    case 1 : cout << "31"<< endl;
    break;
    case 2 : cout << "28"<< endl;
    break;
    case 3 : cout << "31"<< endl;
    break;
    case 4 : cout << "30"<< endl;
    break;
    case 5 : cout << "31"<< endl;
    break;
    case 6 : cout << "30"<< endl;
    break;
    case 7 : cout << "31"<< endl;
    break;
     case 8 : cout << "31"<< endl;
    break;
    case 9 : cout << "30"<< endl;
    break;
    case 10 : cout << "31"<< endl;
    break;
    case 11 : cout << "30"<< endl;
    break;
    case 12 : cout << "31"<< endl;
    break;
            }
    }
    system("pause");
    return 0;
}

