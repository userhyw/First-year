//*********************************************************
//File name	 : 0702
//Author  	 : he yang
//Date   	 : 2021/11/27
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>

int howmany(char *p);
using namespace std;
int main(void)
{
    char a[80];
    int c;
    cout << "please put %s you should understand" << endl;
    cin.getline(a, 80);
    c = howmany(a);
    cout << "there have this figure :" << c << endl;

    system("pause");
    return 0;
}
int howmany(char *p)
{
    int flage = 0;
    while (*p){
        if (*p < '9' && *p > '0'){
            flage++;
        }
        p++;
    }
    return flage;

}
