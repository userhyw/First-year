#include <iostream>
#define MaxLenth 100
#define elementType int

using namespace std;

//2.8
struct sList
{

    sList()//初始化表的长度为0
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//定义表中数组
    int Lenth;//定义长度
};


void AddTwo(sList *a, sList *b);

int main(void)
{
    sList A, B;

    cout << "请输入A的10个有序递增整数，不得出现重复元素："<< endl;
   for (int i = 0; i < 10; i++){
        cin >> A.date[i];
        A.Lenth++;
    }

    cout << "请输入B的10个有序递增整数，不得出现重复元素："<< endl;
    for (int i = 0; i < 10; i++){
            cin >> B.date[i];
            B.Lenth++;
    }

    AddTwo(&A, &B);

    cout << "A与B取交级后" << endl;
    for (int i = 0; i < A.Lenth; i++)
    {
        cout << A.date[i] << " ";
    }

}

//函数实现两个递增有序表表示集合A,B。求A = A交B;
void AddTwo(sList *a, sList *b)
{
    int i = 0, j = 0, k = 0;//K作为“新数组”的长度计量单位

    //默认得到结果的A，任然是递增有序数列
    while (j < b->Lenth && i < a->Lenth)//因为“新数组”的长度我们可以得出，此处主要考虑如何退出循环
    {
        //A, B中遍历到的元素不相等时，分情况来对待
        if (a->date[i] > b->date[j])
        {
            //当A中该元素大于B中该元素时，B的后面可能有等于A中该元素的
            j++;
        }
        else if (a->date[i] < b->date[j])
        {
            //当A中元素，小于B此时元素时，A往后遍历可能出现与B的该元素相等
            i++;
        }
         else if (a->date[i] == b->date[j])  //若A, B中出现相同元素
            {
                a->date[k] = a->date[i];//可以理解为新数组慢慢变长
                k++;//长度 + 1
                i++;//A往后遍历
                j++;//B往后遍历
            }
    }

    a->Lenth = k;//确定新数组的长度

}








