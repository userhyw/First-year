//*********************************************************
//File name	 : 0608
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main(void)
{
    int a[2][3] = {1,2,3,4,5,6};//两个矩阵的求和
    int b[2][3] = {1,2,3,4,5,6};
    int *p1 = NULL, *p2  = NULL;
    p1 = a[0];
    p2 = b[0];

    while(p1 < a[0] + 6 ){
        *p1 = *p1 + *p2;
        p1++;
        p2++;
    }
      p1  = a[0];
     while(p1 < a[0] + 6){
        cout << *p1 << setw(5);
        p1++;
    }

    system("pause");
    return 0;
}
