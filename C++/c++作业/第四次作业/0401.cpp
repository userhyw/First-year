//*********************************************************
//File name	 : 0401
//Author  	 :heyang
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    long int a;
    int b;
    cout << "������һ��10�����ڵ�����" << endl;
    cin >> a;
    while(a>0)
    {
        b = a%10;
        a /=10;
        cout << b ;
    }

    system("pause");
    return 0;
}
