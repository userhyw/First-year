//*********************************************************
//File name	 :0304
//Author  	 :heyang 
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
   int a, b, c, m, M, k;
    cout << "请任意输出三个数据" << endl;
    cin >> a >> b >> c;
    if(a > b && a > c)
{
    M = a;
}
   if(b > a && b > c)
{
    M = b;
}
    if(c > b && c > a)
{
    M = c;
}
if(c < b && c < a)
{
    m = c;
}
if(b < c && b < a)
{
    m = b;
}
if(a < b && a < c)
{
    m = a;
}

 k = a + b + c - m - M; 


cout << m << endl;
cout << k << endl;
cout << M << endl;

system("pause");
return 0;


}
