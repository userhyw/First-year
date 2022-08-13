//*********************************************************
//File name	 : 31
//Author  	 :heyang
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<cmath> 
#include<iomanip>
using namespace std;
int main(void)
{     
	for(int q = 2;q<21;q++)
	{     int e;
	        e = pow(2,q)-1 ;
		for(int w = 2;w<=e;w++)
		{ 
			if((e%w)==0 && (e!=w))
			{
				break; 
			}
		  
		   if(e==w) 
			{    
				cout << e << endl;
			}
		}
			
	}
	
	system("pause");
	return 0;
}
