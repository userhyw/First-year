//*********************************************************
//File name	 : 0511
//Author  	 : heyang
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main(void)
{
    char a[80], b[80];
    char c[160];
    cout << "please put something one" << endl;
    cin.getline(a,80);
    cout << "please put something tow" << endl;
    cin.getline(b,80);
    int j = 0, i = 0;

    for(i = 0; a[i]; i++)
    {
        c[i] = a[i];
    }
    for(j = 0; b[j]; j++)
    {
        c[i+j] = b[j];
    }

   cout << "let we see" <<endl;
    for(int k = 0; c[k]; k++)
    {
        cout << c[k];
    }




    system("pause");
    return 0;
}
