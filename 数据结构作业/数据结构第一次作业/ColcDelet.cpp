#include <iostream>
#define MaxLenth 100
#define elementType int

using namespace std;

//2.6
struct sList
{

    sList()//初始化表的长度为0
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//定义表中数组
    int Lenth;//定义长度
};

bool Delete(sList *a);

int main(void)
{

  sList a;

  cout << "请输入10个任意整数，重复元素将会被删除"<< endl;
  for (int i = 0; i < 10; i++){
    cin >> a.date[i];
    a.Lenth++;
  }

  bool Flage = Delete(&a);
  if (!Flage)
  {
      cout << "wrong!" << endl;
  }
  else
  {
      cout << "删除重复元素后：" << endl;
      for (int i = 0; i < a.Lenth; i++)
      {
          cout << a.date[i] << " ";
      }
  }

}

//函数实现删除顺序表重复元素
bool Delete(sList *a)
{
    //判断是否是空表,或是只有一个元素
    if (a->Lenth < 2)
    {
        return false;//是空表返回false
    }

//    //如果不是空表，进行元素比对，删改
//    for (int i = 0; i < a->Lenth - 1; i++)
//    {
//        for (int j = i + 1; j < a->Lenth; j++)
//        {
//            if (a->date[i] == a->date[j])//发现重复元素
//            {
//                for (int k = j; k < a->Lenth - 1; k++)
//                {
//                    a->date[k] = a->date[k + 1];//后面元素向前移动覆盖
//                }
//                a->Lenth--;//数组长度减1
//                i--;//注意，一次只删除了一个重复的元素，不能确保后面是否还有重复元素，所有每一次对比都要遍历完全
//            }
//        }
//    }

    int i = 1, c = 1;//后面用到，相当于是作添加的方法
    bool Flage = true;//作为标记

    //可以理解为，将不同的元素一次次添加到一个数组中
    //每一次添加之前都要和添加的元素比较
    //和之前的元素均不重复，则将其添加到其中
    while (i < a->Lenth)//外层大循环，保证每一次都是一个元素和所有元素的对比
    {
        for(int j = 0; j < c; j++)//内层循环，可以理解为逐渐将元素添加到一个新的数组中
        {
            if (a->date[i] == a->date[j])//判断这个进入循环的这个元素是否在这个“新数组”中
            {
                Flage = false;//标记后，下方判断
            }
        }

        if (Flage)//若该元素不在此“新数组”中
        {
            a->date[c] = a->date[i];//则添加到其中来
            c++;//且增加该“新数组”长度
        }
        else
        {
            Flage = true;//若是重复，则继续遍历循环
        }

        i++;
    }

    a->Lenth = c;//转换思维，不是把数组集体前移后再改变数组的长度
    //可以把不要的数覆盖，多余的数用改变下标的方式来删除掉

    return true;

}






