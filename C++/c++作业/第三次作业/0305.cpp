//*********************************************************
//File name	 :0305
//Author  	 :heyang 
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    double a, b, c;
    cout << "��������������" << endl;
    cin >> a >> b >> c;
    if(a + b > c && a - b < c)
    {
         if(a==b && b==c && a==c)
       {
        cout << "�ȱ�������" <<endl;
       }
       if((a==b && b!=c ) ||(c==b && a!=c )||(a==c && b!=c ))
       {
        cout << "����������" <<endl;
       }
       if(a*a+b*b==c*c || b*b+c*c==a*a || a*a+c*c==b*b)
       {
        cout << "ֱ��������" <<endl;
       }
        else
            {cout << "����һ��������" << endl; }

    }
    else
    {
        cout << "�ⲻ�����������" << endl;
    }

    system("pause");
    return 0;
}
