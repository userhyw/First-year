//*********************************************************
//File name	 : 0405
//Author  	 :heyang
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
//⒌	定义一个字符数组，输入一串字符，统计其中字符的ACSII码值个位数是3的字符个数。
using namespace std;
int main(void)
{    int c, b;
       b = 0;
    char a[80];
    cin.getline(a,80);
    for(int i = 0;a[i] ;i++)
    {
        c = int (a[i]) ;
        if(c%10==3)
        {
            b +=1;
        }
    }

cout << b << endl;


    system("pause");
    return 0;
}
