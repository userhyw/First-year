//*********************************************************
//File name	 : 0202
//Author  	 : 贺洋
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;
#include<stdlib.h>
int main(void)
{
    float a, b, c, V;
    cout<< "请分别输入长方体的长宽高"<<endl;
    cin>> a >> b >> c ;
     V = a * b* c;
    cout << "该长方体的体积为：" << V <<endl;

    system("pause");

    return 0;
}
