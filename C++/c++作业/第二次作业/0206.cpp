//*********************************************************
//File name	 : 0206
//Author  	 : 贺洋
//Date   	 : 2021/10/18
//Student ID   : 2021218147
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
    float a, b, c, d, h;
    cout << "键盘任意输入4门课程的成绩，得到它们的平均成绩" <<endl;
    cin >> a >> b >> c >> d;
    h = (a + b + c + d)/4.0f;
    cout << "平均成绩为:"<< h << endl;

    system("pause");

    return 0;
}
