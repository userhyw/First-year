//*********************************************************
//File name	 : 0315
//Author  	 :heyang
//Date   	 : 10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
int main(void)
{
    for(int i = 1;i <10;i++)
    {
        switch(i)
        {
        case 1 :
            cout << "    " << "*" << endl;
            break;
        case 2 :
            cout << "   " << "***" << endl;
            break;
        case 3 :
            cout << "  " <<"*****" << endl;
            break;
        case 4 :
            cout << " " <<"*******" << endl;
             break;
        case 5 :
            cout << "*********" << endl;
            break;
        case 6 :
            cout << " " <<"*******" << endl;
            break;
        case 7 :
            cout <<"  " << "*****" << endl;
            break;
        case 8 :
            cout << "   " <<"***" << endl;
            break;
        case 9 :
            cout << "    " <<"*" << endl;
            break;
        }

    }

    system("pause");
    return 0;
}
