#include "twoand.h"
#include <queue>
#include <cstring>
#define NEWLINE cout << endl
//DFS遍历算法实现------------深度优先搜索
void DFS(GraphLink &G, int v)//从编号为v的顶点开始遍历
{
    int w;
    visitLink(G, v);//访问当前点，且标记
    w = firstAdjLink(G, v);//

    while(w != 0)
    {
        if (visited[w] == false) DFS(G, w);
        w = nextAdjLink(G, v, w);//找v在w后的下一个邻接点
    }
}

//BFS遍历算法实现-------------广度优先搜索
void BFS(GraphLink &G, char s[])//从编号为v的顶点开始遍历
{
    int w, v;
    while (*s)
    {
        v = LocateVertexLink(G, *s);
        queue<int> q;
        visitLink(G, v);
        q.push(v);

        while(!q.empty())//队列不空取队头
        {
            v = q.front();
            q.pop();
            w = firstAdjLink(G, v);
        while(w != 0)
            {
                if (visited[w] == false)
                {
                    visitLink(G, w);
                    q.push(w);
                }
                w = nextAdjLink(G, v, w);
            }
        }
        s++;
    }
}

//根据给出的节点序号开始遍历这一张图，生成树
void DFSTree(GraphLink &G, int v, csNode *&p)
{
    visited[v] = true;//标记访问过的节点
    p = new csNode;
    p->data = G.VerList[v].data;
    p->firstChild = NULL;
    p->nextSibling = NULL;

    csNode *q, *r;
    bool flage = true;
    int w = firstAdjLink(G, v);
    while(w != 0)
    {
        if (visited[w] == false)
        {
            if (flage)//第一个是第一个孩子
            {
                DFSTree(G, w, p->firstChild);
                r = p->firstChild;
                flage = false;
            }
            else//其他的是孩子兄弟
            {
                DFSTree(G, w, q->nextSibling);
                r = q->nextSibling;
            }
            q = r;//到兄弟的时候要换q的指向到下一个兄弟
        }
        w = nextAdjLink(G, v, w);
    }
}

//找森林的根节点----建立森林
void FindCreat(GraphLink G, csNode *&Head, char s[])
{
    bool flage = true;
    csNode *r;
    while(*s)
    {
        int v = LocateVertexLink(G, *s);
        if (flage)
        {
            DFSTree(G, v, Head);
            r = Head;
            flage = false;
        }
        else
        {
            DFSTree(G, v, r->nextSibling);
            r = r->nextSibling;
        }
        s++;
    }
}

//BFS生成树
void BFSTree(GraphLink &G, char s, csNode *&T)
{
    int v, w;
    bool flage = true, HY = true;
    csNode *r, *p, *t;

     v = LocateVertexLink(G, s);
     queue<csNode*> q;

        T = new csNode;
        T->data = G.VerList[v].data;
        T->firstChild = NULL;
        T->nextSibling = NULL;
        visited[v] = true;
        q.push(T);

        while(!q.empty())
      {
            r = q.front();
            q.pop();

            v = LocateVertexLink(G, r->data);
            w =firstAdjLink(G, v);

            visited[v] = true;
            HY = true;

            while(w != 0)
            {
                if (visited[w] == false)
                {
                    t = new csNode;
                    t->data = G.VerList[w].data;
                    t->firstChild = NULL;
                    t->nextSibling = NULL;

                    visited[w] = true;
                    q.push(t);

                    if (HY)
                    {
                        r->firstChild = t;
                        HY = false;
                    }
                    else
                    {
                        r->nextSibling = t;
                    }
                    r = t;
                }
                w = nextAdjLink(G, v, w);
            }

      }
}

//BFS生成森林
void BFSForest(GraphLink &G, char s[], csNode *&T)
{
    bool flage = true;
    csNode *p , *q;
    while(*s)
    {
        int v = LocateVertexLink(G, *s);
        visited[v] = true;
        if (flage)
        {
            BFSTree(G, *s, T);
            q = T;//此处赋值狠重要，在前是无效的
            flage = false;
        }
        else
        {
            BFSTree(G, *s, q->nextSibling);
            q = q->nextSibling;
        }
        s++;
    }
}

