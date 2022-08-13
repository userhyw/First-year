//*********************************************************
//File name	 : 0201
//Author  	 : 贺洋 
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;
#include<math.h>
#include<stdlib.h>
int main(void)
{
    float p,  a, b, c, Area;
    cout << "请分别输入三角形的三边"<<endl;
    cin >> a >> b >> c;
    p = (a + b + c)/2.0f;
    Area = sqrt(p*(p - a)*(p - b)*(p - c));
    cout << "该三角形的面积为："<< Area <<endl;
    
    system("pause");
    
    return 0;
}
