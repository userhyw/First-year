#include <iostream>

#define MaxLenth 100
#define elementType int

using namespace std;

struct sList
{
//    sList()
//    {
//        Lenth = 0;
//    }

    elementType date[MaxLenth];//定义表中数组
    int Lenth;//定义长度
};


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

}

//函数实现两个集合的并
void AddList(sList *a, sList *b, sList *c)
{
    bool Flage = true;
    c->Lenth = 0;

    for (int i = 0; i < a->Lenth; i++)
    {
        for (int j = 0; j < b->Lenth; b++)
        {
            if (a->date[i] == b->date[j])
            {
                Flage = false;
                break;
            }
        }

        if (Flage)
        {
            c->date[k] =
        }

    }




}






