//*********************************************************
//File name	 :0306
//Author  	 :heyang 
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    float a;
    int b, c;
    cout << "机票价格、订票时间、订票数量" << endl;
    cin >> a >> b >> c;
    if(c>20 && (b==4||b==5||b==9||b==10))
    {
        a *=  0.8f * c;
        cout << a <<endl;
    }
    else if(c<20 && (b==4||b==5||b==9||b==10))
    {
        a *= 0.9f * c;
        cout << a << endl;
    }
    else
    {
        if(c>20)
        {
            a *=0.6f * c;
            cout << a << endl;
        }
        if(c<20)
        {
            a *=0.8f * c;
            cout << a << endl;
        }
    }

    system("pause");
    return 0 ;
}
