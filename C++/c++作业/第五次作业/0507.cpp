//*********************************************************
//File name	 : 0507
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;
int main(void)
{
    float a[10];
    cout << "������10������������" << endl;


    for(int i = 0;i<10; i++)
    {
        cin >>a[i];
    }

         for(int j = 9; j>=0; j--)
        {
          cout << setw(5) << a[j] ;
        }




    system("pause");
    return 0;
}
