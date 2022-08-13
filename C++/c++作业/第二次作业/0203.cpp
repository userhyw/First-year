//*********************************************************
//File name	 : 0203
//Author  	 : 贺洋
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;
const float PI = 3.14;
#include<stdlib.h>
int main(void)
{
    float r, h, s, V;
    cout<< "请分别输入圆锥体的半径和高"<<endl;
    cin>> r >> h;
    s = PI * r * r;
    V = s * h/3.0f;
    cout<< "该圆锥体的体积为："<< V << endl;
     system("pause");

    return 0;
}
