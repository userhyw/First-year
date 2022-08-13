//*********************************************************
//File name	 : 0602
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
    int a[10];
    int *p1 = NULL , *p2 = NULL;
   p1 = a;
   
   for (p1 = a; p1 < a + 10; p1++){
   	cin >> *p1;
   }
     
     p1 = a;
    int d = 0, *c = NULL;
    d = *p1;
    c = a; 
   for(p1 = a; p1 < a +10 - 1 ; p1++){
     for(p2 = p1+1; p2 < a +10  ; p2++){
            if(*p2 > d){
               d = *p2;
               c = p2;
            }
        }
   }
cout << "max = " << d << endl;
cout << "pos = " << c-a <<endl;
    system("pause");
    return 0;
}
