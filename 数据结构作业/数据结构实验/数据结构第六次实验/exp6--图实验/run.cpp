#include "Link.h"
void init();//基本信息介绍
int main(void)
{
        GraphLink GLink;
         int select = -1;
         while(select != 1008611)
         {
                init();
                cin >> select;
                memset(visited, 0, sizeof(visited));//visited数组重复使用会出错
                system("cls");
                switch(select)
                {
                case 0:
                    {
                        char s[100];
                        cout << "请输入文件的地址：" << endl;
                        cin >> s;
                        bool f  = CreateGraphFromFileLink(s, GLink);
                        f ? cout << "创建成功！" << endl : cout << "创建出现错误！" << endl;

                        break;
                    }
                case 1:
                    {
                        char v_m[100];
                        cout << "输入开始的点的值：";
                        cin >> v_m;
                        char *p = v_m;
                        cout << "DFS: " << endl;
                        while(*p)
                        {
                            int c = LocateVertexLink(GLink, *p);
                            DFS(GLink, c);
                            p++;
                        }

                        NEWLINE;
                        memset(visited, 0, sizeof(visited));//visited数组重复使用会出错
                        cout << "BFS: " << endl;
                        BFS(GLink, v_m);

                        break;
                    }
                case 2:
                    {
                        cout << "此图边的数目为：";
                        cout << GLink.ArcNum << endl;
                        break;
                    }
                case 3:
                    {
                        char s_a[100];
                        cout << "请输入开始的节点值：";
                        cin >> s_a;
                        csNode *Head = NULL;
                        FindCreat(GLink, Head, s_a);

                        cout << "先序遍历森林如下：" << endl;
                        FirstTravel(Head);

                        NEWLINE;
                        cout << "后序遍历森林如下：" << endl;
                        LastTravel(Head);

                        break;
                    }
                case 4:
                    {
                        char m_p[100];
                        csNode *Head;
                        cout << "输入开始的节点的值: ";
                        cin >> m_p;

                        BFSForest(GLink, m_p, Head);

                        cout << "先序遍历森林如下：" << endl;
                        FirstTravel(Head);

                        NEWLINE;
                        cout << "后序遍历森林如下：" << endl;
                        LastTravel(Head);


                        break;
                    }
                case 5:
                    {
                        cout << "Prime: " << endl;
                        Prime(GLink);
                        break;
                    }
                case 6:
                    {
                        cout << "Krusal: " << endl;
                        Krusal(GLink);
                        break;
                    }
                case 7:
                    {
                        cout << "Dijkstra: " << endl;
                        char c;
                        cin >> c;
                        Dijkstra(GLink,c);
                        break;
                    }
                case 8:
                    {
                        cout << "Floyd :" << endl;
                        char c;
                        cin >> c;
                        Floyd(GLink, c);
                        break;
                    }
                case 9:
                    {
                        cout << "Top: " << endl;
                        Top(GLink);
                        break;
                    }
                case 10:
                    {
                        cout << "AOE: " << endl;
                        AOE(GLink);
                        break;
                    }
                case 77:
                    {
                        DestroyGraphLink(GLink);
                        cout << "删除完毕！" << endl;
                        break;
                    }
                default :
                    break;
                }
                system("pause");
                system("cls");
         }
    return 0;
}

//基本信息介绍
void init()
{
    cout << "0.输入对于文件地址，创建图" << endl;
    cout << "1.打印出图（网）的两种遍历序" << endl;
    cout << "2.求给定图中的边（或弧）的数目" << endl;
    cout << "3.对给定的图G及出发点v0，设计算法从V0出发深度优先遍历图G，并构造出相应的生成树或生成森林" << endl;
    cout << "4.对给定的图G及出发点v0，设计算法从V0出发广度优先遍历图G，并构造出相应的生成树或生成森林" << endl;
    cout << "5.实现Prim算法，求解下列给定图G的最小生成树" << endl;
    cout << "6.实现Kruskal算法，求解下列给定图G的最小生成树" << endl;
    cout << "7.实现Dijkstra算法，求解下列给定图G指定顶点到其余顶点之间的最短路径" << endl;
    cout << "8.实现Floyd算法，求解下列给定图G各顶点之间的最短路径" << endl;
    cout << "9.设计算法求解下列给定图G的拓扑序列" << endl;
    cout << "10.设计算法求解下列给定AOE网的关键路径" << endl;
    cout << "77.删除当前图" << endl;
    cout << "输入------1008611-----退出" << endl;
}





