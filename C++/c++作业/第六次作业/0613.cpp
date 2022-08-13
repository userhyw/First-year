//*********************************************************
//File name	 : 0613
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int main(void)
{
     char a[20];
     int b[20];
     char *p1 = NULL;
     int *p2 = NULL, flage = 0;
     cout << "请输入4位16进制的数" << endl;
     cin.getline(a,20);

    p1 = a;
    p2 = b;
    p1 = a + 3;
    while (*p1){
        if(*p1 >= 'A' && *p1 <= 'F'){
             int c = *p1 - 55;
             while (c > 0){
                int d = c%2;
                *p2 = d;
                c /= 2;
                p2++;
             }
        }
            else if(*p1 >= 'a' && *p1 <= 'f'){
             int c = *p1 - 87;
             while (c > 0){
                int d = c%2;
                *p2 = d;
                c /= 2;
                p2++;
             }
             }
             else if(*p1 >= '0' && *p1 <= '9'){
             int c = *p1 - 48;
              flage = 0;
             while (c >= 1){
                int d = c%2;
                *p2 = d;
                p2++;
                c /= 2;
                flage++;
             }
             while (flage < 4){
                *p2 = 0;
                 p2++;
                 flage++;
             }
        }
    p1--;
    }

  p2--;
  while(p2 >= b){
    cout << *p2 ;
    p2--;
  }

    system("pause");
    return 0;
}
