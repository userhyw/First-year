#include "createTree.h"

//清空该表
void distroy(pTree &T)
{
    T.n=0;
}

//清空该森林链
void distroy_m(csNode *T)
{
    if (T)
    {
        distroy_m(T->firstChild);
        distroy_m(T->nextSibling);
        delete T;
    }
}

//孩子链表表示法求森林高度
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

//求森林的叶子结点数目
void HowManyLeaves(csNode *T2, int &Leaves)
{
    if (T2)
    {
        if (T2->firstChild == NULL) Leaves++;
        HowManyLeaves(T2->firstChild, Leaves);
        HowManyLeaves(T2->nextSibling, Leaves);
    }
}

//求森林的度
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
            p = p->nextSibling;//多一个兄弟就 + 1
        }
        if (n > Max) Max = n;
    }
    ManyBother(T->firstChild, Max);
    ManyBother(T->nextSibling, Max);
}

//先序输出结点值及其层次号
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

//输出广义表表示的树
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