//先序遍历森林打印节点值
void FirstTravel(csNode *T)
{
    if (T)
        {
            cout << T->data << '\t' ;
            FirstTravel(T->firstChild);
            FirstTravel(T->nextSibling);
        }

}

//后序遍历森林打印节点值
void LastTravel(csNode *T)
{
    if (T)
        {
            LastTravel(T->firstChild);
            cout << T->data << '\t' ;
            LastTravel(T->nextSibling);
        }

}


int findchild(GraphLink& G,int i,int j)
{
    vNode t = G.VerList[i];
    EdgeNode *edge = t.firstEdge;
    while(edge != NULL)
    {
        if(edge->adjVer == j)
        {
            return edge->eInfo;
        }
        edge = edge->next;

    }
    return INF;
}
//普莱姆算法
void Prime(GraphLink& G)
{
    int least = 1;//测试从第一个节点开始，后续可修改
    int temp;
    int power[100];
    int parent[100];
    int i;
    for (i = 1; i <= G.VerNum; i++)
    {
        power[i] = INF;
        visited[i] = false;
    }
    for (i = 1; i <= G.VerNum; i++)
    {
        parent[i] = INF;
    }
    i = 1;
    //int least = LocateVertex(G,vertex);
    power[least] = 0;
    parent[least] = 0;
    // for (int w = firstAdj(G,least); w != 0;w = nextAdj(G,least,w))
    //     {
    //         if(power[w] > G.AdjMatrix[least][w])
    //         {
    //             power[w] = G.AdjMatrix[least][w];
    //             parent[w] = least;
    //         }
    //     }
    visitLink(G,least);
    cout<<"first:"<<least<<"-------"<<endl;
    while (i < G.VerNum)
    {

        for (int w = firstAdjLink(G,least); w != 0;w = nextAdjLink(G,least,w))
        {
            if(power[w] > findchild(G,least,w)&&!visited[w])
            {
                power[w] =  findchild(G,least,w);
                parent[w] = least;
            }
        }
        for (int  n = 1; n <= G.VerNum; n++)//找到未访问点到已知点的最小值
        {
            if(!visited[n])
            {
                least = n;
                if(power[least] > power[n])
                {
                    least = n;
                }
            }
        }
        visitLink(G,least);
        cout<<parent[least]<<"-->"<<least<<"  power is : "<<power[least]<<endl;
        i++;
    }
}

//Kruskal算法
void Krusal(GraphLink &G)
{
    bool visitEdge[100];
    for (int i = 1;i <= G.VerNum; i++)
    {
        visitEdge[i] = false;
        visited[i] = false;
    }

    int l,r;
    int m,n;
    int edge;
    int least = INF;//最小边
    for ( edge = 0; edge < G.VerNum-1; edge++)//找到n-1条边结束
    {
        least = INF;
        for ( r = 1; r <= G.VerNum;r++)
        {
            for(l = 1; l <= G.VerNum;l++)
            {
                if(findchild(G,r,l)!=0)
                {
                    if(!(visited[r]&&visited[l]))
                    {
                        if(least > findchild(G,r,l))
                        {
                            //cout<<r<<"++++"<<l<<endl;
                            least = findchild(G,r,l);
                            m = r;
                            n = l;
                        }
                    }
                }
            }
        }
        visitLink(G,m);
        visitLink(G,n);
        cout<<m<<"-->"<<n<<"   power is :"<<findchild(G,m,n)<<endl;

    }

}

