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

    elementType date[MaxLenth];//�����������
    int Lenth;//���峤��
};


void AddList(sList *a, sList *b, sList *c);
void InsterSection(sList *a, sList *b, sList *c);
void DifferenceSet(sList *a, sList *b, sList *c);

int main(void)
{
    sList a, b, c;



    cout << "������10��Ԫ�ص�a��: " <<endl;
    for (int i = 0; i < 10; i++){
        cin >> a.date[i];
        a.Lenth++;
    }

    cout << "������10��Ԫ�ص�b��: " <<endl;
    for (int i = 0; i < 10; i++){
        cin >> b.date[i];
        b.Lenth++;
    }

//    AddList(&a, &b, &c);
//
//    cout << "Ԫ�ز������£�" << endl;
//    for (int i = 0; i < c.Lenth; i++)
//    {
//        cout << c.date[i] << " ";
//    }

//    InsterSection(&a, &b, &c);
//
//        cout << "Ԫ�ؽ������£�" << endl;
//        for (int i = 0; i < c.Lenth; i++)
//    {
//        cout << c.date[i] << " ";
//    }


    DifferenceSet(&a, &b, &c);

        cout << "Ԫ�ؽ������£�" << endl;
        for (int i = 0; i < c.Lenth; i++)
    {
        cout << c.date[i] << " ";
    }

}

//����ʵ���������ϵĲ�
//ʵ�ֲ�����Ԫ�ش浽C������
void AddList(sList *a, sList *b, sList *c)
{
    bool Flage = true;//�ж�Ԫ���Ƿ���ͬ��־
    *c = *b;//�Ȱ�b��Ԫ�ؼӵ�c��

    for (int i = 0; i < a->Lenth; i++)
    {
        for (int j = 0; j < b->Lenth; j++)
        {
            if (a->date[i] == b->date[j])
            {
                Flage = false;//������ͬԪ��ֱ������ѭ��
                break;
            }
        }

        if (Flage)
        {
             //�ҵ�һ��������ͬԪ�صģ�ֱ�Ӽ��뵽C��
            c->date[c->Lenth] = a->date[i];
            c->Lenth++;
        }
        else
        {
            Flage = true;//Ԫ����ͬ����������
        }

    }

}

//����ʵ���������ϵĽ���
void InsterSection(sList *a, sList *b, sList *c)
{

    for (int i = 0; i < a->Lenth; i++)
    {
        for (int j = 0; j < b->Lenth; j++)
        {
            if (a->date[i] == b->date[j])//������ͬԪ�أ�����뵽c������
            {
                c->date[c->Lenth] = a->date[i];
                c->Lenth++;
                break;
            }
        }
    }
}


//����ʵ���������ϵĲ
//Ϊ���� a - b �Ľ��
void DifferenceSet(sList *a, sList *b, sList *c)
{

    bool Flage = true;

        for (int i = 0; i < a->Lenth; i++)
    {

        for (int j = 0; j < b->Lenth; j++)
        {
            if (a->date[i] == b->date[j])//������ͬԪ��
            {
                Flage = false;//���üǺ�
                break;//����ѭ��
            }
        }

        if (Flage)//����ͬԪ
        {
            c->date[c->Lenth] = a->date[i];//���뵽����c��
            c->Lenth++;
        }
        else
        {
            Flage = true;//������ͬԪ��ֱ����������������
        }

    }
}





