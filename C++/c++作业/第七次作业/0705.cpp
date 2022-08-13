//*********************************************************
//File name	 : 0705
//Author  	 : he yang
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>

int Decimal(char *p);
//form Octal become Decimal
using namespace std;
int main(void)
{
    char a[20];
    int d;
    cout << "please enter Octal string and you will see its Decimal scale :" << endl;
    cin.getline(a, 20);
    d = Decimal(a);
    cout << "its Decimal scale is :" << d << endl;

    system("pause");
    return 0;
}
int Decimal(char *p)
{
    int n = 0;
    while (*p){
        n = n * 8 + *p - '0' ;
        p++;
    }
    return n;
}
