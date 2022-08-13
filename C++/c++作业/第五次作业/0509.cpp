//*********************************************************
//File name	 : 0509
//Author  	 : 贺洋
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
    cout << "请有序的输入10个数据" << endl;
    for(int i=0; i<10; i++)
    {
        cin >> a[i];
    }

    cout << "请输入您要查找的数据" << endl;
    cin >> b;
 //b是输入的查找数据
     do{
        mid = (top + bot)/2;
        if(b == a[mid])
        {
            cout << b << "的位置在" << mid << endl;
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
     cout << "查无此数" << endl;
 }

    system("pause");
    return 0;
}
