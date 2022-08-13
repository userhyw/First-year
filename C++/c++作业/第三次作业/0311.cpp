//*********************************************************
//File name	 : 0311
//Author  	 :heyang
//Date   	 : 10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int main(void)
{
    for(int i = 32 ;i <=127;i++)
    {
        cout << i << "=" << char(i) << setw(4);
    }

    system("pause");
    return 0;
}
