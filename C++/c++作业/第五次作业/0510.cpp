//*********************************************************
//File name	 : 0509
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main(void)
{
    char a[80];
    int mid = 0, top = 0, L, bot = 0, falge2 = 0;
     bool flage = 1;
    cout << "������һ���ַ���" << endl;
    cin.getline(a,80);

    L=strlen(a);
    int i = 0;
    do{

           if(a[i]==a[L-i-1])
           {

           }
           else
           {
               falge2++;
                flage = false;
           }


        i++;


    }while(flage && i <=L/2);

if(falge2==0)
{
    cout << "���ǻ���" << endl;
}
else
{
    cout << "�ⲻ�ǻ���" << endl;
}

    system("pause");
    return 0;
}
