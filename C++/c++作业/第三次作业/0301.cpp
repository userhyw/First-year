//*********************************************************
//File name	 :0301		
//Author  	 :heyang 
//Date   	 :10.27
//Student ID   :2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
     double a, b;
    cout << "����������ȫ���" << endl;
    cin >> a;
    if (a < 36000)
    {
        b = a * 0.03f;
        cout << "��Ӧ�ý�˰: " << b << endl;
    }
    else if (a < 144000)
    {
        b =  a  * 0.1f - 2520;
        cout << "��Ӧ�ý�˰: " << b << endl;
    }
 else if (a < 300000)
    {
        b =  a*0.2f - 16920;
        cout << "��Ӧ�ý�˰: " << b << endl;
    }

 else if (a < 420000)
    {
        b = a *0.25f -31920;
        cout << "��Ӧ�ý�˰: " << b << endl;
    }
    else if (a < 660000)
    {
        b = a *0.3f -52920;
        cout << "��Ӧ�ý�˰: " << b << endl;
    }
    else if (a < 960000)
    {
        b = a *0.35f -85920;
        cout << "��Ӧ�ý�˰: " << b << endl;
    }
    else if (a > 960000)
    {
        b = a *0.45f -181920.;
        cout << "��Ӧ�ý�˰: " << b << endl;
    }



    system("pause");
    return 0;
}
