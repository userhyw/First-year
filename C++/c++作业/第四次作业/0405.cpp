//*********************************************************
//File name	 : 0405
//Author  	 :heyang
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
//��	����һ���ַ����飬����һ���ַ���ͳ�������ַ���ACSII��ֵ��λ����3���ַ�������
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
