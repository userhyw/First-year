#include <iostream>
#define MaxLenth 100
#define elementType int
using namespace std;
//2.7

struct sList
{

    sList()//��ʼ����ĳ���Ϊ0
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//�����������
    int Lenth;//���峤��
};


int Delete(sList *a);

int main(void)
{
    sList a;

    cout << "����������10��Ԫ�أ���ɾ���ظ�Ԫ��" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> a.date[i];
        a.Lenth++;
    }

    int Flage = Delete(&a);
    if (Flage == 1)
    {
        cout << "wrong!" << endl;
    }
    else
    {
        cout << "ɾ����Ľ��Ϊ��" << endl;
        cout << "�ƶ�����Ϊ��" << Flage << endl;
        for (int i = 0; i < a.Lenth; i++)
        {
            cout << a.date[i] << " ";
        }
    }
}

//����ʵ���������б�ɾ���ظ�Ԫ��
int Delete(sList *a)
{
    if (a->Lenth == 0)//�ձ�ͷ��ش���ֹͣ����
    {
        return 1;
    }

    int i = 0, j = 1, c = 0;

    //˼·�������Ϊ�����ظ���Ԫ�طŵ�ǰ�棬Ȼ������鳤�ȸı�
    while (j < a->Lenth)
    {
        if (i == j || a->date[i] == a->date[j])//Ԫ���ظ��������±���ȵ���Ԫ�����
        {
            j++;//�ƶ��±����Ѱ�Ҳ�һ����Ԫ��
        }
        else
        {
            a->date[++i] = a->date[j];//�Ѳ��ظ���Ԫ�طŵ�ǰ�棬ͬʱ�ƶ��±�
            c++;
        }
    }

    a->Lenth = i + 1;

    return c;

}




