#include "treeChildSibling.h"
void init(void);//��ʼ���������ֺ���
void init_one(void);//��һС�����ֽ���
int main(void)
{
    pTree T1;//˫�ױ�ʾ��
    csNode *T2;//���������ʾ��

    int select = -1;
    while(select != 1008611)
    {
        init();
        cin >> select;
        system("cls");
        switch(select)
        {
        case 0:
            {
                char filename[258];//�ļ�����ȡ
                cout << "������Ҫ���������ļ�����" << endl;
                cin >> filename;

                int flage = CreateTreeFromFile(filename, T1);
                createCsTree(T2, T1);
                if (flage) cout << "˫�ױ�ʾ��ɭ��-----�����ɹ�-----T1��" << endl;
                if (flage) cout << "�����ֵܱ�ʾ��ɭ��-----�����ɹ�-----T2��" << endl;
                break;
            }
        case 1:
            {
                int select_one = -1;
                init_one();
                while (select_one != 1008611)
                {
                    cin >> select_one;
                    int ifind[20];
                    int Len = 0;
                    switch(select_one)
                    {
                    case 1:
                        {
                            cout << "�������������£�" << endl;
                            preTraverse(T1);
                            break;
                        }
                    case 2:
                        {
                            cout << "�������������£�" << endl;
                            postTraverse(T1);
                            break;
                        }
                    case 3:
                        {
                            cout << "��α���������£�" << endl;
                            for(int i=0;i<T1.n;i++)
                            {
                                cout << T1.node[i].data << " ";
                                if (T1.node[i + 1].parent == -1) cout << endl;
                            }
                            break;
                        }
                    default:
                        break;
                    }
                }

                break;
            }
        case 2:
            {
                cout << "��ɭ�ֵĸ߶�Ϊ��" << endl;
                int high = 0;
                high = HowHigh(T2);
                cout << "high��" << high << endl;
                break;
            }
        case 3:
            {
                cout << "��ɭ�ֽ����Ŀ���£�" << endl;
                int Leaves = 0;
                HowManyLeaves(T2, Leaves);
                cout << "Leaves��" << Leaves << endl;
                break;
            }
        case 4:
            {
                int c = 0;
                ManyBother(T2, c);
                cout << "��ɭ�ֵĶ�Ϊ��" << endl;
                cout << "���Ϊ��" << c << endl;

                break;
            }
        case 5:
            {
                cout << "������£�" << endl;
                int Long = 1;
                FirstPut(T2, Long);

                break;
            }
        case 6:
            {
                cout << "�����������£�" << endl;
                cout << "(";
                PrintfL(T2);
                cout << ")";
                break;
            }
        case 7:
            {
                distroy(T1);
                distroy_m(T2);
                T2 = NULL;
                cout << "��ɭ���Ѿ�ɾ����----����" << endl;
                cout << "��ɭ���Ѿ�ɾ����-----��" << endl;
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

//��ʼ���������ֺ���
void init(void)
{
    cout << "0.�����Ӧ�ļ���������ɭ�֣� " << endl;
    cout << "1.�����򡢺��򡢲�α���ɭ�� " << endl;
    cout << "2.��ɭ�ֵĸ߶� " << endl;
    cout << "3.��ɭ��Ҷ�ӽ����" << endl;
    cout << "4.��ɭ�ֵĶ�" << endl;
    cout << "5.����������ֵ�����κ� " << endl;
    cout << "6.���������ʾ����" << endl;
    cout << "7.��յ�ǰɭ��" << endl;
    cout << "---����1008611�˳�---" << endl;
}

//��ʼ���������ֺ���
void init_one(void)
{
    cout << "1.������� " << endl;
    cout << "2.������� " << endl;
    cout << "3.��α���" << endl;
    cout << "---����1008611�˳�---" << endl;
}
