//*********************************************************
//File name	 : 0503
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    int a[10];
    int j = 0, r = 0;//j��¼�����ĸ�����r��¼ż������
    cout << "������ʮ������" << endl;

    for(int i =0;i<10;i++)
    {
        cin >> a[i];
    }

    for(int i = 0;i<10;i++)
    {
        if(a[i]%2==0)
        {
            r++;
        }
        else{
            j++;
        }
    }

    cout << "�����ĸ���Ϊ : " <<  j << endl;
    cout << "ż���ĸ���Ϊ : " <<  r << endl;

    system("pause");
    return 0;
}
