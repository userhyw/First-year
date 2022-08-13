//*********************************************************
//File name	 : 0607
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
    char a[80], b[80], *p1 = NULL, *p2 = NULL;
    cout << "please put something down" << endl;
    cin.getline(a,80);

    p1 = a;
    p2 = b;
    while(*p1){
        *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0';
    cout << b << endl;

    system("pause");
    return 0;
}
