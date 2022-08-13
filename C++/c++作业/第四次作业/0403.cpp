//*********************************************************
//File name	 : 0403
//Author  	 :heyang
//Date   	 : 10.31
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>
//定义一个有10个元素的数组，用其代表10个学生的考试成绩，从键盘输入10个成绩，统计平均成绩，输出高于平均成绩的序号。
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
