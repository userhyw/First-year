//*********************************************************
//File name	 : 0204
//Author  	 : 贺洋
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
const float PI = 3.14;
int main(void)
{
    float r, S, Angle;
    cout << "请分别输入扇形的角度和半径" << endl ;
    cin >> Angle;
    cin >> r;
    S = PI * r * r * (Angle/360.f);
    cout << "该扇形的面积为：" << S << endl;

    system("pause");

    return 0;
}
