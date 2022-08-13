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
    cout << "请输入三个数据" << endl;
    cin >> a >> b >> c;
    if(a + b > c && a - b < c)
    {
         if(a==b && b==c && a==c)
       {
        cout << "等边三角形" <<endl;
       }
       if((a==b && b!=c ) ||(c==b && a!=c )||(a==c && b!=c ))
       {
        cout << "等腰三角形" <<endl;
       }
       if(a*a+b*b==c*c || b*b+c*c==a*a || a*a+c*c==b*b)
       {
        cout << "直角三角形" <<endl;
       }
        else
            {cout << "这是一般三角形" << endl; }

    }
    else
    {
        cout << "这不能组成三角形" << endl;
    }

    system("pause");
    return 0;
}
