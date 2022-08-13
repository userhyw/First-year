//*********************************************************
//File name	 : 0504
//Author  	 : heyang
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;
int main(void)
{
	cout << "由键盘任意输入10个整形数据，将其按升序排序后输出（用冒泡排序）" << endl;
    int a[10] ;
    int z = 0; //z用于替换
    cout << "请输入10个数字" << endl;

     for(int i = 0;i<10;i++)
     {
         cin >> a[i];
     }
   // cout << a[10];
      z = a[0];
    for(int i = 0;i<9;i++)
    {
      for(int j = i + 1;j<10;j++)
      {
	    if(a[i]>a[j])
        {
            z = a[i];
            a[i] = a[j];
            a[j] = z;
        }
      }
    }

for(int i = 0;i<10;i++)
{
    cout << a[i] << endl;
}

    system("pause");
    return 0;
}
