#include <iostream>
#define NEWLINE cout << endl

using namespace std;

struct Stu
{
    int date;
    Stu *Next;
    Stu *Prior;
};

void beCome(Stu *&Head);
void pri(Stu *p);
bool IsRight(Stu *a);
bool TurnList(Stu *a);

int main(void)
{

    Stu *a;
    beCome(a);
    TurnList(a);
   pri(a);
   // bool c = IsRight(a);
   // cout << c << endl;

}

//函数实现逆置头结点双循环链表
bool TurnList(Stu *a)
{
    Stu *p, *q, *l;

    //用类似单链表的头插法来实现这个过程
    if (a->Next->Next == a) return true;
    else if (a->Next == a) return false;

    p = a->Next;
    q = a->Next->Next;
    l = a->Prior;

    p->Next = a;
    p->Prior = a;
    p = q;
    q = q->Next;

    while (a->Next != l){
        p->Prior = a;
        p->Next = a->Next;
        a->Next = p;
        p = q;
        q = q->Next;
    }

    return true;

}

bool IsRight(Stu *a)
{
    Stu *first, *last;
    first = a->Next;
    last = a->Prior;

    if (last->Prior == first)//只有首元结点
    {
        return true;
    }

    while (first != last){
        //前后同时遍历对比数值

        if (first->date != last->date) return false;
        else{
            first = first->Next;
            last = last->Prior;
        }

    }
    return true;


}


//函数实现A,B两表连接，最后为循环链表A；
void TowTry(Stu *a, Stu *&b)//B的头指针可能要置空
{
    Stu *p = NULL;
    Stu *q = NULL;

    //如若B表为空
    if (b->Next == NULL){
        delete p;//删除头结点
        b = NULL;//将指针置空
        return;
    }
    else{//B表非空

        //A表遍历到最后一个元素
        q = a;
        while (q ->Next != a){
            q = q->Next;
        }
        q ->Next = b->Next;//A的尾巴，连接到了B的首元结点

        //遍历B表到最后一个元素
        p = b;
        while (p->Next != b){
            p = p->Next;
        }

        //把B的尾巴连到A的头上
        p->Next = a;

        //最后释放B的头结点
        delete b;
        b = NULL;

    }

}

//函数实现初始化链表并输入值
void beCome(Stu *&Head)
{
    //头结点安排
    Head = new Stu;
    Head->Next = NULL;
    Head->Prior = NULL;
    Stu *p;
    Stu *q = Head;

    int x;
    cout << "输入数据：，输入9999退出!" << endl;
    cin >> x;
    while (x != 9999)
    {
        p = new Stu;
        p->date = x;
        p->Next = NULL;
        p->Prior = q;
        q->Next = p;
        q = p;
        cin >> x;
    }
    p->Next = Head;
    Head->Prior = p;

}

//遍历链表输出
void pri(Stu *p)
{
    Stu *q = p ->Next;
    while (q != p){
        cout << q->date << " ";
        q = q->Next;
    }
    NEWLINE;

}




