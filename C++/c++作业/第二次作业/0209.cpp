//*********************************************************
//File name	 : 0209
//Author  	 : ����
//Date   	 : 2021/10/18
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
    float a, b, c, h;
    int i;
    cout << "���д��𡢴�������ʡ�������ޣ������õ��������Ϣ�ܺͣ����Ƹ�����" <<endl;

    cin >> a >> h >> b;
    i = 0;
    while(i<b)
    {
        a *= (1 + h);
        i ++;
    }
    cout << a <<endl;
    system("pause");

    return 0;
}
