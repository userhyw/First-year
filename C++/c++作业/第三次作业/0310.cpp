//*********************************************************
//File name	 : 0310
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
    double PI,PI2,n;
      PI = 1;
      n = 1;
    for(int i = 2 ;i < 1000;i++)
    {
        n = (-1.)*n;
        PI += n/(2*i-1);
    }

    PI2 = 4.0f*PI;
    cout << setprecision(10) <<PI2 << endl;









    system("pause");
    return 0;
}
