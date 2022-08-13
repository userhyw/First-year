//*********************************************************
//File name	 : 0610
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
    int a[4][4];
    cout << "请为这个4*4的矩阵输入16个值" << endl; 
    for (int i = 0; i < 4; i++){
    	for (int j = 0; j < 4; j++){
    		cin >> a[i][j];
		}
	}
    int  *p1[4] = {a[0],a[1],a[2],a[3]}, *p2 = NULL;//q用于调试
    int **p3 = NULL;

    p2 = a[0];
    p3 = p1;

    do{
        int c = **p3;
        **p3 = *p2;
        *p2 = c;
        p3++;
        p2++;
    }while(p2 < a[0] + 3);
   int b  = **p3;
   **p3 = *p2;
   *p2 = b;

  p2 += 2;
  p3 = p1 + 1;
 do{
        int c = *(*p3 + 1);
        *(*p3 + 1)  =  *p2 ;
            *p2 = c;
        p3++;
        p2++;
    }while(p2 < a[1] + 3);
  int d = *(*p3 + 1);
        *(*p3 + 1) = *p2;
        *p2 = d;

  p2 += 3;
  p3 = p1 + 2;
 do{
        int c = *(*p3 + 2);
        *p2 = *(*p3 + 2);
        *(*p3 +  2)= c;
        p3++;
        p2++;
    }while(p2 < a[2] + 3);
  int e = *(*p3 + 2);
       *(*p3 + 2) = *p2;
        *p2 = e;
     int (*q)[4] ;
     int *w;
    for (q = a; q < a + 4; q++){
    	for (w = (int * ) q; w < (int * ) q + 4; w++){
    		cout << *w << "  " ;
		}
		cout << endl;
	} 
    system("pause");
    return 0;
}
