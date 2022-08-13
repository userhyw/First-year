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
                cout << "输入元素值，输入10086退出！" << endl;
                cin >> w;
                while(w != 10086)
                {
                    L.listInsert(w);
                    cin >> w;
                }
                cout << "输入完毕！" << endl;
                break;
            }
        case 2:
            {
                    L.DeleteAll();//--------len = 0
                    cout << "表以被清空" << endl;
                    break;
            }
        case 3:
            {
                int i ;
                cout << "输入您要插入的位置以及插入的值" <<endl;
                cin >> i;
                cin >> w;
                L.listInsert(i, w);
                cout << "插入成功" << endl;
                break;
            }
        case 4:
            {
                cout <<"请输入要删除的结点的序号" << endl;
                int i;
                cin >> i;
                L.listDelete(i);
                cout << "删除成功！" << endl;
                break;
            }
        case 5:
            {
                cout << "请输入元素的值" << endl;
                cin >> w;
                L.listInsert(true, w);
                cout << "插入成功！" << endl;
                break;
            }
        case 6:
            {
                SeqList L1, L2;
                cout << "原表数据为：" << endl;
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
                    cout << "先输入表二的元素， 10086退出！" << endl;

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

                    cout << "新表如下：" << endl;
                    L2.Printf();
                    NEWLINE;

                    L1.DeleteAll();
                    L2.DeleteAll();
                    break;
            }
        case 8:
            {
                int j = L.listDelete(true);
                cout << "删除成功！" << "删除的次数为：" << j << "次" << endl;
                cout << "删除后表为：" << endl;
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

    //输入元素测试
//    cout << "请输入10个元素" << endl;
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
//            cout << "表是空的！";
//        }

        return 0;
}

void init(void)
{
    cout << "********************************************************************" << endl;
    cout << "输入对应数字：" << endl;
    cout << "输入1，输入元素！" << endl;
    cout << "输入2，清空该表！" << endl;
    cout << "输入3，在第i个结点位置插入值为x的结点" << endl;
    cout << "输入4，删除顺序表中第i个元素结点。" << endl;
    cout << "输入5，在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性。" << endl;
    cout << "输入6，将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。" << endl;
    cout <<"输入7，求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中" << endl;
    cout <<"输入8，删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好" << endl;
    cout << "输入9，查看表中元素" << endl;
    cout << "输入1008611退出程序！" << endl;
    cout << "********************************************************************" << endl;

}
