//*********************************************************
//File name	 : 0604
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>

using namespace std;

int main(void)
{
    char a[80];
    int flage1 = 0, flage2 = 0;
    char *p1 = NULL, *p2  = NULL, b = 0;

    cout << "������һ���ַ���" << endl;
    cin.getline(a, 80);
    b  =strlen(a);

    for(p1 = a; p1 < a + b ; p1++){
        if(*p1 >= 'a' && *p1 <= 'z'){
            flage1++;
        }
        else if(*p1 >= 'A' && *p1 <= 'Z'){
            flage2++;
        }
    }

      cout << "Сд��ĸ���ֵĴ���" << ":" << flage1 <<endl;
      cout << "��д��ĸ���ֵĴ���" << ":" << flage2 << endl;


    system("pause");
    return 0;
}
