//*********************************************************
//File name	 : 0201
//Author  	 : ���� 
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
    cout << "��ֱ����������ε�����"<<endl;
    cin >> a >> b >> c;
    p = (a + b + c)/2.0f;
    Area = sqrt(p*(p - a)*(p - b)*(p - c));
    cout << "�������ε����Ϊ��"<< Area <<endl;
    
    system("pause");
    
    return 0;
}
