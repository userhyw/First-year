//*********************************************************
//File name	 : 0511
//Author  	 : ����
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
   char a[80];
   char b[1];
   cout << "������һ���ַ�" << endl;
   cin.getline(a,80);
   cout << "��Ҫ���ҵĵ����ַ�" << endl;
   cin >> b[0];

   int flage = 0;//flage��Ϊ��¼���ݳ��ֵĴ���
   for(int i = 0; a[i]; i++)
   {
       if(a[i]==b[0])
       {
           flage++;
       }
   }
   cout << b[0] << " " << "���ֵĴ���Ϊ" << flage << endl;

   system("pause");
   return 0;
}
