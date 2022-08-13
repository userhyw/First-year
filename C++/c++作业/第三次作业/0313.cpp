//*********************************************************
//File name	 :0313
//Author  	 :heyang
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int main(void)
{
    long double e, n;
    e = 1;
    int j = 1;
    cout << "ÇëÊäÈën = "; 
    cin >> n;
    for(int i = 1;i < n; i++)
    {
        j *= i;
        e +=1./j;
    }
    cout <<  setprecision(7) << e <<endl;

    system("pause");
    return 0;
}
