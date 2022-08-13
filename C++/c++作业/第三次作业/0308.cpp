//*********************************************************
//File name	 :0308
//Author  	 :heyang 
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    float a, b, c, d;//代表听说读写
    int s;//代表总成绩
    cout << "请分别输入您的听.说.读.写.成绩" <<endl;
    cin >> a >> b >> c >> d;
    if(a >= 5 && b >= 5 && c >= 5 && d >=5)
    {
        s = (a + b + c + d)/4;
        if(s >= 6)
        {
            cout << "恭喜您的雅思成绩合格了" <<endl;
        }
        else
        {
            cout << "您的雅思考试没有合格" <<endl;
        }
    }
    else
    {
        cout << "您的雅思成绩没有合格" << endl;
    }

    system("pause");
    return 0;
}
