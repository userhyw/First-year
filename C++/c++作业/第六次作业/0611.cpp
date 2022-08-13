//*********************************************************
//File name	 : 0611
//Author  	 : he yang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main(void)
{
    char  b ,a[80], *p1 = NULL, *p2 = NULL;
    cout << "please put spmething dowm" << endl;
    cin.getline(a, 80);
    int Ipos = 0;
    cout << "please input a char" << endl;
    cin >> b;

    p1 = a;
    while(*p1){
        if(*p1 == b){
        	p2 = p1;
            Ipos++;
             while(*p1){
                *p1 = *(p1 + 1);
                 p1++;
            }
            p1 = p2;
        }
        p1++;
}

    if (Ipos == 0){
        cout << "sorry , no this abc" << endl;
    }
    else{
    cout << a;
    }
    system("pause");
    return 0;
}
