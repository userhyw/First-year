//*********************************************************
//File name	 : 0404
//Author  	 :heyang
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>
//����һ��4��5�еĸ��������飬��������飬ͳ��ÿ�е�Ԫ��֮�ʹ�ŵ�һ��һά�����в������
using namespace std;
int main(void)
{
     double s;
     double a[4][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
     double b[4];
     for(int i = 0;i <4;i++)
     {   s = 0;
         for(int j  = 0; j < 5;j++)
         {
             s += a[i][j];

         }
         b[i] = s;

     }

        for(int i = 0; i < 4;i++)
        {
       cout << b[i] << setw(4);
        }


    system("pause");
    return 0;
}