//dijkstra
void Dijkstra(GraphLink G,elementType vertex)
{
    //int loc = LocateVertex(G,vertex);
    int loc = 1;
    int i,j;
    int dist[100];
    int parent[100];
    int min = INF;
    int m;
    queue <int> q;
    for (i = 1; i <= G.VerNum; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    for (i = 1; i <= G.VerNum; i++)
    {
        parent[i] = -1;
    }
    dist[loc] = 0;
    q.push(loc);
    visitLink(G,loc);
    while (!q.empty())
    {
        min = INF;
        int temp = q.front();
        q.pop();
        for (int w = firstAdjLink(G,temp); w != 0;w = nextAdjLink(G,temp,w))
        {
            if(!visited[w])
            {
                if(dist[w] > dist[temp] + findchild(G,temp,w))
                {
                    dist[w] = dist[temp] + findchild(G,temp,w);
                    parent[w] = temp;
                    if(min > dist[w])
                    {
                        min = dist[w];
                        m = w;
                    }
                }
            }
        }
        if(!visited[m])
        {
            q.push(m);
            visitLink(G,m);
        }
    }

    for(i = 1;i <= G.VerNum;i++)
    {
        j = i;
        int son = j;
        // while (parent[j] != -1)
        // {
        //     cout<<parent[j]<<"--->"<<j<<"\t";
        //     j = parent[j];

        // }
        while (son != loc&&son != -1)
        {
            cout<<son<<"<--"<<parent[son]<<"\t";
            son = parent[son];
        }
        cout<<"result:"<<endl;
        cout<<loc<<"-->"<<i<<"="<<dist[i]<<endl;
    }


}

//Floyd算法
void Floyd(GraphLink& G,elementType vertex)
{
    // int loc = LocateVertex(G,vertex);
    int loc = 1;
    int Edge[100][100];

    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;

    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            Edge[i][j] = findchild(G,i,j);

            if (i == j)
            {
                Edge[i][j] = 0;
            }

        }
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            for (int k = 1; k <= G.VerNum; k++)
            {
                if((Edge[j][k] > Edge[j][i] + Edge[i][k]))
                {
                    Edge[j][k] = Edge[j][i] + Edge[i][k];

                }
            }
        }

    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {

            cout<<i<<"-->"<<j<<"\t"<<Edge[i][j]<<endl;
        }
    }


}

//____________________________________________________________________________________________________________________
//拓扑序列
void Top(GraphLink& G)
{
    int dgree[100];//度数
    int n = 1;
    int temp;
    for (int i = 1; i <= G.VerNum; i++)
    {
        dgree[i] = 0;
        visited[i] = false;
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            if(findchild(G,j,i) != INF)
            {
                dgree[i]++;
            }
        }
    }
    while (n <= G.VerNum)
    {
        for (int j = 1; j <= G.VerNum; j++)//找到度为0的点
        {
            if(!visited[j]&&dgree[j] == 0)
            {
                temp = j;
            }
        }
        visitLink(G, temp);
        for (int w = firstAdjLink(G, temp); w != 0; w = nextAdjLink(G,temp,w))
        {
            if (!visited[w])
            {
                dgree[w]--;
            }

        }
        n++;
    }

}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//AOE网关键路径
void AOE(GraphLink& G)
{
    int dgree[100];//保存度数
    int dest[100];//保存路径
    int parent[100];//保存父亲结点
    int n = 1;
    int temp;
    int max = 0,m;//标记父节点
    for (int v=1; v<=G.VerNum; v++) {
        visited[v]=false;
    }
    queue <int> q;
    for (int i = 1; i <= G.VerNum; i++)
    {
        dgree[i] = 0;
        dest[i] = 0;
        parent[i] = -1;
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        for (int j = 1; j <= G.VerNum; j++)
        {
            if(findchild(G,j,i) != INF)
            {
                dgree[i]++;
            }
        }
    }
    for (int i = 1; i <= G.VerNum; i++)
    {
        if(dgree[i] == 0)
        {
            q.push(i);
            dest[i] = 0;
            visited[i] = true;
            cout<<"执行"<<G.VerList[i].data<<"\t"<<endl;
        }
    }
    while (!q.empty())
    {
        // int j;
        // int less = INF;
        int temp = q.front();
        q.pop();

        for(int w = firstAdjLink(G,temp);w!=0;w = nextAdjLink(G,temp,w))
        {
            if(!visited[w])
            {
                if(dest[w] < dest[temp] + findchild(G,temp,w)&&findchild(G,temp,w)!=INF)
                {

                    dest[w] = dest[temp] + findchild(G,temp,w);
                    parent[w] = temp;
                }
                if(dgree[w] > 0)
                {
                    dgree[w]--;
                }
                if(dgree[w] == 0)
                {
                    cout<<G.VerList[parent[w]].data<<"结束之后"<<"    执行"<<G.VerList[w].data<<"\t"<<dest[w]<<endl;
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
        // for(int i = 1;i <= G.VerNum;i++)
        // {
        //     if(!visited[i])
        //     {
        //         if(dgree[i] == 0&&dest[i] < less)
        //         {
        //             less = dest[i];
        //             j = i;
        //         }
        //     }
        // }
    }

}

