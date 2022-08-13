#include "createTree.h"

//��ոñ�
void distroy(pTree &T)
{
    T.n=0;
}

//��ո�ɭ����
void distroy_m(csNode *T)
{
    if (T)
    {
        distroy_m(T->firstChild);
        distroy_m(T->nextSibling);
        delete T;
    }
}

//���������ʾ����ɭ�ָ߶�
int  HowHigh(csNode *T2)
{
    if (!T2) return 0;
    else
    {
        int a = 0, b = 0;
        a = HowHigh(T2->firstChild) + 1;
        b = HowHigh(T2->nextSibling);
        if (a >b) return a;
        return b;
    }
}

//��ɭ�ֵ�Ҷ�ӽ����Ŀ
void HowManyLeaves(csNode *T2, int &Leaves)
{
    if (T2)
    {
        if (T2->firstChild == NULL) Leaves++;
        HowManyLeaves(T2->firstChild, Leaves);
        HowManyLeaves(T2->nextSibling, Leaves);
    }
}

//��ɭ�ֵĶ�
void ManyBother(csNode *T, int &Max)
{
    if (!T) return;
    if (T->firstChild)
    {
        csNode *p = T->firstChild;
        int n = 1;
        while(p->nextSibling)
        {
            n++;
            p = p->nextSibling;//��һ���ֵܾ� + 1
        }
        if (n > Max) Max = n;
    }
    ManyBother(T->firstChild, Max);
    ManyBother(T->nextSibling, Max);
}

//����������ֵ�����κ�
void FirstPut(csNode *T, int Long)
{
  if (T)
  {
      cout << "(" << T->data << "," << Long << ")" << endl;
      int c = Long + 1;
      FirstPut(T->firstChild, c);
      FirstPut(T->nextSibling, Long);
  }
}

//���������ʾ����
void PrintfL(csNode *T)
{
    if (T)
    {
        bool flage = false;
        cout << T->data;
        if (T->firstChild)
        {
            cout <<"(";
            flage = true;
        }
        PrintfL(T->firstChild);
        if (flage) cout << ")";
        if (T->nextSibling) cout << ",";
        PrintfL(T->nextSibling);
    }
}
