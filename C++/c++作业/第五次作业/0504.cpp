//*********************************************************
//File name	 : 0504
//Author  	 : 贺洋
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************#include<iostream>
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
	cout << "输入一串英文字符，将大小写转换" << endl; 
    char a[80];
    cin.getline(a,80);

    for(int i=0; a[i]; i++)
    {
        if(a[i]>='A' && a[i]<='Z')
        {
            a[i] += 32;
        }
     else if(a[i]>='a' && a[i]<='z')
        {
            a[i] -= 32;
        }

    }
    for(int i=0; a[i]; i++)
    {
        cout << a[i];
    }

    system("pause");
    return 0;
}
