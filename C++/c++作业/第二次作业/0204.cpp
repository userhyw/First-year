//*********************************************************
//File name	 : 0204
//Author  	 : ����
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
    cout << "��ֱ��������εĽǶȺͰ뾶" << endl ;
    cin >> Angle;
    cin >> r;
    S = PI * r * r * (Angle/360.f);
    cout << "�����ε����Ϊ��" << S << endl;

    system("pause");

    return 0;
}
