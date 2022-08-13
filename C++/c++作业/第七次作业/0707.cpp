//*********************************************************
//File name	 : 0707
//Author  	 : he yang
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#define n 4

void turnback(int (*p)[n], int n1);

using namespace std;
int main(void)
{
    int N;
    cout << "请输入您的阶数" << endl;
    cin >> N;
    int a[N][4];
    cout << "请输入该矩阵的元素" << endl;
    for (int i = 0; i < 4 ; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }
    turnback(a, N);
   cout << "转置后的矩阵如下 ：" << endl;
    for (int i = 0; i < 4 ; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
void turnback(int (*p)[n], int n1)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = i; j < n1; j++)
        {
            int d  = *(*(p + i) + j);
            *(*(p + i) + j) = *(*(p + j) + i);
            *(*(p + j) + i )= d;
        }
    }
    return ;
}
