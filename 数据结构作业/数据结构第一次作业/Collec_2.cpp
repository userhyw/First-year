#include <iostream>

#define MaxLenth 100
#define elementType int
//2.3

using namespace std;

struct sList
{
    sList()
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//定义表中数组
    int Lenth;//定义长度
};


void AddList(sList *a, sList *b, sList *c);
void InsterSection(sList *a, sList *b, sList *c);
void DifferenceSet(sList *a, sList *b, sList *c);

int main(void)
{
    sList a, b, c;



    cout << "请输入10个元素到a中: " <<endl;
    for (int i = 0; i < 10; i++){
        cin >> a.date[i];
        a.Lenth++;
    }

    cout << "请输入10个元素到b中: " <<endl;
    for (int i = 0; i < 10; i++){
        cin >> b.date[i];
        b.Lenth++;
    }

//    AddList(&a, &b, &c);
//
//    cout << "元素并集如下：" << endl;
//    for (int i = 0; i < c.Lenth; i++)
//    {
//        cout << c.date[i] << " ";
//    }

//    InsterSection(&a, &b, &c);
//
//        cout << "元素交集如下：" << endl;
//        for (int i = 0; i < c.Lenth; i++)
//    {
//        cout << c.date[i] << " ";
//    }


    DifferenceSet(&a, &b, &c);

        cout << "元素交集如下：" << endl;
        for (int i = 0; i < c.Lenth; i++)
    {
        cout << c.date[i] << " ";
    }

}

//函数实现两个集合的并
//实现并，将元素存到C数组中
void AddList(sList *a, sList *b, sList *c)
{
    bool Flage = true;//判断元素是否相同标志
    *c = *b;//先把b中元素加到c中

    for (int i = 0; i < a->Lenth; i++)
    {
        for (int j = 0; j < b->Lenth; j++)
        {
            if (a->date[i] == b->date[j])
            {
                Flage = false;//出现相同元素直接跳出循环
                break;
            }
        }

        if (Flage)
        {
             //找到一个不是相同元素的，直接加入到C中
            c->date[c->Lenth] = a->date[i];
            c->Lenth++;
        }
        else
        {
            Flage = true;//元素相同，继续遍历
        }

    }

}

//函数实现两个集合的交集
void InsterSection(sList *a, sList *b, sList *c)
{

    for (int i = 0; i < a->Lenth; i++)
    {
        for (int j = 0; j < b->Lenth; j++)
        {
            if (a->date[i] == b->date[j])//出现相同元素，则加入到c集合中
            {
                c->date[c->Lenth] = a->date[i];
                c->Lenth++;
                break;
            }
        }
    }
}


//函数实现两个集合的差集
//为集合 a - b 的结果
void DifferenceSet(sList *a, sList *b, sList *c)
{

    bool Flage = true;

        for (int i = 0; i < a->Lenth; i++)
    {

        for (int j = 0; j < b->Lenth; j++)
        {
            if (a->date[i] == b->date[j])//出现相同元素
            {
                Flage = false;//做好记号
                break;//跳出循环
            }
        }

        if (Flage)//非相同元
        {
            c->date[c->Lenth] = a->date[i];//加入到集合c中
            c->Lenth++;
        }
        else
        {
            Flage = true;//出现相同元素直接跳过，继续遍历
        }

    }
}





