#include <iostream>
#define ElementType int

using namespace std;

//创建结构体
 typedef struct Students
{
    ElementType date;
    Students *Next;

}Stu;

void Delete(Stu *p, int m_x);

int main(void)
{


}

//函数实现传入值，删除链表中对应结点
void Delete(Stu *p, int m_x)
{
    Stu *q = NULL;//建立一个临时指针，用于记录删除结点
    //默认有头结点
    if (p->Next == NULL)
    {
        cout << "你都没有数据你是要干哈？" << endl;
        return;
    }

    //因为这样不会改变头指针的地址，所以可以直接遍历
    while(p->Next != NULL)
    {
        if (p->Next->date == m_x)//当找到该元素时
        {
            q = p->Next;
            p->Next = p->Next->Next;
            delete q;//释放该节点，系统回收使用权
            q = NULL;//将该指针置于空
        }

        p = p->Next;
    }
    return;

}


//函数实现两个递增有序的链表，带头结点的并集，但是表示的是集合，所以没有相同元素 A = A U B
void AaddB(Stu *p, Stu *q)
{
        Stu *cur = p;//用于记录多余链表的头部位置
        p = p->Next;
        q = q->Next;


        if (p== NULL || q == NULL) return;

        while (p->Next && q->Next)//p->Next代表第一个结点
        {
            if (p->date > q->date)//B中元素小于A中
            {
                    q = q->Next;
            }
        else if (p->date < q->date)
            {

                    p = p->Next;
            }
            else
            {
                cur->date = p->date;
                cur = cur->Next;
                q = q->Next;
                p = p->Next;
            }

        }

        //循环结束后
        Stu *now = cur;//从now开始一个的都要删去
        Stu *de = NULL;
        cur->Next = NULL;
        while (now->Next)
        {
            de = now->Next;
            delete de;
            now = now->Next;
        }
        return;

}



















