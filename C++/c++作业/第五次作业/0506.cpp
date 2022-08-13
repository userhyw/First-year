//*********************************************************
//File name	 : 0504
//Author  	 : heyang
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;
int main(void)
{
	float a[10];
	cout << "请输入十个浮点型数据" << endl;

	for(int l = 0;l < 10;l++)
	{
		cin >> a[l];
	}

	int c  = 0;
	float b = 0;
	for(int i = 0;i < 9;i++)
	{
        c = i;

		for(int j = i + 1;j < 10;j++)
		{
			if(a[j] > a[i])
			{
				c = j;
			}
		}
		if(c != i)
		{
		   b = a[c];
		   a[c] = a[i];
		   a[i] = b;
		}
	}

	for(int k = 0; k < 10; k++)
	{
		cout  << setw(5) << a[k] ;
	}


	system("pause");
	return 0;
}
