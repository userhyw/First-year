//*********************************************************
//File name	 : 0502
//Author  	 : 贺洋
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    int a[10], q=0, w=0, e=0, r=0, t=0;
    cout << "请输入十个成绩 (每科成绩满分为100) " << endl;
    for(int i  = 0;i<10;i++)
    {
        cin >> a [i];
    }

    for(int i = 0;i<10;i++)
    {
        if(a[i]>= 90)
        {
            q++;
        }
    else if(a[i]>= 80)
        {
            w++;
        }
    else if(a[i]>= 70)
        {
            e++;
        }
 else if(a[i]>= 60)
        {
            r++;
        }
   else{
    t++;
   }

    }

   cout << "优 ：" <<  q << endl;
   cout << "良 ：" <<  w << endl;
   cout << "中 ：" <<  e << endl;
   cout << "及格 ：" <<  r << endl;
   cout << "不及格 ：" <<  t << endl;
    system("pause");
    return 0;
}
