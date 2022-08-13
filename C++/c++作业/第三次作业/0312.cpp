//*********************************************************
//File name	 : 0312
//Author  	 :heyang
//Date   	 : 10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int main(void)
{

    double c=1, x, h=1;
    int sign = 1;//c表示cosx,y表示阶乘
    cout << "请输入x =";
    cin >> x;
    long double y = 1; 
    for(int i = 1; i < 30; i++)
    {
         h *=x*x;
        sign = -sign;
        y *= ( 2*i) * (2*i-1);
        c +=(h*sign)/y ;

    }
    cout <<  setprecision(6) << c <<endl;
    system("pause");
    return 0;
}
