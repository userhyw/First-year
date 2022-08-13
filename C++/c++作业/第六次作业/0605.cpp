//*********************************************************
//File name	 : 0605
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
    string  a[10] = {"zhangfei","libai","wanglong","liyang","huhu","yabngyang","baiabi","lihua","niuwa","zhangailing"};
    string *p1 = NULL, *p2 = NULL;


    for(p1 = a; p1 < a + 10 -1; p1++){
        for(p2 = p1 + 1; p2 <  a + 10; p2++){
            if(*p1 > *p2){
                string d ;
                d = *p2;
                *p2  = *p1;
                *p1  = d;
            }
        }
    }

   for(p1 = a; p1 < a +10; p1++){
        cout << *p1 <<endl;
    }

    system("pause");
    return 0;
}
