//*********************************************************
//File name	 : 08
//Author  	 :heyang 
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main()
{
	double x0, x, f, f1, c;
	cout << "������һ��x" << endl;
	cout << "���ǽ����㷽��x^3/3-6=0�ĸ�" << endl;
	cin >> x; 
	
	x0 = 0;
	for(int i = 1;i<100;i++)
	{
		f = x*x*x/3.-6;
	    f1 = x*x;
		x0 = x - f/f1;
		c = x0;
		x = c;	
		
	}
	
	cout << c << endl;
	
	
	
	
	
	
	
	
	system("pause");
	return 0;
}
