//*********************************************************
//File name	 : 0509
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;
int main(void)
{
    string a[10], s;
    int flage = 0, b = 0;
    cout << "������10������" << endl;
    for(int i=0; i<10; i++)
    {
        cin >>a[i];
    }

    cout << "��������Ҫ���ҵ�����" << endl;
    cin >> s;
    for(int i=0; i<10 ;i++)
   {
       if(a[i] == s)
        {
            b = i;
        }

   }

      if(b != 0 )
      {
          cout << b << endl;
      }
      else
      {
          cout << "���޴���"  << endl;
      }
    system("pause");
    return 0;
}
