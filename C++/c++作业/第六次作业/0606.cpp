//*********************************************************
//File name	 : 0606
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>

using namespace std;

int main(void)
{
     char a[80], b[80],  *p1 = NULL, *p2 = NULL;
     cout << "ÇëÊäÈëÁ½´®×Ö·û" << endl;
     cin.getline(a,80);
     cin.getline(b,80);

     p1 = a;
     while(*p1){
        p1++;
     }

    p2 = b;
    while(*p2){
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    cout << a << endl;
    system("pause");
    return 0;
}
