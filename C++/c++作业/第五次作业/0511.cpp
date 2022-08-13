//*********************************************************
//File name	 : 0511
//Author  	 : 贺洋
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
   cout << "请输入一串字符" << endl;
   cin.getline(a,80);
   cout << "您要查找的单个字符" << endl;
   cin >> b[0];

   int flage = 0;//flage作为记录数据出现的次数
   for(int i = 0; a[i]; i++)
   {
       if(a[i]==b[0])
       {
           flage++;
       }
   }
   cout << b[0] << " " << "出现的次数为" << flage << endl;

   system("pause");
   return 0;
}
