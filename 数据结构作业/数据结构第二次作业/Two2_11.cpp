#include <iostream>
#define ElementType int

using namespace std;

//�����ṹ��
 typedef struct Students
{
    ElementType date;
    Students *Next;

}Stu;

void Delete(Stu *p, int m_x);

int main(void)
{


}

//����ʵ�ִ���ֵ��ɾ�������ж�Ӧ���
void Delete(Stu *p, int m_x)
{
    Stu *q = NULL;//����һ����ʱָ�룬���ڼ�¼ɾ�����
    //Ĭ����ͷ���
    if (p->Next == NULL)
    {
        cout << "�㶼û����������Ҫ�ɹ���" << endl;
        return;
    }

    //��Ϊ��������ı�ͷָ��ĵ�ַ�����Կ���ֱ�ӱ���
    while(p->Next != NULL)
    {
        if (p->Next->date == m_x)//���ҵ���Ԫ��ʱ
        {
            q = p->Next;
            p->Next = p->Next->Next;
            delete q;//�ͷŸýڵ㣬ϵͳ����ʹ��Ȩ
            q = NULL;//����ָ�����ڿ�
        }

        p = p->Next;
    }
    return;

}


//����ʵ���������������������ͷ���Ĳ��������Ǳ�ʾ���Ǽ��ϣ�����û����ͬԪ�� A = A U B
void AaddB(Stu *p, Stu *q)
{
        Stu *cur = p;//���ڼ�¼���������ͷ��λ��
        p = p->Next;
        q = q->Next;


        if (p== NULL || q == NULL) return;

        while (p->Next && q->Next)//p->Next�����һ�����
        {
            if (p->date > q->date)//B��Ԫ��С��A��
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

        //ѭ��������
        Stu *now = cur;//��now��ʼһ���Ķ�Ҫɾȥ
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



















