#include <iostream>
#define MaxLenth 100
#define elementType int

using namespace std;

//2.8
struct sList
{

    sList()//��ʼ����ĳ���Ϊ0
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//�����������
    int Lenth;//���峤��
};


void AddTwo(sList *a, sList *b);

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

    AddTwo(&A, &B);

    cout << "A��Bȡ������" << endl;
    for (int i = 0; i < A.Lenth; i++)
    {
        cout << A.date[i] << " ";
    }

}

//����ʵ����������������ʾ����A,B����A = A��B;
void AddTwo(sList *a, sList *b)
{
    int i = 0, j = 0, k = 0;//K��Ϊ�������顱�ĳ��ȼ�����λ

    //Ĭ�ϵõ������A����Ȼ�ǵ�����������
    while (j < b->Lenth && i < a->Lenth)//��Ϊ�������顱�ĳ������ǿ��Եó����˴���Ҫ��������˳�ѭ��
    {
        //A, B�б�������Ԫ�ز����ʱ����������Դ�
        if (a->date[i] > b->date[j])
        {
            //��A�и�Ԫ�ش���B�и�Ԫ��ʱ��B�ĺ�������е���A�и�Ԫ�ص�
            j++;
        }
        else if (a->date[i] < b->date[j])
        {
            //��A��Ԫ�أ�С��B��ʱԪ��ʱ��A����������ܳ�����B�ĸ�Ԫ�����
            i++;
        }
         else if (a->date[i] == b->date[j])  //��A, B�г�����ͬԪ��
            {
                a->date[k] = a->date[i];//�������Ϊ�����������䳤
                k++;//���� + 1
                i++;//A�������
                j++;//B�������
            }
    }

    a->Lenth = k;//ȷ��������ĳ���

}








