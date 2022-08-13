//*********************************************************
//File name	 : 0503
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
    int j = 0, r = 0;//j记录奇数的个数，r记录偶数个数
    cout << "请输入十个整数" << endl;

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

    cout << "奇数的个数为 : " <<  j << endl;
    cout << "偶数的个数为 : " <<  r << endl;

    system("pause");
    return 0;
}
