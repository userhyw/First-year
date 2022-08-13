
#include "BiTree.h"

void init();//�����ʾ���ֺ���
void showtime(BiNode* pBT, elementType s[], int i);//��������תΪ˳������
int main(void)
{
//    BiTree T;
//    char filename[100];
//    char strLine[100][3];
//    int Len = 0;
//    T.ReadFileToArray(filename, strLine, Len);
    int select = -1;
    BiTree T;
    while(select != 1008611)
    {
        init();
        cin >> select;
        system("cls");
        switch(select)
        {
        case 0:
            {
                char filename[100];
                char strLine[100][3];
                int Len = 0, row = 0;
                if (T.ReadFileToArray(filename, strLine, Len) && T.CreateBiTreeFromFile(T.root, strLine, Len, row))
                    cout << "�����ɹ���" << endl;
                    break;
            }
        case 1:
            {
                int high = 1;
                T.InOrder(T.root, high);
                break;
            }
        case 2:
            {
                int Lea = 0, One = 0;
                T.LeavesOne(T.root, Lea, One);
                cout << "Ҷ�ӽ����Ϊ��" << Lea << "��" << endl;
                cout << "һ�Ƚ����Ϊ��" << One << "��" << endl;
                break;
            }
        case 3:
            {
                elementType x;
                bool flage = false;
                cout << "����Ҫ���ҵ�x��ֵ��" << endl;
                cin >> x;

                T.Fimaly(T.root, x, flage);
                if (!flage) cout << "û���ڴ������ҵ���ֵ" << endl;
                break;
            }
        case 4:
            {
                elementType x;
                bool flage = false;
                int high = 1;
                cout << "����Ҫ���ҵ�x��ֵ��" << endl;
                cin >> x;

                T.High(T.root, x, high, flage);
                if (!flage) cout << "û���ڴ������ҵ���ֵ" << endl;
                break;
            }
        case 5:
            {
                elementType s[200];
                int i = 1;
                memset(s, '#', 100);
                showtime(T.root, s, i);//תΪ˳��ṹ

                cout << "˳��洢���£�" << endl;
                for (int j = 1; s[j] != '#'; j++)
                {
                    cout << s[j] << " ";
                }
                NEWLINE;
                T.DestroyBiTree(T.root);

                cout << "ת�����Ϊ��" << endl;
                T.Turn(T.root, s, 1);

                break;
            }
        case 6:
            {
                New s[100];
                int Len = 0;
                T.Track(T.root, s, Len);
                break;
            }
        case 7:
            {
                New s[100];
                int Len = 0, head = 0;
                T.LeToRi(T.root, s, head, Len);
                break;
            }
        case 10:
            {
                T.DestroyBiTree(T.root);
                T.root = NULL;
                cout << "ɾ����ϣ�" << endl;
                break;
            }
        default:
            break;
        }
        system("pause");
        system("cls");
    }


    return 0;
}

void init()
{
    cout << "���� 1008611 �˳���" << endl;
    cout << "0.�����ļ���ַ������������" << endl;
    cout << "1.�����������������и�����ֵ��������Ӧ�Ĳ����" << endl;
    cout << "2.���������Ҷ�ӽ������1�Ƚ����" << endl;
    cout << "3.��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ" << endl;
    cout << "4.��������һ��Ԫ��x�����������еĲ��" << endl;
    cout << "5.����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ" << endl;
    cout << "6.�����������ÿ��Ҷ�ӽ�㵽������·��" << endl;
    cout << "7.�Զ��������ʾ�Ķ������������ϵ��£������Ҵ�ӡ���ֵ��������α������ӡ" << endl;
    cout << "10.���ٵ�ǰ������" << endl;
}


//��������תΪ˳������
void showtime(BiNode* pBT, elementType s[], int i)
{
    if (pBT)
    {
        s[i] = pBT->data;
        showtime(pBT->lChild, s, 2 * i);
        showtime(pBT->rChild, s, 2 * i + 1);
    }
    else
    {
        s[i] = '^';
    }
}






