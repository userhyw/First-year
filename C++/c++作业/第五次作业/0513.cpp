//*********************************************************
//File name	 : 0511
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    char a[80];
    char b[1];
    int n ;
    int c = 1, d = 0;

    cout << "������һ���ַ�" << endl;
    cin.getline(a,80);
    cout << "������Ҫ����ĵ��ַ�����λ��" << endl;
    cin >> b[0] >> n;

    for(int i = n; a[i]; i++)
    {
      a[n+d] = a[n+c];
      c++;
      d++;
    }
    a[n] = b[0];

    for(int i = 0; a[i]; i++)
    {
        cout << a[i];
    }
    system("pause");
    return 0;
}
