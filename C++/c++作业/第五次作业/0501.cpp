//*********************************************************
//File name	 : 0501
//Author  	 : 贺洋
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>


using namespace std;
int main(void)
{
    int a[10];
     int c  ;//当作最大值来处理
     int address = 0;
    cout << "请输入十个整形数" << endl;
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
