//*********************************************************
//File name	 : 0612
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

using namespace std;
//判断回文 
int main(void)
{
    char a[80], *p1 = NULL, *p2 = NULL;
    cout << "please put something dowm" << endl;
    cin.getline(a, 80);

    p1 = a;
    while(*p1){
        p1++;
    }
   p1--;
    p2 = a;
    while(p1 > p2){
        if( (int)*p1 != (int)*p2){
            break;
        }
        p2++;
        p1--;
    }

    if(p2 >= p1){
        cout << "这是回文" << endl;
    }
    else{
        cout << "这不是回文" << endl;
    }
    system("pause");
    return 0;
}
