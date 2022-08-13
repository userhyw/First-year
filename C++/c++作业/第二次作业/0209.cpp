//*********************************************************
//File name	 : 0209
//Author  	 : 贺洋
//Date   	 : 2021/10/18
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
    float a, b, c, h;
    int i;
    cout << "银行存款本金、存款年利率、存款年限，您将得到本金和利息总和（不计复利）" <<endl;

    cin >> a >> h >> b;
    i = 0;
    while(i<b)
    {
        a *= (1 + h);
        i ++;
    }
    cout << a <<endl;
    system("pause");

    return 0;
}
