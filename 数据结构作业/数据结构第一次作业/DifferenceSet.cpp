#include <iostream>
#define MaxLenth 100
#define elementType int

using namespace std;

//2.9
struct sList
{

    sList()//��ʼ����ĳ���Ϊ0
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//�����������
    int Lenth;//���峤��
};

void DifSet(sList *a, sList *b);
int main(void)
{
    sList A, B;
    cout << "������A��10������������������ó����ظ�Ԫ�أ�"<< endl;
   for (int i = 0; i < 10; i++){
        cin >> A.date[i];
        A.Lenth++;
    }

    cout << "������B��10������������������ó����ظ�Ԫ�أ�"<< endl;
    for (int i = 0; i < 10; i++){
            cin >> B.date[i];
            B.Lenth++;
    }

    DifSet(&A, &B);

    cout << "A - B�Ľ��Ϊ��" << endl;
    for (int i = 0; i < A.Lenth; i++)
    {
        cout << A.date[i] << " ";
    }

}

//����ʵ�ֵ������򼯺ϵĲ A = A - B
void DifSet(sList *a, sList *b)
{
    int i = 0, j = 0, k = 0;//k��Ϊ�������顱�ĳ��ȿ���
    b->date[10] = -1;

    //�ʣ�A���ϱ��������ȫ
    while (i < a->Lenth)//A��Ԫ�ؽ�С���Ա�����A�ͽ���������A�ϴ�ʱ�������B�������ˣ�A�����Ԫ���޷���ȡ
    {
            if (a->date[i] > b->date[j] && j < b->Lenth - 1)//��A��Ԫ�ش���B��Ԫ��, ��B����û�б�����
            {
                j++;//��B���ϱ�����֮�ͣ���ֹ�����±�Խ�磡
            }
            else if (a->date[i] < b->date[j]|| j == b->Lenth - 1) //��벿������������ڣ�B������Ԫ�ض�С��A��
            {
                a->date[k] = a->date[i];
                i++;
                k++;
            }
            else if (a->date[i] == b->date[j])
            {
                j++;
                i++;
            }
    }

    a->Lenth = k;
}












