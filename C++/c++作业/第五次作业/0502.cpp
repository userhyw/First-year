//*********************************************************
//File name	 : 0502
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    int a[10], q=0, w=0, e=0, r=0, t=0;
    cout << "������ʮ���ɼ� (ÿ�Ƴɼ�����Ϊ100) " << endl;
    for(int i  = 0;i<10;i++)
    {
        cin >> a [i];
    }

    for(int i = 0;i<10;i++)
    {
        if(a[i]>= 90)
        {
            q++;
        }
    else if(a[i]>= 80)
        {
            w++;
        }
    else if(a[i]>= 70)
        {
            e++;
        }
 else if(a[i]>= 60)
        {
            r++;
        }
   else{
    t++;
   }

    }

   cout << "�� ��" <<  q << endl;
   cout << "�� ��" <<  w << endl;
   cout << "�� ��" <<  e << endl;
   cout << "���� ��" <<  r << endl;
   cout << "������ ��" <<  t << endl;
    system("pause");
    return 0;
}
