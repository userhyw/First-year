//*********************************************************
//File name	 : 0609
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main(void)
{   //µ¹ÐòÊä³ö×Ö·û´®
    char a[80], *p1 = NULL, *p2 = NULL;
    cout << "please input %s" << endl;
    cin.getline(a,80);

    p1 = a;
    while(*p1){
        p1++;
    }
    p1  = p1 - 1;
    while(p1 >= a){
        cout << *p1 ;
        p1--;
    }

    system("pause");
    return 0;
}
