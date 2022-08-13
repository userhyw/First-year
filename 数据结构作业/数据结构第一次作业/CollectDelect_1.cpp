#include <iostream>
#define MaxLenth 100
#define elementType int
using namespace std;
//2.7

struct sList
{

    sList()//初始化表的长度为0
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//定义表中数组
    int Lenth;//定义长度
};


int Delete(sList *a);

int main(void)
{
    sList a;

    cout << "请有序输入10个元素，将删除重复元素" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> a.date[i];
        a.Lenth++;
    }

    int Flage = Delete(&a);
    if (Flage == 1)
    {
        cout << "wrong!" << endl;
    }
    else
    {
        cout << "删除后的结果为：" << endl;
        cout << "移动次数为：" << Flage << endl;
        for (int i = 0; i < a.Lenth; i++)
        {
            cout << a.date[i] << " ";
        }
    }
}

//函数实现有序序列表删除重复元素
int Delete(sList *a)
{
    if (a->Lenth == 0)//空表就返回错误，停止运算
    {
        return 1;
    }

    int i = 0, j = 1, c = 0;

    //思路可以理解为，不重复的元素放到前面，然后把数组长度改变
    while (j < a->Lenth)
    {
        if (i == j || a->date[i] == a->date[j])//元素重复，或是下标相等导致元素相等
        {
            j++;//移动下标继续寻找不一样的元素
        }
        else
        {
            a->date[++i] = a->date[j];//把不重复的元素放到前面，同时移动下标
            c++;
        }
    }

    a->Lenth = i + 1;

    return c;

}




