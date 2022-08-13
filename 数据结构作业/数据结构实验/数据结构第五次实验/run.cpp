#include "treeChildSibling.h"
void init(void);//初始化介绍文字函数
void init_one(void);//第一小题文字介绍
int main(void)
{
    pTree T1;//双亲表示法
    csNode *T2;//孩子链表表示法

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
                char filename[258];//文件名读取
                cout << "请输入要创建树的文件名：" << endl;
                cin >> filename;

                int flage = CreateTreeFromFile(filename, T1);
                createCsTree(T2, T1);
                if (flage) cout << "双亲表示法森林-----创建成功-----T1！" << endl;
                if (flage) cout << "孩子兄弟表示法森林-----创建成功-----T2！" << endl;
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
                            cout << "先序遍历结果如下：" << endl;
                            preTraverse(T1);
                            break;
                        }
                    case 2:
                        {
                            cout << "后序遍历结果如下：" << endl;
                            postTraverse(T1);
                            break;
                        }
                    case 3:
                        {
                            cout << "层次遍历结果如下：" << endl;
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
                cout << "该森林的高度为：" << endl;
                int high = 0;
                high = HowHigh(T2);
                cout << "high：" << high << endl;
                break;
            }
        case 3:
            {
                cout << "该森林结点数目如下：" << endl;
                int Leaves = 0;
                HowManyLeaves(T2, Leaves);
                cout << "Leaves：" << Leaves << endl;
                break;
            }
        case 4:
            {
                int c = 0;
                ManyBother(T2, c);
                cout << "该森林的度为：" << endl;
                cout << "结果为：" << c << endl;

                break;
            }
        case 5:
            {
                cout << "结果如下：" << endl;
                int Long = 1;
                FirstPut(T2, Long);

                break;
            }
        case 6:
            {
                cout << "广义表输出如下：" << endl;
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
                cout << "该森林已经删除！----数组" << endl;
                cout << "该森林已经删除！-----链" << endl;
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

//初始化介绍文字函数
void init(void)
{
    cout << "0.输入对应文件创建树（森林） " << endl;
    cout << "1.按先序、后序、层次遍历森林 " << endl;
    cout << "2.求森林的高度 " << endl;
    cout << "3.求森林叶子结点数" << endl;
    cout << "4.求森林的度" << endl;
    cout << "5.先序输出结点值及其层次号 " << endl;
    cout << "6.输出广义表表示的树" << endl;
    cout << "7.清空当前森林" << endl;
    cout << "---输入1008611退出---" << endl;
}

//初始化介绍文字函数
void init_one(void)
{
    cout << "1.先序遍历 " << endl;
    cout << "2.后序遍历 " << endl;
    cout << "3.层次遍历" << endl;
    cout << "---输入1008611退出---" << endl;
}
