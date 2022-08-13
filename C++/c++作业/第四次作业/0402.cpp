//*********************************************************
//File name	 : 0402
//Author  	 : 贺洋
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;
int main(void)
{
    char a1[27], a2[27];
    int flag1 = 0, flag2 = 0, flag3 = 0;
    cout << "输入一个十进制字符" << endl;
    cin.getline(a1,27);

     if(a1[0]=='+')
     {
         strcpy(a2,a1+1);
         for(int i=0; a2[i];i++)
         {
             if(a2[i]>='0' && a2[i]<='9')
             {

             }
             else
             {
                 flag1++;
             }
         }
if(flag1==0)
{
    for(int j= 0; a2[j]; j++)
    {
        cout << a2[j];
    }
}
else
{
    cout << "wrong" << endl;

}
return 0;
     }
if(a1[0]=='-')
     {
         for(int i=1; a1[i];i++)
         {
             if(a1[i]>='0' && a1[i]<='9')
             {

             }
             else
             {
                 flag2++;
             }
         }
if(flag2==0)
{
    for(int j= 0; a1[j]; j++)
    {
        cout << a1[j];
    }
}
else
{
    cout << "wrong" << endl;
}
    return 0;
     }

for(int i=0; a1[i];i++)
         {
             if(a1[i]>='0' && a1[i]<='9')
             {

             }
             else
             {
                 flag3++;
             }
         }
if(flag3==0)
{
    for(int j= 0; a1[j]; j++)
    {
        cout << a1[j];
    }
}
else
{
    cout << "wrong" << endl;
}


    system("pause");
    return 0;
}
