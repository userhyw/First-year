//*********************************************************
//File name	 : 0211
//Author  	 : ����
//Date   	 : 2021/10/18
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
    int a;
    cout <<"������һ�����" << endl;
    cin >> a;
    if (a%400==0)
    {
        cout << "����һ������" << endl;
    }
    else
    {
        if (a%4==0)
        {
            cout << "����һ������" <<endl;
        }
        else
        {
            cout << "�ⲻ��һ������" << endl;
        }
    }

    system("pause");
    return 0;

}
