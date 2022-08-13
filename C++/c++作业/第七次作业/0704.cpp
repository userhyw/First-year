//*********************************************************
//File name	 : 0704
//Author  	 : he yang
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>

bool ijudge(int a);

using namespace std;
int main(void)
{
    int a;
    cout << "please put one figures we will judge Prime number" << endl;
    cin >> a;
    cout << ijudge(a) << endl;


    system("pause");
    return 0;
}
bool ijudge(int a)
{
    int flage = 0;
    if (a == 2)
    {
        flage == 0;
    }
    else if (a != 2){
    for (int i = 2; i < a; i++)
    {
        if (a%i==0)
        {
            flage++;
        }
    }
    }
    bool k  = true;
        if (flage == 0)
        {
            for (int i = 101; i < 200; i  = i + 2)
            {
                k = true;
                for (int j  = 3; j < i / 2; j = j + 2)
                {
                    if (i%j == 0)
                    {
                        k = false;
                    }
                }
                if (k )
                {
                    cout << i << "  ";
                }
            }
        cout << endl;
        }


    return flage ==0 ? true : false ;

}
