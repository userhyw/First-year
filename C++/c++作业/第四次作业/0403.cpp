//*********************************************************
//File name	 : 0403
//Author  	 :heyang
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>
//����һ����10��Ԫ�ص����飬�������10��ѧ���Ŀ��Գɼ����Ӽ�������10���ɼ���ͳ��ƽ���ɼ����������ƽ���ɼ�����š�
using namespace std;
int main(void)
{
  int cj[10];
  double s1, s2;

  for(int i = 0;i<10 ; i++)
  {
      cin >> cj[i];

  }
 for(int i = 0;i<10 ; i++)
  {
      s1 += cj[i];
  }
s2 = s1/10;
for(int i = 0;i<10 ; i++)
  {
      if(cj[i] > s2)
      {
        cout << setw(4) << i;
      }

  }

    system("pause");
    return 0;
}
