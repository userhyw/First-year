
#include "BiTree.h"

void init();//输出提示文字函数
void showtime(BiNode* pBT, elementType s[], int i);//二叉链表转为顺序数组
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
                    cout << "创建成功！" << endl;
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
                cout << "叶子结点数为：" << Lea << "个" << endl;
                cout << "一度结点数为：" << One << "个" << endl;
                break;
            }
        case 3:
            {
                elementType x;
                bool flage = false;
                cout << "输入要查找的x的值：" << endl;
                cin >> x;

                T.Fimaly(T.root, x, flage);
                if (!flage) cout << "没有在此树上找到该值" << endl;
                break;
            }
        case 4:
            {
                elementType x;
                bool flage = false;
                int high = 1;
                cout << "输入要查找的x的值：" << endl;
                cin >> x;

                T.High(T.root, x, high, flage);
                if (!flage) cout << "没有在此树上找到该值" << endl;
                break;
            }
        case 5:
            {
                elementType s[200];
                int i = 1;
                memset(s, '#', 100);
                showtime(T.root, s, i);//转为顺序结构

                cout << "顺序存储如下：" << endl;
                for (int j = 1; s[j] != '#'; j++)
                {
                    cout << s[j] << " ";
                }
                NEWLINE;
                T.DestroyBiTree(T.root);

                cout << "转换结果为：" << endl;
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
                cout << "删除完毕！" << endl;
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
    cout << "输入 1008611 退出！" << endl;
    cout << "0.输入文件地址创建二叉树！" << endl;
    cout << "1.中序次序输出二叉树中各结点的值及其所对应的层次数" << endl;
    cout << "2.求二叉树的叶子结点数和1度结点数" << endl;
    cout << "3.键盘输入一个元素x，求其父节点、兄弟结点、子结点的值" << endl;
    cout << "4.键盘输入一个元素x，求其在树中的层次" << endl;
    cout << "5.将按顺序方式存储在数组中的二叉树转换为二叉链表形式" << endl;
    cout << "6.输出二叉树从每个叶子结点到根结点的路径" << endl;
    cout << "7.对二叉链表表示的二叉树，按从上到下，从左到右打印结点值，即按层次遍历序打印" << endl;
    cout << "10.销毁当前二叉树" << endl;
}


//二叉链表转为顺序数组
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






