//*********************************************************
//File name	 : 0507
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    int a[10], b, c=0, d=0;
    cout << "������ʮ��������������"  << endl;
    for(int i=0; i<10; i++)
    {
        cin >> a[i];
    }

    cout << "������һ�����ݽ��в���" <<endl;
    cin >> b ;

    for(int i=0; a[i]; i++)
    {
        if(a[i]==b)
        {
            c = i;
            d++;
        }
    }
    if(d)
    {
        cout << c << endl;
    }
    else
    {
        cout << "wrong" << endl;
    }

   system("pause");
    return 0;
}
