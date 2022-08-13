//*********************************************************
//File name	 : 0703
//Author  	 : he yang
//Date   	 : 2021/11/27
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>
void isort(int *p, int n);
//ÅÅÐòÊý×é
using namespace std;
int main(void)
{
    int a[10];
    cout << "please put ten figures" << endl;
    for (int i = 0; i < 10; i++){
        cin >> a[i];
    }
    isort(a, 10);
    cout << "sort as follows  :" << endl;
    for (int i = 0; i < 10;  i++){
        cout << a[i] << " ";
    }

    system("pause");
    return 0;
}
void isort(int *p, int n)
{
   int *q,  b,  d,  *p1;
   q = p + n;
   for (; p < q - 1; p++){
        d = *p;
     for (p1 = p + 1; p1 < q; p1++){
        if (*p1 > d){
            d = *p1;
            *p1 = *p;
            *p= d;
        }
     }
   }
  return ;
}
