//*********************************************************
//File name	 :0309
//Author  	 :heyang 
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{    int k = 3, j=3, s1=0, s2=0, s3=0;//sÎªºÍ
    for (int i = 3;i <= 10000;i++)
    {
      if(i%3==0)
      {
          s1 +=i;
      }
      
    }
    cout << s1 << endl;

    while(j<=10000)
    {
    	if(j%3==0)
    	{
		s2 +=j;
	    }
    	j++;	   	
	}
	cout << s2 << endl;
	
	do{
		if(k%3==0)
		{
			s3 +=k;
		}
		k++;
	}
	while(k<10000);
	
	cout << s3 <<endl;
	

system("pause");
    return 0;
}

