//*********************************************************
//File name	 : 0501
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
     int c  ;//�������ֵ������
     int address = 0;
    cout << "������ʮ��������" << endl;
    for(int i = 0;i<10;i++)
  {
      cin >> a[i];
  }
       c = a[0];
    //   a[10] = '\0';
     for(int i = 1; i < 10; i++)
     {
         if(a[i]>=c)
         {
             c = a [i];
             if(a[i]  = c)
                {
                    address = i;
                }
         }

     }
        cout <<  c << endl ;
        cout << address << endl;;

}
