//*********************************************************
//File name	 : 0708
//Author  	 : he yang
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#define N1 4
//judge this matrix is or not symmetrical

using namespace std;
bool cctv( int (*p)[N1], int n );

int main(void)
{

    int N2;
    cout << "please enter your number of rows and columns" << endl;
    cin  >> N2;
    int a[N2][N1];
    cout << "please enter your figures :" << endl;
    for (int i = 0; i < N2; i++)
    {
        for (int j  = 0; j < N1; j++)
        {
            cin >> a[i][j];
        }
    }

    bool k =  cctv(a,N2);
    if (k==true)
    {
        cout << "this is symmetrical" << endl;
    }
    else
    {
        cout << "this is not symmetrical" << endl;
    }


    system("pause");
    return 0;
}

bool cctv( int (*p)[N1],int n )
{
    bool k  = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < N1; j++)
        {
            int c = *(*(p + i) + j);
            int d = *(*(p + j) + i);
            if (c != d)
            {
                k = false;
                break;
            }
        }
    }

    return k;
}
