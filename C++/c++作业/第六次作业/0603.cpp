//*********************************************************
//File name	 : 0603
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main(void)
{
      int a[10];
      int *p1 = NULL, *p2 = NULL;
      cout << "please put ten math :" << endl;
	  for (p1 = a; p1 < a + 10; p1++){
	  	cin >> *p1;
	  } 
       
      p1 = a;
      for(p1 = a; p1 < a+ 10 -1; p1++){
        for(p2 = p1 + 1; p2 < a +10; p2++){
            if(*p2 > *p1){
                int c = *p2;
                *p2 =  *p1;
                *p1 = c;
            }
        }
      }

      cout << "将一组数据排序如下" << endl;
    for(p1 = a; p1 <a + 10; p1++){
        cout << *p1 << setw(5);
    }







    system("pause");
    return 0;
}
