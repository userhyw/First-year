//*********************************************************
//File name	 :
//Author  	 :
//Date   	 :
//Student ID   :
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    int a, b;
    int s ;
    for(int i = 1;i<1001 ; i++)
    {
         s=0;
       for(int j = 1; j < i ;j++)
       {
           if(i%j==0)
           {
               s +=j;
            }

        }
       if(s==i)
        {
                cout << s << endl;
        }

    }

    system("pause");
    return 0;
}
