//*********************************************************
//File name	 : 13
//Author  	 :heyang 
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{ 
    int a[100];
    int k;
    int h = 0, c;
	for(int n = 2;n < 100;n++)	
 {
	
    k = 41 + n*(n-1);
	for(int i = 2;i<=k/2;i++)
	{
		if(k%i==0)
		{   
		    c = n;
		    a[h] = c;
		    h++;
		}
		
	}
	
 }
    cout << a[0] << endl;
	system("pause");
	return 0;
}



