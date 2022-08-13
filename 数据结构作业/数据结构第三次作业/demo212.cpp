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

//����ʵ������ͷ���˫ѭ������
bool TurnList(Stu *a)
{
    Stu *p, *q, *l;

    //�����Ƶ������ͷ�巨��ʵ���������
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

    if (last->Prior == first)//ֻ����Ԫ���
    {
        return true;
    }

    while (first != last){
        //ǰ��ͬʱ�����Ա���ֵ

        if (first->date != last->date) return false;
        else{
            first = first->Next;
            last = last->Prior;
        }

    }
    return true;


}


//����ʵ��A,B�������ӣ����Ϊѭ������A��
void TowTry(Stu *a, Stu *&b)//B��ͷָ�����Ҫ�ÿ�
{
    Stu *p = NULL;
    Stu *q = NULL;

    //����B��Ϊ��
    if (b->Next == NULL){
        delete p;//ɾ��ͷ���
        b = NULL;//��ָ���ÿ�
        return;
    }
    else{//B��ǿ�

        //A����������һ��Ԫ��
        q = a;
        while (q ->Next != a){
            q = q->Next;
        }
        q ->Next = b->Next;//A��β�ͣ����ӵ���B����Ԫ���

        //����B�����һ��Ԫ��
        p = b;
        while (p->Next != b){
            p = p->Next;
        }

        //��B��β������A��ͷ��
        p->Next = a;

        //����ͷ�B��ͷ���
        delete b;
        b = NULL;

    }

}

//����ʵ�ֳ�ʼ����������ֵ
void beCome(Stu *&Head)
{
    //ͷ��㰲��
    Head = new Stu;
    Head->Next = NULL;
    Head->Prior = NULL;
    Stu *p;
    Stu *q = Head;

    int x;
    cout << "�������ݣ�������9999�˳�!" << endl;
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

//�����������
void pri(Stu *p)
{
    Stu *q = p ->Next;
    while (q != p){
        cout << q->date << " ";
        q = q->Next;
    }
    NEWLINE;

}




