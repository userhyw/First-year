#include <iostream>
#define MaxLenth 100
#define elementType int

using namespace std;

//2.6
struct sList
{

    sList()//��ʼ����ĳ���Ϊ0
    {
        Lenth = 0;
    }

    elementType date[MaxLenth];//�����������
    int Lenth;//���峤��
};

bool Delete(sList *a);

int main(void)
{

  sList a;

  cout << "������10�������������ظ�Ԫ�ؽ��ᱻɾ��"<< endl;
  for (int i = 0; i < 10; i++){
    cin >> a.date[i];
    a.Lenth++;
  }

  bool Flage = Delete(&a);
  if (!Flage)
  {
      cout << "wrong!" << endl;
  }
  else
  {
      cout << "ɾ���ظ�Ԫ�غ�" << endl;
      for (int i = 0; i < a.Lenth; i++)
      {
          cout << a.date[i] << " ";
      }
  }

}

//����ʵ��ɾ��˳����ظ�Ԫ��
bool Delete(sList *a)
{
    //�ж��Ƿ��ǿձ�,����ֻ��һ��Ԫ��
    if (a->Lenth < 2)
    {
        return false;//�ǿձ���false
    }

//    //������ǿձ�����Ԫ�رȶԣ�ɾ��
//    for (int i = 0; i < a->Lenth - 1; i++)
//    {
//        for (int j = i + 1; j < a->Lenth; j++)
//        {
//            if (a->date[i] == a->date[j])//�����ظ�Ԫ��
//            {
//                for (int k = j; k < a->Lenth - 1; k++)
//                {
//                    a->date[k] = a->date[k + 1];//����Ԫ����ǰ�ƶ�����
//                }
//                a->Lenth--;//���鳤�ȼ�1
//                i--;//ע�⣬һ��ֻɾ����һ���ظ���Ԫ�أ�����ȷ�������Ƿ����ظ�Ԫ�أ�����ÿһ�ζԱȶ�Ҫ������ȫ
//            }
//        }
//    }

    int i = 1, c = 1;//�����õ����൱��������ӵķ���
    bool Flage = true;//��Ϊ���

    //�������Ϊ������ͬ��Ԫ��һ�δ���ӵ�һ��������
    //ÿһ�����֮ǰ��Ҫ����ӵ�Ԫ�رȽ�
    //��֮ǰ��Ԫ�ؾ����ظ���������ӵ�����
    while (i < a->Lenth)//����ѭ������֤ÿһ�ζ���һ��Ԫ�غ�����Ԫ�صĶԱ�
    {
        for(int j = 0; j < c; j++)//�ڲ�ѭ�����������Ϊ�𽥽�Ԫ����ӵ�һ���µ�������
        {
            if (a->date[i] == a->date[j])//�ж��������ѭ�������Ԫ���Ƿ�������������顱��
            {
                Flage = false;//��Ǻ��·��ж�
            }
        }

        if (Flage)//����Ԫ�ز��ڴˡ������顱��
        {
            a->date[c] = a->date[i];//����ӵ�������
            c++;//�����Ӹá������顱����
        }
        else
        {
            Flage = true;//�����ظ������������ѭ��
        }

        i++;
    }

    a->Lenth = c;//ת��˼ά�����ǰ����鼯��ǰ�ƺ��ٸı�����ĳ���
    //���԰Ѳ�Ҫ�������ǣ���������øı��±�ķ�ʽ��ɾ����

    return true;

}






