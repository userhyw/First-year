//*********************************************************
//File name	 : 0509
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include <iomanip>

using namespace std;
int main(void)
{
    int a[10], top = 0, bot = 9, mid, b;
    bool flage = false;
    cout << "�����������10������" << endl;
    for(int i=0; i<10; i++)
    {
        cin >> a[i];
    }

    cout << "��������Ҫ���ҵ�����" << endl;
    cin >> b;
 //b������Ĳ�������
     do{
        mid = (top + bot)/2;
        if(b == a[mid])
        {
            cout << b << "��λ����" << mid << endl;
            flage =  1;
        }
        else if(b < a[mid])
        {
            bot = mid -1;
        }
        else
        {
            top = mid +1;
        }
     }while(top <= bot && flage == false);
 if(flage == false)
 {
     cout << "���޴���" << endl;
 }

    system("pause");
    return 0;
}
