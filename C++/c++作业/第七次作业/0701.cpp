//*********************************************************
//File name	 : 0701
//Author  	 : he yang
//Date   	 : 2021/11/27
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>
//最大公约数
int Max(int a, int b);
using namespace std;

int main(void)
{
    int a, b, c;
    cout << "please put two figures" << endl;
    cin >> a >> b;
    c = Max(a, b);
    cout << "the Max yue is :" << c << endl;



    system("pause");
    return 0;
}

int Max(int a, int b)
{
   int c, d, e, f;
   c = a > b ? a : b;
   d = a < b ? a : b;
   while (c%d!=0){
       e = c%d;
       c = d;
       d = e;

   }
   return d;
}
