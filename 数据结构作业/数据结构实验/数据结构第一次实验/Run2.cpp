#include "linkedList.h"

void init(void);

int main(void)
{

    LinkedList L, L2, L3;

    int Select = -1;
    while (true)
    {
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
                        L.createListR();//β�巨���룡
                        cout << "��������ϣ�" << endl;
                        break;
                }
            case 2:
                {
                    L.destroy();
                    cout << "��������գ�" << endl;
                    break;
                }
            case 3:
                {
                    int i;
                    elementType x;
                    cout << "'��������λ�ã��Լ������ֵ" <<endl;
                    cin >>i;
                    cin >> x;

                    L.listInsert(i, x);
                    cout << "������ϣ�" << endl;
                    break;
                }
            case 4:
                {
                    cout << "����Ҫɾ���Ľ�����" <<endl;
                    int i;
                    cin >> i;

                    bool c = L.listDelete(i);
                    if (c)
                    cout << "ɾ����ϣ�" << endl;
                    else
                    cout << "δ�ҵ��Ľ�㣬�޷�ɾ����" << endl;
                    break;
                }
            case 5:
                {
                    elementType x;
                    cout << "������Ҫ�����ֵ��" << endl;
                    cin >> x;

                    L.listInsert(true, x);
                    cout << "������ϣ�" << endl;
                    break;
                }
            case 6:
                {
                    L.apart(L2, L3);

                    cout << "L1: ";
                    L2.print();
                    NEWLINE;

                    cout << "L2: ";
                    L3.print();
                    NEWLINE;

                    L2.destroy();
                    L3.destroy();
                    break;
                }
            case 7:
                {
                    L3.ReLinkedList();//ɾ����ĳ�ʼ����

                    cout << "��������Ԫ��" <<endl;
                    L2.createListR();

                    cout << "L1: ";
                    L.print();
                    NEWLINE;

                    L3.allpart(L, L2);

                    cout << "L3: ";
                    L3.print();
                    NEWLINE;

                    L2.destroy();
                    L3.destroy();
                    break;
                }
            case 8:
                {
                    int j = L.listDeleteSame(true);
                    cout << "ԭ�����ݣ�";
                    L.print();
                    NEWLINE;

                    cout << "ɾ����ϣ��ƶ�����Ϊ��" << j << endl;
                    L.print();
                    break;
                }
            case 9:
                {
                    cout << "������Ԫ�أ�" <<endl;
                    L2.createListR();

                    cout << "ԭ�����ݣ�";
                    L.print();
                    NEWLINE;

                    L.disApart(L2);//�󼯺�

                    cout << "���Ϊ��" << endl;
                    cout << "L: ";
                    L.print();

                    break;
                }
            case 10:
                {
                    cout << "����Ԫ������: " << endl;
                    L.print();
                    break;
                }

        }

        system("pause");
        system("cls");
    }



//    L.destroy();
//    cout << "ԭ���ݣ�" << endl;
//    L.print();//ԭ���ݣ�
//-------------------------11111111111111111111111111-----------------
//    L.listInsert(5, 100);
//    L.listInsert(10, 100);
//   L.listInsert(10, 100);
//    L.listInsert(0, 100);
//    L.listInsert(5, 100);
//    NEWLINE;
//    cout << "�����" << endl;
//    L.print();


//-------------------------2222222222222222222222222-----------------
//    L.listDelete(10);
//    L.listDelete(1);
//    L.listDelete(0);
//    NEWLINE;
//    cout << "ɾ����" << endl;
//    L.print();


//-------------------------333333333333333333333333-----------------

//    L.listInsert(true, 110);
//    NEWLINE;
//    cout << "�����" << endl;
//    L.print();



//-------------------------444444444444444444444444-----------------
//        NEWLINE;
//        LinkedList L1, L2;
//        L.apart(L1, L2);
//        cout << "L1: ";
//        L1.print();
//        NEWLINE;
//        cout << "L2: ";
//        L2.print();


//-------------------------55555555555555555555555555---------------------
//    L2.createListR();
//    L3.allpart(L, L2);
//    NEWLINE;
//    cout << "����Ԫ��Ϊ��" ;
//    L3.print();

//-------------------------66666666666666666666666666---------------------
//    L.listDeleteSame(true);
//    NEWLINE;
//    L.print();

//-------------------------777777777777777777777777777---------------------
//    L2.createListR();
//
//    NEWLINE;
//    L.disApart(L2);
//    cout << "L2:";
//    L2.print();
//
//    NEWLINE;
//    cout << "L1:";
//    L.print();

    return 0;
}

void init(void)
{
    cout << "********************************************************************" << endl;
    cout << "�����Ӧ���֣�" << endl;
    cout << "����1������Ԫ�أ�" << endl;
    cout << "����2����ոñ�" << endl;
    cout << "����3���ڵ�i�����λ�ò���ֵΪx�Ľ��" << endl;
    cout << "����4��ɾ�������е�i��Ԫ�ؽ�㡣" << endl;
    cout << "����5����һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�" << endl;
    cout << "����6������������е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳����У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������" << endl;
    cout <<"����7��������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3��" << endl;
    cout <<"����8��ɾ���������������е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ���������" << endl;
    cout << "����9��������������L1��L2���������½�㣬����ԭ�����������кϲ�����ʹ�úϲ����Ϊһ�����ϣ��ϲ�����L1��ͷ�����Ϊͷ��㣬ɾ������Ľ�㣬ɾ��L2��ͷ��㡣Ҫ��ʱ���������" << endl;
    cout << "����10���鿴����Ԫ��" << endl;
    cout << "����1008611�˳�����" << endl;
    cout << "********************************************************************" << endl;

}










