//*********************************************************
//File name	 : 0203
//Author  	 : ����
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
    cout<< "��ֱ�����Բ׶��İ뾶�͸�"<<endl;
    cin>> r >> h;
    s = PI * r * r;
    V = s * h/3.0f;
    cout<< "��Բ׶������Ϊ��"<< V << endl;
     system("pause");

    return 0;
}
