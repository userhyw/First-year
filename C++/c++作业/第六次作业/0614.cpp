//*********************************************************
//File name	 : 0614
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>
//求二维数组平均值
using namespace std;

int main(void)
{
    int a[2][3] = {1,3,7,4,5,6};
    int *p1= NULL;
    int  **p2 = NULL;
    float s = 0;
     p1 = a[0];
    p2 = &p1;
   while(p1 < a[0] + 6){
   	s += **p2;
   	p1++;
   }

    cout << s/6.0 << endl;
    system("pause");
    return 0;
}
