#include <iostream>
#define NEWLINE cout << endl

#define A 10
#define B 10
#define C  (A + B)
using namespace std;

int Colle_1(int *a1, int n1, int *b1, int n2, int *c1);//���������ӷֺ�


int main(void)
{
    //Ŀ������˳����ʾ���ϣ�Ȼ��ʵ�ֽ�����������Щ���ܡ�
    //������ʵ�֡�

//    int a1[A], b1[B], c1[C];

    //Ϊ�˵��Է��㣬����ֱ���ڳ�����д������
    int a1[A] = {1, 2, 3, 4, 5, 6, 7,  8, 9, 10};
    int b1[B] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int c1[C];

    //���ú���ʵ�ֲ�
    int m_c = Colle_1(a1, A, b1, B, c1);

    for (int i = 0; i < m_c; i++)
    {
        cout << c1[i] <<"\t";
    }
    NEWLINE;


}

//����ʵ�ּ��ϵĲ�, ���ص���c1������ĳ���
int Colle_1(int *a1, int n1, int *b1, int n2, int *c1)
{
    //ʵ�ֲ�����Ԫ�ش浽C������

    bool Flage1 = true;//�ж�Ԫ���Ƿ���ͬ��־
    int k = 0;//��¼c1����ĳ���

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a1[i] == b1[j])
            {
                Flage1 = false;
                break;
            }
        }
        if (Flage1)
        {
            //�ҵ�һ��������ͬԪ�صģ�ֱ�Ӽ��뵽C��
            c1[k] = a1[i];
            k++;
        }
        else
        {
            Flage1 = true;//Ԫ����ͬ����������
        }

    }

    //ѭ��������a1�����к�b��ͬ���Ѿ����뵽��c1��
    //���ڰ�b1������Ԫ�ط���c1��
    for (int j = 0; j < n2; j++){
        c1[k] = b1[j];
        k++;
    }
        return k;

}







