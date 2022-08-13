#include <iostream>
#define MaxLenth 100
#define elementType int

using namespace std;

//2.9
struct sList
{

    sList()//初始化表的长度为0
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//定义表中数组
    int Lenth;//定义长度
};

void DifSet(sList *a, sList *b);
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

    DifSet(&A, &B);

    cout << "A - B的结果为：" << endl;
    for (int i = 0; i < A.Lenth; i++)
    {
        cout << A.date[i] << " ";
    }

}

//函数实现递增有序集合的差集 A = A - B
void DifSet(sList *a, sList *b)
{
    int i = 0, j = 0, k = 0;//k作为“新数组”的长度控制
    b->date[10] = -1;

    //故，A集合必须遍历完全
    while (i < a->Lenth)//A中元素较小可以遍历完A就结束，但是A较大时，会出现B遍历完了，A后面的元素无法获取
    {
            if (a->date[i] > b->date[j] && j < b->Lenth - 1)//当A中元素大于B中元素, 且B集合没有遍历完
            {
                j++;//当B集合遍历完之和，防止数组下标越界！
            }
            else if (a->date[i] < b->date[j]|| j == b->Lenth - 1) //后半部分条件情况属于，B中所有元素都小于A了
            {
                a->date[k] = a->date[i];
                i++;
                k++;
            }
            else if (a->date[i] == b->date[j])
            {
                j++;
                i++;
            }
    }

    a->Lenth = k;
}












