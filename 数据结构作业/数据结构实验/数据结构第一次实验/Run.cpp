#include "seqList.h"

void init(void);

int main(void)
{
    SeqList L;
    elementType w = 0;
    int Select = -1;

    while (true){
        init();
        cin >> Select;
        system("cls");

        if (Select == 1008611){
            break;
        }

        switch(Select)
        {
        case 1:
            {
                cout << "����Ԫ��ֵ������10086�˳���" << endl;
                cin >> w;
                while(w != 10086)
                {
                    L.listInsert(w);
                    cin >> w;
                }
                cout << "������ϣ�" << endl;
                break;
            }
        case 2:
            {
                    L.DeleteAll();//--------len = 0
                    cout << "���Ա����" << endl;
                    break;
            }
        case 3:
            {
                int i ;
                cout << "������Ҫ�����λ���Լ������ֵ" <<endl;
                cin >> i;
                cin >> w;
                L.listInsert(i, w);
                cout << "����ɹ�" << endl;
                break;
            }
        case 4:
            {
                cout <<"������Ҫɾ���Ľ������" << endl;
                int i;
                cin >> i;
                L.listDelete(i);
                cout << "ɾ���ɹ���" << endl;
                break;
            }
        case 5:
            {
                cout << "������Ԫ�ص�ֵ" << endl;
                cin >> w;
                L.listInsert(true, w);
                cout << "����ɹ���" << endl;
                break;
            }
        case 6:
            {
                SeqList L1, L2;
                cout << "ԭ������Ϊ��" << endl;
                L.Printf();
                NEWLINE;
                L.Separation(L1, L2);

                cout << "L1: ";
                L1.Printf();
                NEWLINE;

                cout << "L2: ";
                L2.Printf();
                NEWLINE;

                L2.DeleteAll();
                L1.DeleteAll();
                break;
            }
        case 7:
            {
                    SeqList L1, L2;
                    cout << "����������Ԫ�أ� 10086�˳���" << endl;

                    cin >> w;
                    while(w != 10086)
                    {
                        L1.listInsert(w);
                        cin >> w;
                    }
                    NEWLINE;

                    L2.add(L, L1);

                    cout << "L1: ";
                    L.Printf();
                    NEWLINE;

                    cout << "L2: ";
                    L1.Printf();
                    NEWLINE;

                    cout << "�±����£�" << endl;
                    L2.Printf();
                    NEWLINE;

                    L1.DeleteAll();
                    L2.DeleteAll();
                    break;
            }
        case 8:
            {
                int j = L.listDelete(true);
                cout << "ɾ���ɹ���" << "ɾ���Ĵ���Ϊ��" << j << "��" << endl;
                cout << "ɾ�����Ϊ��" << endl;
                L.Printf();
                break;
            }
        case 9:
            {
                L.Printf();
                break;
            }
        default:
            break;
        }
        system("pause");
        system("cls");

    }

    //����Ԫ�ز���
//    cout << "������10��Ԫ��" << endl;
//    for (int i = 0; i < 10; i++){
//        cin >> w;
//        L.listInsert(w);
//    }

//    L.listInsert(10, 1000);
//    L.listDelete(3);
//        L.listInsert(true, 110);

//        SeqList L1, L2;
//        L.Separation(L1, L2);
//        L1.Printf();
//        NEWLINE;

//        SeqList L1, L2, L3;
//        for (int i = 0; i < 10; i++){
//            cin >> w;
//            L1.listInsert(w);
//        }
//        for (int i = 0; i < 10; i++){
//            cin >> w;
//            L2.listInsert(w);
//        }
//
//        L3.add(L1, L2);

//        for (int i = 0; i < 15; i++){
//                        cin >> w;
//            L3.listInsert(w);
//        }
//        L3.listDelete(true);
//       int j = L3.Printf();
//        if (j == -1){
//            cout << "���ǿյģ�";
//        }

        return 0;
}

void init(void)
{
    cout << "********************************************************************" << endl;
    cout << "�����Ӧ���֣�" << endl;
    cout << "����1������Ԫ�أ�" << endl;
    cout << "����2����ոñ�" << endl;
    cout << "����3���ڵ�i�����λ�ò���ֵΪx�Ľ��" << endl;
    cout << "����4��ɾ��˳����е�i��Ԫ�ؽ�㡣" << endl;
    cout << "����5����һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�" << endl;
    cout << "����6����˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳����У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������" << endl;
    cout <<"����7����������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��" << endl;
    cout <<"����8��ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ���������" << endl;
    cout << "����9���鿴����Ԫ��" << endl;
    cout << "����1008611�˳�����" << endl;
    cout << "********************************************************************" << endl;

}
