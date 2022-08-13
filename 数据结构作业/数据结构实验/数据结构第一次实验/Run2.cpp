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
                        L.createListR();//尾插法输入！
                        cout << "输入已完毕！" << endl;
                        break;
                }
            case 2:
                {
                    L.destroy();
                    cout << "链表已清空！" << endl;
                    break;
                }
            case 3:
                {
                    int i;
                    elementType x;
                    cout << "'输入插入的位置，以及插入的值" <<endl;
                    cin >>i;
                    cin >> x;

                    L.listInsert(i, x);
                    cout << "插入完毕！" << endl;
                    break;
                }
            case 4:
                {
                    cout << "输入要删除的结点序号" <<endl;
                    int i;
                    cin >> i;

                    bool c = L.listDelete(i);
                    if (c)
                    cout << "删除完毕！" << endl;
                    else
                    cout << "未找到改结点，无法删除！" << endl;
                    break;
                }
            case 5:
                {
                    elementType x;
                    cout << "输入您要插入的值：" << endl;
                    cin >> x;

                    L.listInsert(true, x);
                    cout << "插入完毕！" << endl;
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
                    L3.ReLinkedList();//删除后的初始化！

                    cout << "输入表二的元素" <<endl;
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
                    cout << "原表数据：";
                    L.print();
                    NEWLINE;

                    cout << "删除完毕！移动次数为：" << j << endl;
                    L.print();
                    break;
                }
            case 9:
                {
                    cout << "输入表二元素：" <<endl;
                    L2.createListR();

                    cout << "原表数据：";
                    L.print();
                    NEWLINE;

                    L.disApart(L2);//求集合

                    cout << "结果为：" << endl;
                    cout << "L: ";
                    L.print();

                    break;
                }
            case 10:
                {
                    cout << "表中元素如下: " << endl;
                    L.print();
                    break;
                }

        }

        system("pause");
        system("cls");
    }



//    L.destroy();
//    cout << "原数据：" << endl;
//    L.print();//原数据！
//-------------------------11111111111111111111111111-----------------
//    L.listInsert(5, 100);
//    L.listInsert(10, 100);
//   L.listInsert(10, 100);
//    L.listInsert(0, 100);
//    L.listInsert(5, 100);
//    NEWLINE;
//    cout << "插入后：" << endl;
//    L.print();


//-------------------------2222222222222222222222222-----------------
//    L.listDelete(10);
//    L.listDelete(1);
//    L.listDelete(0);
//    NEWLINE;
//    cout << "删除后：" << endl;
//    L.print();


//-------------------------333333333333333333333333-----------------

//    L.listInsert(true, 110);
//    NEWLINE;
//    cout << "插入后：" << endl;
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
//    cout << "公共元素为：" ;
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
    cout << "输入对应数字：" << endl;
    cout << "输入1，输入元素！" << endl;
    cout << "输入2，清空该表！" << endl;
    cout << "输入3，在第i个结点位置插入值为x的结点" << endl;
    cout << "输入4，删除链表中第i个元素结点。" << endl;
    cout << "输入5，在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性。" << endl;
    cout << "输入6，将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。" << endl;
    cout <<"输入7，求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中" << endl;
    cout <<"输入8，删除递增有序单链表中的重复元素，并统计移动元素次数，要求时间性能最好" << endl;
    cout << "输入9，递增有序单链表L1、L2，不申请新结点，利用原表结点对两表进行合并，并使得合并后成为一个集合，合并后用L1的头结点作为头结点，删除多余的结点，删除L2的头结点。要求时间性能最好" << endl;
    cout << "输入10，查看表中元素" << endl;
    cout << "输入1008611退出程序！" << endl;
    cout << "********************************************************************" << endl;

}










